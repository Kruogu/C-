//
// Created by tianya on 2024/11/8.
//
#include "iostream"
using namespace std;
//1.3.1��ģ���﷨
template<class NameType,class AgeType>//�������� ģ��
class Person{
public:
    Person(NameType name,AgeType age){
        this->m_Name = name;
        this->m_Age = age;
    }

    void showPerson()//��ӡ���һ��
    {
        cout<<"name��"<<this->m_Name<< endl;
        cout<<"age��"<<this->m_Age<< endl;
    }
    //����
//    string m_Name;//�� string ������Ըĳ� ��ģ��
    NameType m_Name;
    //����
//    int m_Age;
    AgeType m_Age;
};
void test01(){
    Person<string,int> p1("�����",99);
    p1.showPerson();//�������
}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
