//
// Created by tianya on 2024/11/13.
//
#include "iostream"
using namespace std;
//��ģ���Ա��������ʵ��
template<class T1,class T2>
class Person{
public:
    //����ʵ��
    Person(T1 name,T2 age);
//    Person(T1 name,T2 age){
//        this->m_Name = name;
//        this->m_Age = age;
//    }
    void showPerson();
//    void showPerson(){
//        cout<<"������"<< this->m_Name<< endl;
//        cout<<"���䣺"<< this->m_Age<< endl;
//    }
    T1 m_Name;
    T2 m_Age;
};

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

void test01(){
    Person<string,int> P("Tom",20);
    P.showPerson();
}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
