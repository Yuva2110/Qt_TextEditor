#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QMessageBox>
#include <QFileDialog>
#include <QPrinter>
#include <QFontDialog>
#include <QColorDialog>
#include <QPrintDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_as_triggered();

    void on_actionExit_triggered();

    void on_actionCopy_triggered();

    void on_actionCut_triggered();

    void on_actionPaste_triggered();

    void on_actionFind_triggered();

    void on_actionUndo_triggered();

    void on_actionSelect_all_triggered();

    void on_actionRedo_triggered();

    void on_actionZoom_in_triggered();

    void on_actionZoom_out_triggered();

    void on_actionFonts_triggered();

    void on_actionColors_triggered();

    void on_actionAbout_me_triggered();

    void on_actionHelp_triggered();

    void on_actionSubscript_triggered();

    void on_actionSuperscript_triggered();

private:
    Ui::MainWindow *ui;
    QString currFile="";
};
#endif // MAINWINDOW_H
