#include<iostream>
#include"MyWidget.h"

// 参考：https://blog.csdn.net/perfectguyipeng/article/details/78082360

int main() {
    MyWidget* obj1 = new MyWidget();
    MyWidget* obj2 = new MyWidget();
    obj1->connect(obj1, "mySignal()", obj2, "mySlot()");
    obj1->testEmitSignal();
}