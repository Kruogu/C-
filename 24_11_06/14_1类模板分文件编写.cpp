//
// Created by tianya on 2024/11/15.
//

//#include "14_2person.h"//����  ��ģ���еĳ�Ա����һ��ʼ�ǲ��ᴴ����

//��һ�ֽ����ʽ��ֱ�Ӱ���Դ�ļ�
//#include "14_2person.cpp"//�ɹ�

//�ڶ��ֽ����ʽ����.h��.cpp�е�����д��һ�𣬽���׺����Ϊ.hpp�ļ�
//.hppһ�������ģ�壬���Ǳ���ģ�Լ���׳�
#include "14_3person.hpp"

#include "iostream"
using namespace std;
//1.3.7��ģ����ļ���д
//template<class T1,class T2>
//class Person{
//public:
//    //����ʵ��
//    Person(T1 name,T2 age);
//
//    void showPerson();
//
//    T1 m_Name;
//    T2 m_Age;
//};
//
////���캯��������ʵ��
//template<class T1,class T2>
//Person<T1,T2>::Person(T1 name, T2 age) {
//    this->m_Name = name;
//    this->m_Age = age;
//}
//
////��Ա����������ʵ��
//template<class T1,class T2>
//void Person<T1,T2>::showPerson(){
//    cout<<"������"<< this->m_Name<< endl;
//    cout<<"���䣺"<< this->m_Age<< endl;
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
