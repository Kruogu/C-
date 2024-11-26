//
// Created by tianya on 2024/11/15.
//

#include "14_2person.h"
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

