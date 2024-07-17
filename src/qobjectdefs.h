#pragma once
#include"qobject.h"
#include<iostream>
#include<sstream>

// 模拟 QT中 qobjectdefs.h
// 主要是定义元对象结构、一些全局宏，如Q_OBJECT、signals、slots

// 一些全局宏
#define W_OBJECT \
public:\
static MetaObject staticMetaObject;\
MetaObject* metaObject();\
void qt_meta_call(int slotIndx);\

#define w_signals public
#define w_slots public  //简单实现所有slot为public型
#define w_emit //空宏


struct MetaObject //元对象 结构
{
    const char* signal_names;
    const char* slot_names;

    //激活信号发送过程
    //需记录发送信号者，所发送的信号函数的索引
    template<class T>
    static void activate(T* sender, int signal_indx);
};

//Connection结构：存储接受信号的对象、对应槽函数的索引
struct Connection
{
    Object* receiver;
    int slotIndx;

    std::string getClassInfo() {
        std::ostringstream oss;
        oss << "[ObjectName:" << receiver->getClassName() << ",slotIndx:" << slotIndx << "]";
        return oss.str();
    }
};




//activate激活信号发送
//本质就是 根据已经初始化的 信号-槽 关联关系 的map，找到当前信号对应的槽函数，并执行
template<class T>
inline void MetaObject::activate(T* sender, int signal_indx)
{
    //这里体现C++观察者模式，一个信号状态变化，会通知所有和他关联的槽函数
    auto ret_pair = sender->SigSlotMap.equal_range(signal_indx);
    auto valid_begin = ret_pair.first;
    auto valid_end = ret_pair.second;
    auto it = valid_begin;
    for (auto it = valid_begin;it != valid_end;it++)
    {
        std::cout << "找到指定信号函数对应的槽函数信息：\n";
        std::cout << "{" << it->first << "," << it->second.getClassInfo() << "}\n";

        //正式执行所找到对应的槽函数
        // it->second.slotIndx 这是对应槽函数的索引
        // QT中使用qt_metacall() 根据槽函数索引，找到对应槽函数进行执行
        // QT中似乎使用qt_metacall纯粹是Q_OBECJT声明得到的，然后moc_xxx.cpp为当前自定义的类中实现了它
        //并不是 QWidget、QObject中声明的函数、或接口
        int slot_dx = it->second.slotIndx;
        sender->qt_meta_call(slot_dx);
    }
}
