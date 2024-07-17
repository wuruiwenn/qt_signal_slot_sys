
// 手动实现QT中moc_xxx.cpp文件，就是填充元对象信息，
// 即 自定义类的 类信息、函数信息、信号槽信息
// QT中是通过<moc元对象编译器>实现得到moc_xxx.cpp的

#include"MyWidget.h"


//(手动)填充属于自定义类的元对象信息
//简单起见，就定义一个信号-槽
const char signal_names[] = "mySignal()";
const char slot_names[] = "mySlot()";
MetaObject MyWidget::staticMetaObject = { signal_names,slot_names };

//获取指向元对象的指针
MetaObject* MyWidget::metaObject() {
    return &staticMetaObject;
}

//实现信号函数
void MyWidget::mySignal() {
    MetaObject::activate<MyWidget>(this, 0);
}

void MyWidget::qt_meta_call(int slotIndx) {
    switch (slotIndx)
    {
    case 0:
        mySlot();
    }
}









