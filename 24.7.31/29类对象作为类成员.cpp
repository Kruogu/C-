//
// Created by tianya on 2024/9/8.
//
#include "iostream"
using namespace std;

//�������Ϊ���Ա

//�ֻ���
class Phone{
public:
    Phone(string pName){
        cout<<"Phone�Ĺ��캯������"<<endl;
        m_PName = pName;
    }
    ~Phone(){
        cout<<"Phone��������������"<<endl;
    }
//    �ֻ�Ʒ������
    string m_PName;
};

//����
class Person{
public:
    //Phone m_Phone = pName  ��ʽת����
    Person(string name,string pName):m_Name(name),m_Phone(pName)
    {
        cout<<"Person�Ĺ��캯������"<<endl;
    }
    ~Person(){
        cout<<"Person��������������"<<endl;
    }
//    ����
    string m_Name;
//    �ֻ�
    Phone m_Phone;
};

//��������Ķ�����Ϊ�����Ա������ʱ���ȹ���������ٹ�������������˳��
//������˳���빹���෴

void test01(){
    Person p("����","ƻ��MAX");
    cout<<"m_Name = "<<p.m_Name<<endl;
    cout<<"m_Phone = "<<p.m_Phone.m_PName<<endl;
    cout<<p.m_Name<<"���ţ�"<<p.m_Phone.m_PName<<endl;
}
int main(){
    test01();
    cout<<"HelloWorld11"<<endl;
return 0;
}
