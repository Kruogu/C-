//
// Created by tianya on 2024/9/10.
//
#include "iostream"
using namespace std;

class Person{
public:
    Person(int age){
//        age = age;
//    thisָ��ָ�򱻵��ó�Ա���������Ķ���
        this->age = age;
    }

//    void PersonAddAge(Person &p){
//        this->age += p.age;
//    }

//    ����  ���ɾ�� &����  ���ص���ֵ  ���20
    Person& PersonAddAge(Person &p){
        this->age += p.age;
//        thisָ�����һ��p2��ָ�룬��*thisָ��ľ���p2���������
        return *this;//p2�ı���
    }
    int age;
    int m_Age;//�õ�ϰ�ߣ�����淶   ��ԱAge
};

//1.������Ƴ�ͻ
void test01(){
    Person p1(18);
    cout<<"p1������Ϊ��"<<p1.age<<endl;
}

//2.���ض������� *this
void test02(){
    Person p1(10);

    Person p2(10);

//    p2.PersonAddAge(p1);
//    cout<<"p2������Ϊ��"<<p2.age<<endl;//20   p1�ӵ�p2��

//    ��ʽ���˼�룬������������׷��  coutҲ��
    p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);//����
    cout<<"p2������Ϊ��"<<p2.age<<endl;//40   p1�����ӵ�p2��
}
int main(){
    test01();
    test02();
    cout<<"HelloWorld"<<endl;
    return 0;
}
