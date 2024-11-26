//
// Created by tianya on 2024/11/15.
//

#ifndef INC_24_11_06_14_PERSON_H
#define INC_24_11_06_14_PERSON_H

#pragma once
#include "iostream"
using namespace std;

template<class T1,class T2>
class Person{
public:
    //类内实现
    Person(T1 name,T2 age);

    void showPerson();

    T1 m_Name;
    T2 m_Age;
};



#endif //INC_24_11_06_14_PERSON_H
