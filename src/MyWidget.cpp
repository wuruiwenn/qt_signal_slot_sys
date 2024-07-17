
// 自定义的窗口类

#include"MyWidget.h"
#include<iostream>
#include<typeinfo>

MyWidget::~MyWidget() {

}

MyWidget::MyWidget() {

}

void MyWidget::mySlot() {
    std::cout << "MySlot() is currently executing ! \n";
}


void MyWidget::connect(Object* sender, const char* signal, Object* receiver, const char* slot)
{
    MyWidget* curSenderObj = dynamic_cast<MyWidget*>(sender);
    MyWidget* curRevObj = dynamic_cast<MyWidget*>(receiver);

    int signal_indx = findSignalIndex(curSenderObj->metaObject()->signal_names, signal);
    int slot_indx = findSignalIndex(curRevObj->metaObject()->slot_names, slot);

    if (signal_indx == -1 || slot_indx == -1) {
        std::cout << "signal or slot not found !";
        return;
    }
    //若成功找到信号、对应槽，则初始化 信号-槽的关联关系map
    Connection tmpConn = { receiver,slot_indx }; //存储信号接收者对象指针，该信号对应槽函数的索引
    SigSlotMap.insert({ signal_indx,tmpConn });
}

//手动发送信号，测试
void MyWidget::testEmitSignal() {
    w_emit mySignal();
}