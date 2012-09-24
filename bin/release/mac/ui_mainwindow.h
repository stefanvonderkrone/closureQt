/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Sep 24 21:36:37 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPlainTextEdit *textLog;
    QPushButton *btnCompile;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *compilerPath;
    QPushButton *btnLoadCompiler;
    QLabel *label_2;
    QLineEdit *configPath;
    QPushButton *btnLoadConfig;
    QLabel *label_3;
    QLineEdit *outputPath;
    QPushButton *btnSelectOutput;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(640, 480);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        textLog = new QPlainTextEdit(centralWidget);
        textLog->setObjectName(QString::fromUtf8("textLog"));
        textLog->setEnabled(true);
        textLog->setGeometry(QRect(10, 10, 620, 310));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textLog->sizePolicy().hasHeightForWidth());
        textLog->setSizePolicy(sizePolicy);
        textLog->setLineWrapMode(QPlainTextEdit::WidgetWidth);
        textLog->setReadOnly(true);
        btnCompile = new QPushButton(centralWidget);
        btnCompile->setObjectName(QString::fromUtf8("btnCompile"));
        btnCompile->setGeometry(QRect(510, 420, 114, 32));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 325, 620, 106));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 2);

        compilerPath = new QLineEdit(layoutWidget);
        compilerPath->setObjectName(QString::fromUtf8("compilerPath"));
        compilerPath->setReadOnly(true);

        gridLayout->addWidget(compilerPath, 0, 2, 1, 1);

        btnLoadCompiler = new QPushButton(layoutWidget);
        btnLoadCompiler->setObjectName(QString::fromUtf8("btnLoadCompiler"));

        gridLayout->addWidget(btnLoadCompiler, 0, 3, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        configPath = new QLineEdit(layoutWidget);
        configPath->setObjectName(QString::fromUtf8("configPath"));
        configPath->setReadOnly(true);

        gridLayout->addWidget(configPath, 1, 1, 1, 2);

        btnLoadConfig = new QPushButton(layoutWidget);
        btnLoadConfig->setObjectName(QString::fromUtf8("btnLoadConfig"));

        gridLayout->addWidget(btnLoadConfig, 1, 3, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        outputPath = new QLineEdit(layoutWidget);
        outputPath->setObjectName(QString::fromUtf8("outputPath"));
        outputPath->setReadOnly(true);

        gridLayout->addWidget(outputPath, 2, 1, 1, 2);

        btnSelectOutput = new QPushButton(layoutWidget);
        btnSelectOutput->setObjectName(QString::fromUtf8("btnSelectOutput"));

        gridLayout->addWidget(btnSelectOutput, 2, 3, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 640, 22));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "closureQt", 0, QApplication::UnicodeUTF8));
        btnCompile->setText(QApplication::translate("MainWindow", "compile", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Closure Compiler:", 0, QApplication::UnicodeUTF8));
        btnLoadCompiler->setText(QApplication::translate("MainWindow", "load ", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "config-file:", 0, QApplication::UnicodeUTF8));
        btnLoadConfig->setText(QApplication::translate("MainWindow", "load", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "output-File:", 0, QApplication::UnicodeUTF8));
        btnSelectOutput->setText(QApplication::translate("MainWindow", "select", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
