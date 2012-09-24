#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextStream>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	connect( ui->btnLoadCompiler, SIGNAL(clicked()), this, SLOT(handleLoadCompiler()) );
	connect( ui->btnLoadConfig, SIGNAL(clicked()), this, SLOT(handleLoadConfig()) );
	connect( ui->btnCompile, SIGNAL(clicked()), this, SLOT(handleCompile()) );
	connect( ui->btnSelectOutput, SIGNAL(clicked()), this, SLOT(handleSelectOutput()) );
	configLoaded = compilerLoaded = outputSelected = processRunning = false;
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *evt) {
	ui->textLog->setGeometry( 10, 10, evt->size().width() - 20, evt->size().height() - 170 );
	ui->layoutWidget->setGeometry( 10, evt->size().height() - 160, evt->size().width() - 20, ui->layoutWidget->geometry().height() );
	ui->btnCompile->setGeometry( evt->size().width() - 130, evt->size().height() - 60, ui->btnCompile->geometry().width(), ui->btnCompile->height() );
}

void MainWindow::handleCompile() {
	if ( configLoaded && compilerLoaded && outputSelected && !processRunning ) {
		log( "Starting Compiler..." );
		log( "" );
		compilerProcess = new QProcess();
		QStringList program( "java -jar " + compilerPath );
		int numInputFiles = jsFilePaths->length();
		int i = 0;
		QString jsTemplate = "--js=";
		while ( i < numInputFiles ) {
			program.push_back( jsTemplate + jsFilePaths->at( i ) );
			i++;
		}
		program.push_back( "--js_output_file=" + outputFilePath );
		log( program.join( " " ) );
		connect( compilerProcess, SIGNAL(finished(int)), this, SLOT( handleProcessFinished(int) ) );
		connect( compilerProcess, SIGNAL( readyReadStandardOutput() ), this, SLOT( handleProcessOutput() ) );
		connect( compilerProcess, SIGNAL( readyReadStandardError() ), this, SLOT( handleProcressError() ) );
		compilerProcess->start( program.join( " " ) );
		processRunning = true;
	} else if ( !configLoaded ) {
		log( "ERROR: Please load your config-file!" );
	} else if ( !compilerLoaded ) {
		log( "ERROR: Please load the closure compiler!" );
	} else if ( !outputSelected ) {
		log( "ERROR: Please select an output-file!" );
	} else if ( processRunning ) {
		log( "ERROR: The Closure Compiler is already running!" );
	}
}

void MainWindow::handleLoadCompiler() {
	compilerDialog = new QFileDialog(this,Qt::Dialog);
	compilerDialog->setFileMode(QFileDialog::ExistingFile);
	compilerDialog->setFilter( "JAR-Archive (*.jar)" );
	connect( compilerDialog, SIGNAL(fileSelected(QString)),this, SLOT(handleCompilerSelected()) );
	compilerDialog->show();
}

void MainWindow::handleLoadConfig() {
	configDialog = new QFileDialog(this,Qt::Dialog);
	configDialog->setFileMode(QFileDialog::ExistingFile);
	connect( configDialog, SIGNAL(fileSelected(QString)),this, SLOT(handleConfigSelected()) );
	configDialog->show();
}

void MainWindow::handleConfigSelected() {
	configPath = configDialog->selectedFiles().first();
	QString path = configDialog->directory().path();
	QFile configFile( configPath );
	if ( configFile.exists() ) {
		configFile.open( QIODevice::ReadOnly );
		QTextStream textStream( &configFile );
		config = textStream.readAll();
		QStringList fileList = config.split( "\n" );
		configFile.close();
		jsFilePaths = new QStringList();
		int numEntries = fileList.length();
		int i = 0;
		while ( i < numEntries ) {
			QFileInfo fileInfo( path + "/" + fileList[ i ] );
			if ( fileInfo.exists() ) {
				jsFilePaths->push_back( fileInfo.absoluteFilePath() );
			}
			i++;
		}
		configLoaded = true;
		log( "Selected config file:" );
		log( configPath );
		log( "Config file contains the following files:" );
		log( jsFilePaths->join( "\n" ) );
		ui->configPath->setText( configPath );
	}
}

void MainWindow::handleCompilerSelected() {
	compilerPath = compilerDialog->selectedFiles().first();
	compilerLoaded = true;
	log( "Selected compiler-path:" );
	log( compilerPath );
	ui->compilerPath->setText( compilerPath );
}

void MainWindow::handleSelectOutput() {
	outputDialog = new QFileDialog( this, Qt::Dialog );
	outputDialog->setFileMode(QFileDialog::AnyFile);
	outputFilePath = outputDialog->getSaveFileName( this, "Select Output File", "", "(JavaScript (*.js)");
	if ( outputFilePath.length() > 0 ) {
		log( "Selected output file path:" );
		log( outputFilePath );
		ui->outputPath->setText( outputFilePath );
		outputSelected = true;
	}
}

void MainWindow::log(QString message) {
	ui->textLog->appendPlainText( message );
}

void MainWindow::handleProcessFinished( int exitCode ) {
	processRunning = false;
	log( "Closure Compiler finished with exitCode " + QString::number( exitCode ) );
}

void MainWindow::handleProcessOutput() {
	log( QString( compilerProcess->readAllStandardOutput() ) );
}

void MainWindow::handleProcressError() {
	log( QString( compilerProcess->readAllStandardError() ) );
}
