//
// Created by tianya on 2024/10/22.
//
#include "iostream"
using namespace std;

//���ع�ϵ�����
class Person{
public:
    Person(string name,int age){
        m_Name = name;
        m_Age = age;
    }

//    ���� == ��
//    void operator ==  (Person &p){
    bool operator ==  (Person &p){
        if(this->m_Name == p.m_Name && this->m_Age == p.m_Age)
        {
            return true;
        }else{
            return false;
        }
    }

    //    ���� != ��
    bool operator !=  (Person &p){
        if(this->m_Name != p.m_Name || this->m_Age != p.m_Age)
        {
            return true;
        }else{
            return false;
        }
    }
    string m_Name;
    int m_Age;
};

void test01(){
    Person p1("Tom",18);
//    Person p2("Tom",18);
    Person p2("Jerry",18);

//    if(p1 == p2){// == ����  ���غ��ٱ���
//        cout<<"p1��p2����ȵ�!"<<endl;
//    }else{
//        cout<<"p1��p2�ǲ���ȵ�!"<<endl;
//    }

    if(p1 != p2){// == ����  ���غ��ٱ���
        cout<<"p1��p2�ǲ���ȵ�!"<<endl;
    }else{
        cout<<"p1��p2����ȵ�!"<<endl;
    }

}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
