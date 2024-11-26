//
// Created by tianya on 2024/11/15.
//

//#include "14_2person.h"//报错  类模板中的成员函数一开始是不会创建的

//第一种解决方式，直接包含源文件
//#include "14_2person.cpp"//成功

//第二种解决方式，将.h和.cpp中的内容写到一起，将后缀名改为.hpp文件
//.hpp一般代表类模板，不是必须的，约定俗成
#include "14_3person.hpp"

#include "iostream"
using namespace std;
//1.3.7类模板分文件编写
//template<class T1,class T2>
//class Person{
//public:
//    //类内实现
//    Person(T1 name,T2 age);
//
//    void showPerson();
//
//    T1 m_Name;
//    T2 m_Age;
//};
//
////构造函数的类外实现
//template<class T1,class T2>
//Person<T1,T2>::Person(T1 name, T2 age) {
//    this->m_Name = name;
//    this->m_Age = age;
//}
//
////成员函数的类外实现
//template<class T1,class T2>
//void Person<T1,T2>::showPerson(){
//    cout<<"姓名："<< this->m_Name<< endl;
//    cout<<"年龄："<< this->m_Age<< endl;
//}

void test01(){
    Person<string,int> P("Jerry",18);
    P.showPerson();
}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
