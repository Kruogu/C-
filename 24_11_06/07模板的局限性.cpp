//
// Created by tianya on 2024/11/8.
//

#include "iostream"
using namespace std;

//ģ��ľ�����
//ģ�岢�������ܵ�,��Щ�ض��������ͣ���Ҫ�þ��廯��ʽ������ʵ��

class Person{
public:
    Person(string name,int age){
        this->m_Name = name;
        this->m_Age = age;
    }
    //����
    string m_Name;
    //����
    int m_Age;
};


//�Ա����������Ƿ���Ⱥ���
template<class T>
bool myCompare(T &a,T &b){//compare  �Ƚ�
    if(a == b){
        return true;
    } else{
        return false;
    }
}

//���þ��廯Person�İ汾ʵ�ִ��룬���廯���ȵ���
template<>bool myCompare(Person &p1,Person &p2){
//bool myCompare(Person &p1,Person &p2){//����Ҳ��
    if(p1.m_Name==p2.m_Name && p1.m_Age==p2.m_Age){
        return true;
    } else{
        return false;
    }
}


void test01(){
    int a = 10;
    int b = 20;
    bool ret = myCompare(a,b);
    if(ret) {
        cout<<"���������"<<endl;
    }
    else {
        cout<<"�����������"<<endl;
    }
}

void test02(){
    Person p1("Tom",10);
    Person p2("Tom",10);
    bool ret = myCompare(p1,p2);//ֱ�ӱ��� ���಻�ܱȽ�
//    ��һ�ֽ������������ == �������̫�鷳�ˣ�������ʹ��
//    �ڶ��ֽ�����������غ���ģ��,���ȵ�������
    if(ret)
        cout<<"p1 = p2"<<endl;
    else
        cout<<"p1 != p2"<<endl;
}
int main(){
//    test01();
    test02();
    cout<<"HelloWorld"<<endl;
    return 0;
}
