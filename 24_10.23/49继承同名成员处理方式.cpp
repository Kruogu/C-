//
// Created by tianya on 2024/10/26.
//
#include "iostream"
using namespace std;

//继承同名成员处理方式
class Base{  // 父类
public:
    Base(){
        m_A = 100;
    }
    void func(){
        cout<<"Base - func()调用"<<endl;
    }
    void func(int a){
        cout<<"Base - func(int a)调用"<<endl;
    }
    int m_A;
};

class Son:public Base{
public:
    Son(){
        m_A = 200;
    }
    void func(){
        cout<<"Son - func()调用"<<endl;
    }
    void func(int a){
        cout<<"Son - func(int a)调用"<<endl;
    }
    int m_A;
};

//同名成员属性处理方式
void test01(){
    Son s;
    cout<<"Son 下 m_A = "<<s.m_A<<endl; // 子类对象数据

//    如果通过子类对象访问到父类中同名成员，需要加作用域
    cout<<"Base 下 m_A = "<<s.Base::m_A<<endl; // 加一个父类作用域

}

//同名成员函数处理方式
void test02(){
    Son s;
    s.func();//直接调用  调用是子类中的同名成员函数
    //如何调用到父类中同名成员函数？
    s.Base::func(); // 父类

//如果子类中出现和父类同名的成员函数，子类的同名成员会隐藏掉父类中所有同名成员函数
//如果想访问到父类中被隐藏的同名成员函数，需要加作用域
    s.Base::func(1); // 父类重载  不能直接调用
    s.func(1);// 子类重载
//    总结：子类优先原则（爸爸宠儿子）

}
int main(){
//    test01();
    test02();
    cout<<"HelloWorld"<<endl;
    return 0;
}
