//
// Created by tianya on 2024/10/26.
//

//E:\0Work\0workspace\24_10.23
//dir
//cl /d1 reportSingleClassLayoutSon 51多继承语法.cpp
#include "iostream"
using namespace std;

//多继承语法
class Base1{
public:
    Base1(){
        m_A = 100;
    }
    int m_A;
};


class Base2{
public:
    Base2(){
//        m_B = 200;
        m_A = 200;//假设和父类1中的对象一样
    }
//    int m_B;
    int m_A;//假设和父类1中的对象一样
};

//子类 需要继承Base1和BaSe2
//语法：c1ass子类：继承方式 父类1，继承方式 父类2...
class Son:public Base1,public Base2{
public:
    Son(){
        m_C = 300;
        m_D = 400;
    }
    int m_C;
    int m_D;
};

void test01(){
    Son s;
    cout<<"sizeof Son = "<<sizeof(Son)<<endl;//16
    cout<<"sizeof Son = "<<sizeof(s)<<endl;//16

//    当父类中出现同名成员，需要加作用域区分
//    cout<<"m_A = "<<s.m_A<<endl; //意义不明确
    cout<<"Base1::m_A = "<<s.Base1::m_A<<endl;
    cout<<"Base2::m_A = "<<s.Base2::m_A<<endl;
//    cout<<"m_B = "<<s.m_B<<endl;

    cout<<"m_C = "<<s.m_C<<endl;
    cout<<"m_D = "<<s.m_D<<endl;
}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
