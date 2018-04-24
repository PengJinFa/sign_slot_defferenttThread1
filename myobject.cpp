#include "myobject.h"
#include<QThread>
#include<QDebug>

MyObject::MyObject()
{

}

MyObject::~MyObject()
{

}

void MyObject::on_btn_click()
{
    qDebug()<<"Thread t2 id:"<<this->thread()->currentThreadId();
}
