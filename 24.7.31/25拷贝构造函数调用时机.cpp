//
// Created by tianya on 2024/8/1.
//
#include "iostream"
using namespace std;

//�������캯������ʱ��


class Person{
public:
    Person(){
        cout<<"PersonĬ�Ϲ��캯������"<<endl;

    }
    Person(int age){
        cout<<"Person�вι��캯������"<<endl;
        m_Age = age;
    }
    Person(const Person &p){
        cout<<"Person�������캯������"<<endl;
        m_Age = p.m_Age;
    }
    ~Person(){
        cout<<"Person������������"<<endl;
    }

    int m_Age;
};

//1��ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
void test01(){
    Person p1(20);
    Person p2(p1);
    cout<<"P2������Ϊ�� "<<p2.m_Age<<endl;
}
//2��ֵ���ݵķ�ʽ������������ֵ
void doWork(Person p){}

void test02(){
    Person p;
    doWork(p);  //Ҳ��һ�ο������캯��
}

//3��ֵ��ʽ���ؾֲ�����
Person doWork2(){
    Person p1;
//    return p1;
    cout<<"p1:"<<(int*)&p1<<endl;
    return Person(p1);//����Ϳ�����������������
}
void test03(){      //����Ӧ���ǵ�������
    Person p = doWork2();
    cout<<"p:"<<(int*)&p<<endl;
}

int main(){
//    test01();
//    test02();
    test03();
    cout<<"HelloWorld"<<endl;
    return 0;
}
