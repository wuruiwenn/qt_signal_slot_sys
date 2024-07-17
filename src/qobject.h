#pragma once
#include<string>
#include<typeinfo>



// 模拟QT中 qobject.h
// QT 在qobject.h中声明了 顶层Object类、信号槽的 connect()函数

class Object 
{
public:
    Object();
    ~Object();
public:
    virtual void connect(Object* sender, const char* signal, Object* receiver, const char* slot) = 0;
    int findSignalIndex(const char* str, const char* subStr);

    virtual void qt_meta_call(int slotIndx) = 0;

public:
    std::string getClassName();
};
