//
// Created by tianya on 2024/9/9.
//
#include "iostream"
using namespace std;

//静态成员函数
//所有对象共享同一个函数
//静态成员函数只能访问静态成员变量
class Person{
public:
//    静态成员函数
    static void func(){
        m_A = 100;//静态成员函数可以访问静态成员变量,大家共享，不需要区分
//        m_B = 200;//报错，静态成员函数不可以访问非静态成员变量，无法区分到底是哪个对象的m_B属性
        cout<<"static void func调用"<<endl;
    }

    static int m_A;//静态成员变量
    int m_B; //非静态成员变量

//    静态成员函数也是有访问权限的
private:
    static void func2(){
        cout<<"static void func2调用"<<endl;
    }
};

//静态成员变量类内声明，类外初始化
int Person::m_A = 0;



//有两种访问方式
void test01(){
//    1.通过对象进行访问
    Person p;
    p.func();

//    2.通过类名访问
    Person::func();

//    Person::func2();//类外无法访问 私有 静态成员函数
}

int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
