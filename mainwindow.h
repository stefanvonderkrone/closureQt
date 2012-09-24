#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QProcess>
#include <QtPlugin>

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
		Q_OBJECT
		
	public:
		explicit MainWindow(QWidget *parent = 0);
		~MainWindow();
		void resizeEvent(QResizeEvent *evt);
		
	private:
		Ui::MainWindow *ui;
		bool configLoaded, compilerLoaded, outputSelected, processRunning;
		QString compilerPath, configPath, config, outputFilePath;
		QStringList *jsFilePaths;
		QFileDialog *configDialog, *compilerDialog, *outputDialog;
		QProcess *compilerProcess;
		void log( QString message );

	public slots:
		void handleLoadCompiler();
		void handleLoadConfig();
		void handleCompile();
		void handleConfigSelected();
		void handleCompilerSelected();
		void handleSelectOutput();
		void handleProcessFinished( int exitCode );
		void handleProcessOutput();
		void handleProcressError();
};

#endif // MAINWINDOW_H
