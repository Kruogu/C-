//
// Created by tianya on 2024/10/26.
//


#include "iostream"
using namespace std;

//继承中的同名静态成员处理方式
class Base{
public:
    static int m_A;//类内声明，类外初始化
    static void func(){
        cout<<"Base - static void func()调用"<<endl;
    }
    static void func(int a){//重载版本
        cout<<"Base - static void func(int a)调用"<<endl;
    }
};
int Base::m_A = 100;

class Son:public Base{
public:
    static int m_A;
    static void func(){
        cout<<"Son - static void func()调用"<<endl;
    }
};
int Son::m_A = 200;

//同名静态成员属性

void test01(){
//    1.通过对象访问
    cout<<"通过对象访问："<<endl;
    Son s;
    cout<<"Son 下 m_A = "<<s.m_A<<endl;//先访问子类  200
    cout<<"Base 下 m_A = "<<s.Base::m_A<<endl;//访问父类 100

//    2.通过类名访问
    cout<<"通过类名访问："<<endl;
    cout<<"Son 下 m_A = "<<Son::m_A<<endl;//200  直接访问子类
    cout<<"Base 下 m_A = "<<Base::m_A<<endl;//100  直接访问父类
//    第一个::代表通过类名方式访问    第二个::代表访问父类作用域下
    cout<<"Base 下 m_A = "<<Son::Base::m_A<<endl;//通过子类访问父类，这样也行

}

//同名静态成员函数
void test02(){
//    1.通过对象访问
    cout<<"通过对象访问："<<endl;
    Son s;
    s.func();//现在调用的是子类 Son
    s.Base::func();//父类

//    2.通过类名访问
    cout<<"通过类名访问："<<endl;
    Son::func();
    Base::func();
    Son::Base::func();

//    重载版本
//    子类出现和父类同名静态成员函数，也会隐藏父类中所有同名成员函数
//    如果想访问父类中被隐藏同名成员，需要加作用域
//    Son::func(100);//直接调用不行,父类被隐藏了
    Son::Base::func(3);
}
int main(){
//    test01();
    test02();
    cout<<"HelloWorld"<<endl;
    return 0;
}
