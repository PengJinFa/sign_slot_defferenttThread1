#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QApplication>
#include<QThread>
#include<QDebug>
#include<myobject.h>
#include<thread>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qDebug()<<"Main thread id:"<<this->thread()->currentThreadId();
    QThread * t2=new QThread();
    t2->start();
    MyObject * obj1=new MyObject();
    //把对象移动到新线程
    obj1->moveToThread(t2);


    //连接到对象
    QObject::connect(this->ui->pushButton,SIGNAL(clicked()),obj1,SLOT(on_btn_click()));

}

MainWindow::~MainWindow()
{
    delete ui;
}
