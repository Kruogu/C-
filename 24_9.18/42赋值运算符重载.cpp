//
// Created by tianya on 2024/10/10.
//
#include "iostream"
using namespace std;

//赋值运算符重载

class Person{
public:
    Person(int age){
        m_Age = new int(age);
    }
    ~Person(){//释放堆区空间  堆区内存重复释放，导致程序崩溃
//        解决方案，利用深拷贝解决浅拷贝带来的问题
        //正常应该崩溃，实际上为什么还可以运行？
        if(m_Age!=NULL){
            delete m_Age;
            m_Age = NULL;
        }
    }
//    void operator=(Person &p){
    Person& operator=(Person &p){
//        编译器是提供浅拷贝
//        m_Age = p.m_Age;

//        应该先判断是否有属性在堆区，如果有先释放干净，然后再深拷贝
        if(m_Age!=NULL){
            delete m_Age;
            m_Age = NULL;
        }
//        深拷贝操作
        m_Age = new int(*p.m_Age);

//        返回对象本身
        return *this;
    }
    int *m_Age;
};

void test01(){
    Person p1(18);
    cout<<"p1的年龄为："<<p1.m_Age<<endl;//p1的年龄为：0x17001326880
    cout<<"p1的年龄为："<<*p1.m_Age<<endl;//p1的年龄为：18  加了一个解引用的操作

    Person p2(20);
    cout<<"p2的年龄为："<<*p2.m_Age<<endl;

    p2 = p1;//赋值操作
    cout<<"p2被p1赋值的年龄为："<<*p2.m_Age<<endl;

    Person p3(30);
    p3 = p2 = p1;//报错，不能连续赋值，p2返回值是void
    cout<<"p1的年龄为："<<*p1.m_Age<<endl;
    cout<<"p2的年龄为："<<*p2.m_Age<<endl;
    cout<<"p3的年龄为："<<*p3.m_Age<<endl;
}
int main(){
    test01();

    int a = 10;
    int b = 20;
    int c = 30;

    c = b = a;
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    cout<<"c = "<<c<<endl;
    cout<<"HelloWorld"<<endl;
    return 0;
}
