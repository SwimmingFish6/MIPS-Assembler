#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "assembler.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("MIPS汇编");
    this->address = 0;
    this->pr = 0;
    ui->address->setText("0x0000");
    ui->address_2->setText("0x0000");
    manager.shiftAddress(ui);
    manager.shiftReg(ui);
    this->setFixedSize(830,500);

    QPixmap pixmapBg = QPixmap(":/bg.jpg").scaled(this->size());
    QPalette paletteBg(this->palette());
    paletteBg.setBrush(QPalette::Background, QBrush(pixmapBg));
    this->setPalette(paletteBg);

    QColor myLayoutColor(0xEF,0xEF,0xEF);
    myLayoutColor.setAlphaF(0.8);
    QPalette paletteLayout(this->palette());
    paletteLayout.setColor(QPalette::Background, myLayoutColor);
    ui->formLayoutWidget_5->setPalette(paletteLayout);
    ui->formLayoutWidget_5->setAutoFillBackground(true);
    ui->formLayoutWidget_6->setPalette(paletteLayout);
    ui->formLayoutWidget_6->setAutoFillBackground(true);
    ui->formLayoutWidget->setPalette(paletteLayout);
    ui->formLayoutWidget->setAutoFillBackground(true);
    ui->formLayoutWidget_2->setPalette(paletteLayout);
    ui->formLayoutWidget_2->setAutoFillBackground(true);
    ui->formLayoutWidget_3->setPalette(paletteLayout);
    ui->formLayoutWidget_3->setAutoFillBackground(true);
    ui->formLayoutWidget_4->setPalette(paletteLayout);
    ui->formLayoutWidget_4->setAutoFillBackground(true);
    ui->formLayoutWidget_7->setPalette(paletteLayout);
    ui->formLayoutWidget_7->setAutoFillBackground(true);
    ui->formLayoutWidget_8->setPalette(paletteLayout);
    ui->formLayoutWidget_8->setAutoFillBackground(true);
    ui->label_2->setPalette(paletteLayout);
    ui->label_2->setAutoFillBackground(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_exec_clicked(){
    if(pr<13){
        queue[pr++] = manager;
    }
    manager.exec();
    manager.shiftReg(ui);
    manager.shiftAddress(ui);
}

void MainWindow::on_pushButton_2_clicked(){
    manager.reset();
    manager.shiftAddress(ui);
    manager.shiftReg(ui);
}

void MainWindow::on_compiler_clicked(){
    QString inst = ui->assinput->toPlainText();
    QStringList list = inst.split("\n");

    if(NULL == inst){
        QMessageBox::information(NULL, "ERROR","汇编指令输入栏不能为空！", QMessageBox::Yes, QMessageBox::Yes);
        return;
    }

    foreach(QString str , list){
        char*  buf;
        int result;

        QByteArray ba = str.toLatin1();
        buf=ba.data();

        result = manager.assemble(buf);

        if(!result) break;
        QMessageBox::information(NULL, "ERROR",str, QMessageBox::Yes, QMessageBox::Yes);
    }
    manager.shiftad_2(ui);
    manager.shiftAddress(ui);
}

void MainWindow::on_addcheck_clicked(){
    manager.shiftAddress(ui);
}

void MainWindow::on_lastpage_clicked(){
    manager.shiftad_3(ui);
    manager.shiftAddress(ui);
}

void MainWindow::on_nextpage_clicked(){
    manager.shiftad_4(ui);
    manager.shiftAddress(ui);
}

void MainWindow::on_pushButton_clicked(){
    manager.shiftad(ui);

    QMessageBox::information(NULL, "OK", "写入地址已改变！", QMessageBox::Yes, QMessageBox::Yes);
}

void MainWindow::on_cancel_clicked(){
    if(pr==0){
         QMessageBox::information(NULL, "ERROR","撤销失败!", QMessageBox::Yes, QMessageBox::Yes);

    }
    else{
    manager = queue[--pr];
    manager.shiftad(ui);
    manager.shiftAddress(ui);
    manager.shiftad_2(ui);
    manager.shiftad_3(ui);
    manager.shiftad_4(ui);
    manager.shiftReg(ui);
    }
}
