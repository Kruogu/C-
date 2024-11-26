//
// Created by tianya on 2024/9/10.
//
#include "iostream"
using namespace std;

//成员变量 和 成员函数 是分开存储的

class Person{
     int m_A;//非静态成员变量，属于类的对象上

     static int m_B;//静态成员变量，不属于类的对象上 还是4

     void func(){}//非静态成员函数，不属于类的对象上  还是4

     static void func2(){}//静态成员函数，不属于类的对象上  还是4
};
int Person::m_B = 0;//初始化静态变量

void test01(){
    Person p;
//    空对象占用内存空间为：1个字节
//    C++编译器会给每个空对象也分配一个字节空间，为了区分空对象占内存的位置
//    每个空对象也应该有一个独一无二的内存地址
    cout<<"size of p = "<<sizeof(p)<<endl;
}
void test02(){
    Person p;
    cout<<"size of p = "<<sizeof(p)<<endl;
}
int main(){
    test01();//1个字节
    test02();//变成4个字节了
    cout<<"HelloWorld"<<endl;
    return 0;
}
