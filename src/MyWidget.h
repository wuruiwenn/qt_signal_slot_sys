#pragma once

#include"qobject.h"
#include"qobjectdefs.h"
#include<map>

// struct MetaObject //元对象，QT中是把其放在单独的 qobjectdefs.h中
// {
//     const char* signal_nams;
//     const char* slot_names;
// };

//自定义的窗口类
class MyWidget :public Object
{
public:
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
    typedef SigSlotMapType::iterator MapIterType;
    SigSlotMapType SigSlotMap;//存储当前类的 信号-槽 关联关系 的map

public:
    void testEmitSignal();
};