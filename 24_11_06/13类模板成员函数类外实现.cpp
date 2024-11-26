//
// Created by tianya on 2024/11/13.
//
#include "iostream"
using namespace std;
//类模板成员函数类外实现
template<class T1,class T2>
class Person{
public:
    //类内实现
    Person(T1 name,T2 age);
//    Person(T1 name,T2 age){
//        this->m_Name = name;
//        this->m_Age = age;
//    }
    void showPerson();
//    void showPerson(){
//        cout<<"姓名："<< this->m_Name<< endl;
//        cout<<"年龄："<< this->m_Age<< endl;
//    }
    T1 m_Name;
    T2 m_Age;
};

//构造函数的类外实现
template<class T1,class T2>
Person<T1,T2>::Person(T1 name, T2 age) {
    this->m_Name = name;
    this->m_Age = age;
}

//成员函数的类外实现
template<class T1,class T2>
void Person<T1,T2>::showPerson(){
    cout<<"姓名："<< this->m_Name<< endl;
    cout<<"年龄："<< this->m_Age<< endl;
}

void test01(){
    Person<string,int> P("Tom",20);
    P.showPerson();
}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
