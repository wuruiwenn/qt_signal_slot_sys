#include"qobject.h"
#include <cstring>


Object::Object() {

}

Object::~Object() {

}

//connect()做的事情，它根据传入的signals字符串查找到对应的槽函数索引
//但是connect并不会执行槽函数，connect()只构造信号-槽关联关系
// 槽函数是 emit signal; 时才执行

//connect()做的事情应该是：在内部建立信号-槽的关联关系：
// 将信号和槽的对应关系保存到一个类似 multimap 的结构中：
// void Object::connect(Object* sender, const char* signal, Object* receiver, const char* slot)
// {
//     // int sig_dx = findSignalIndex(sender->, signal);
// }

//字符串查找，str是否包含subStr
int Object::findSignalIndex(const char* str, const char* subStr)
{
    if (!str || !subStr || strlen(str) < strlen(subStr))
        return -1;
    int cmpRet = strcmp(str, subStr);
    if (cmpRet == 0)
        return cmpRet;
    return -1;
}

std::string Object::getClassName() {
    return typeid(*this).name();
}