//
// Created by tianya on 2024/11/8.
//

#include "iostream"
using namespace std;

//1.3.4��ģ���������������

template<class T1,class T2>
class Person{
public:
    Person(T1 name,T2 age){
        this->m_Name = name;
        this->m_Age = age;
    }

    void showPerson(){
        cout<<"����:"<< this->m_Name<< endl;
        cout<<"����:"<< this->m_Age<< endl;
    }
    T1 m_Name;
    T2 m_Age;
};

//��õ�����
//1.ָ����������͡���ֱ����ʾ�������������  ��ģ��Ķ���,�������еĲ���
void printPerson1(Person<string ,int>&p){//ֱ������,�������þ���ֵ����
    p.showPerson();
}
void test01(){
    Person<string ,int>p("����",18);
    printPerson1(p);//��һ��
//    p.showPerson();
}


//2.����ģ�廯�����������еĲ�����Ϊģ����д���
template<class T1,class T2>
void printPerson2(Person<T1,T2>&p){
    p.showPerson();
    cout<<"T1������Ϊ:"<< typeid(T1).name()<< endl;//�鿴�������Ƶ�������T��������
    cout<<"T2������ Ϊ:"<< typeid(T2).name()<< endl;
}
void test02(){
    Person<string ,int>p("��˽�",90);
    printPerson2(p);
}


//3.������ģ�廯�����������������ģ�廯���д���
template<class T>
void printPerson3(T &p){
    p.showPerson();
    cout<<"T������Ϊ:"<< typeid(T).name()<< endl;//�鿴�������Ƶ�������T��������
//    6PersonINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE
//     Person��                   string                           int
}
void test03(){
    Person<string ,int>p("��ɮ",30);
    printPerson3(p);
}
int main(){
    test01();
    test02();
    test03();
    cout<<"HelloWorld"<<endl;
    return 0;
}
