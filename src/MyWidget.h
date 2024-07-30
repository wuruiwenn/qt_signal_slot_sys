#pragma once

#include"qobject.h"
#include"qobjectdefs.h"
#include<map>

//自定义的窗口类
class MyWidget :public Object
{
    W_OBJECT // 模拟QT Q_OBJECT宏

public:
    MyWidget();
    virtual ~MyWidget();

w_signals:
    void mySignal();

w_slots:
    void mySlot();
    void mySlot2();

public:
    void connect(Object* sender, const char* signal, Object* receiver, const char* slot) override;
public:
    typedef std::multimap<int, Connection> SigSlotMapType;
    // typedef SigSlotMapType::iterator MapIterType;
    SigSlotMapType SigSlotMap;//存储当前类的 信号-槽 关联关系 的map

public:
    void testEmitSignal();
};