//
// Created by tianya on 2024/9/9.
//
#include "iostream"
using namespace std;

//静态成员变量
class Person{
public:
//    1.所有对象都共享同一份数据
//    2.编译阶段就分配了内存
//    3.类内声明，类外初始化操作
    static int m_A;

//    静态成员变量也是有访问权限的
private:
    static int m_B;
};

int Person::m_A=100;  //类内声明，类外初始化操作
int Person::m_B=200;

void test01(){
    Person p;//p = 100
    cout<<p.m_A<<endl;

    Person p2;//p2 = 200
    p2.m_A = 200;
    cout<<p2.m_A<<endl;

    cout<<p.m_A<<endl;//p = 200
}
void test02(){
//    静态成员变量不属于某个对象上，所有对象共享同一份数据
//    因此静态成员变量有两种访问方式
//    1.通过对象进行访问
//    Person p;
//    cout<<p.m_A<<endl;

//    2.通过类名进行访问
//    也可以不用创建对象，直接调用Person作用域下的m_A输出
//    非静态成员变量必须创建对象才能读写，静态可以直接访问
    cout<<Person::m_A<<endl;

//    cout<<Person::m_B<<endl;//私有权限，不可以访问
//    类外访问不到私有的静态成员变量
}
int main(){
//    test01();
    test02();
    cout<<"HelloWorld12"<<endl;
    return 0;
}
