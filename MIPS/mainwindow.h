#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "assembler.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    assembler manager;
    assembler queue[13];
    unsigned int pr;
    unsigned int address;

public slots:
    void on_compiler_clicked();
    void on_exec_clicked();
    void on_addcheck_clicked();
    void on_lastpage_clicked();
    void on_nextpage_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_cancel_clicked();
};

#endif // MAINWINDOW_H
