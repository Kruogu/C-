//
// Created by tianya on 2024/8/1.
//
#include "iostream"
using namespace std;

//拷贝构造函数调用时机


class Person{
public:
    Person(){
        cout<<"Person默认构造函数调用"<<endl;

    }
    Person(int age){
        cout<<"Person有参构造函数调用"<<endl;
        m_Age = age;
    }
    Person(const Person &p){
        cout<<"Person拷贝构造函数调用"<<endl;
        m_Age = p.m_Age;
    }
    ~Person(){
        cout<<"Person析构函数调用"<<endl;
    }

    int m_Age;
};

//1、使用一个已经创建完毕的对象来初始化一个新对象
void test01(){
    Person p1(20);
    Person p2(p1);
    cout<<"P2的年龄为： "<<p2.m_Age<<endl;
}
//2、值传递的方式给函数参数传值
void doWork(Person p){}

void test02(){
    Person p;
    doWork(p);  //也是一次拷贝构造函数
}

//3、值方式返回局部对象
Person doWork2(){
    Person p1;
//    return p1;
    cout<<"p1:"<<(int*)&p1<<endl;
    return Person(p1);//这个就可以正常调用两次了
}
void test03(){      //理论应该是调用两次
    Person p = doWork2();
    cout<<"p:"<<(int*)&p<<endl;
}

int main(){
//    test01();
//    test02();
    test03();
    cout<<"HelloWorld"<<endl;
    return 0;
}
