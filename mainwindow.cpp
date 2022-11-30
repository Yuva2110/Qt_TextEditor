#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QFileDialog>
#include<QMessageBox>
#include <QDesktopServices>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    currFile.clear();
    ui->textEdit->setText(QString());
}


void MainWindow::on_actionOpen_triggered()
{
    QString Myfile=QFileDialog::getOpenFileName(this,"Open the File");
    QFile file(Myfile);
    currFile =Myfile;
    if(!file.open(QIODevice:: ReadOnly | QFile :: Text)){
        QMessageBox::warning(this,"Warning","Cannot open file : "+file.errorString());
    }
    setWindowTitle(Myfile);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}


void MainWindow::on_actionSave_triggered()
{
     QApplication::quit();
}


void MainWindow::on_actionSave_as_triggered()
{
    QString Myfile = QFileDialog::getSaveFileName(this,"Save as");
    QFile file(Myfile);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"Warning","Cannot save file : "+file.errorString());
        return ;
    }
    currFile = Myfile;
    setWindowTitle(Myfile);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out<< text ;
    file.close();
}


void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}


void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}


void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}


void MainWindow::on_actionFind_triggered()
{
    //ui->textEdit->search();
}


void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}


void MainWindow::on_actionSelect_all_triggered()
{
    ui->textEdit->selectAll();
}


void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}


void MainWindow::on_actionZoom_in_triggered()
{
    ui->textEdit->zoomIn(10);
}


void MainWindow::on_actionZoom_out_triggered()
{
    ui->textEdit->zoomOut(10);
}


void MainWindow::on_actionFonts_triggered()
{
    bool ok;

    QFont font = QFontDialog::getFont(&ok,QFont("Helvetical[Cronyx]",12),this);

    if(ok){
        ui->textEdit->setFont(font);
    }
}


void MainWindow::on_actionColors_triggered()
{
    bool a=true;

    QColor color = QColorDialog::getColor(Qt :: yellow,this);

    if(a) {
        ui->textEdit->setTextColor(color);
    }
}


void MainWindow::on_actionAbout_me_triggered()
{
    QString f= QFileDialog::getOpenFileName(
                this,tr("Open File"),
                "c://","All files (*.*);;Text File(*.txt);;Music filr (*.mp3)");
    QDesktopServices ::openUrl(QUrl("file : ///"+f,QUrl::TolerantMode));
}


void MainWindow::on_actionHelp_triggered()
{
 //   ui->textEdit->();
}


void MainWindow::on_actionSubscript_triggered()
{
    QTextCharFormat format;
    format.setVerticalAlignment(QTextCharFormat::AlignSubScript);
    if(ui->textEdit->hasFocus())
        ui->textEdit->mergeCurrentCharFormat(format);
}


void MainWindow::on_actionSuperscript_triggered()
{
    QTextCharFormat format;
    format.setVerticalAlignment(QTextCharFormat::AlignSuperScript);
    if(ui->textEdit->hasFocus())
        ui->textEdit->mergeCurrentCharFormat(format);
}

