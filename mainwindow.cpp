#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include "qtquestc.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString SavDir;
    if (QFileInfo("SavedDir.txt").exists())
    {
        QFile inputFile("SavedDir.txt");
        if (inputFile.open(QIODevice::ReadOnly))
        {
            QTextStream in(&inputFile);
            SavDir = in.readLine();
            qtQuestC qt(SavDir);

            ui->textEdit->setText(SavDir);
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QFileDialog msgDialog(this);     // диалоговое окно
    msgDialog.setFileMode(QFileDialog::Directory);
    QString fileNames;
    fileNames = msgDialog.getExistingDirectory();
    if (fileNames.isEmpty() == false)
    {
        ui->textEdit->setText(fileNames);
        qtQuestC qt(fileNames);
    }
}

