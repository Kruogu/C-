//
// Created by tianya on 2024/10/10.
//
#include "iostream"
using namespace std;

//��ֵ���������

class Person{
public:
    Person(int age){
        m_Age = new int(age);
    }
    ~Person(){//�ͷŶ����ռ�  �����ڴ��ظ��ͷţ����³������
//        �������������������ǳ��������������
        //����Ӧ�ñ�����ʵ����Ϊʲô���������У�
        if(m_Age!=NULL){
            delete m_Age;
            m_Age = NULL;
        }
    }
//    void operator=(Person &p){
    Person& operator=(Person &p){
//        ���������ṩǳ����
//        m_Age = p.m_Age;

//        Ӧ�����ж��Ƿ��������ڶ�������������ͷŸɾ���Ȼ�������
        if(m_Age!=NULL){
            delete m_Age;
            m_Age = NULL;
        }
//        �������
        m_Age = new int(*p.m_Age);

//        ���ض�����
        return *this;
    }
    int *m_Age;
};

void test01(){
    Person p1(18);
    cout<<"p1������Ϊ��"<<p1.m_Age<<endl;//p1������Ϊ��0x17001326880
    cout<<"p1������Ϊ��"<<*p1.m_Age<<endl;//p1������Ϊ��18  ����һ�������õĲ���

    Person p2(20);
    cout<<"p2������Ϊ��"<<*p2.m_Age<<endl;

    p2 = p1;//��ֵ����
    cout<<"p2��p1��ֵ������Ϊ��"<<*p2.m_Age<<endl;

    Person p3(30);
    p3 = p2 = p1;//��������������ֵ��p2����ֵ��void
    cout<<"p1������Ϊ��"<<*p1.m_Age<<endl;
    cout<<"p2������Ϊ��"<<*p2.m_Age<<endl;
    cout<<"p3������Ϊ��"<<*p3.m_Age<<endl;
}
int main(){
    test01();

    int a = 10;
    int b = 20;
    int c = 30;

    c = b = a;
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    cout<<"c = "<<c<<endl;
    cout<<"HelloWorld"<<endl;
    return 0;
}
