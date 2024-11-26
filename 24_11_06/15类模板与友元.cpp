//
// Created by tianya on 2024/11/16.
//
#include "iostream"
using namespace std;

//通过全局函数 打印Person信息

//提前让编译器知道Person类存在
template<class T1,class T2>
class Person;
//类外实现
template<class T1,class T2>
void printPerson2(Person<T1,T2> p){
    cout<<"类外实现姓名："<<p.m_Name<<endl;
    cout<<"类外实现年龄："<<p.m_Age<<endl;
}

//类模板与友元
template<class T1,class T2>
class Person{
    //全局函数 类内实现  加上友元
    friend void printPerson(Person<T1,T2> p){
        cout<<"姓名："<<p.m_Name<<endl;
        cout<<"年龄："<<p.m_Age<<endl;
    }

    //全局函数 类内实现  加上友元    加空模板参数列表<>
//    如果全局函数是类外实现，需要让编译器提前知道这个函数的存在
    friend void printPerson2<>(Person<T1,T2> p);
public:
    //类内实现
    Person(T1 name,T2 age){
        this->m_Name = name;
        this->m_Age = age;
    }

//    void showPerson();

private:
    T1 m_Name;
    T2 m_Age;
};

//类外实现
//template<class T1,class T2>
//void printPerson2(Person<T1,T2> p){
//    cout<<"类外实现姓名："<<p.m_Name<<endl;
//    cout<<"类外实现年龄："<<p.m_Age<<endl;
//}

//1、全局函数 在类内实现  加上友元
void test01(){
    Person<string,int> p("Tom",20);
    printPerson(p);
}

//2、全局函数 在类外实现
void test02(){
    Person<string,int> p("Jerry",20);
    printPerson2(p);
}
int main(){
//    test01();
    test02();
    cout<<"HelloWorld"<<endl;
    return 0;
}
