//
// Created by tianya on 2024/11/15.
//

#include "14_2person.h"
//���캯��������ʵ��
template<class T1,class T2>
Person<T1,T2>::Person(T1 name, T2 age) {
    this->m_Name = name;
    this->m_Age = age;
}

//��Ա����������ʵ��
template<class T1,class T2>
void Person<T1,T2>::showPerson(){
    cout<<"������"<< this->m_Name<< endl;
    cout<<"���䣺"<< this->m_Age<< endl;
}

