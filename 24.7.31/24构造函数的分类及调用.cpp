//
// Created by tianya on 2024/7/31.
//
#include "iostream"
using namespace std;

//1���캯���ķ��༰����
//����
//    ���ղ�������    �޲ι��죨Ĭ�Ϲ��죩 �� �вι���
//    �������ͷ���    ��ͨ���� �� ��������
class Person{
public:
    //���캯��
    Person(){
        cout<<"Person �޲ι��캯���ĵ���"<<endl;
    }
    Person(int a){
        age = a;//��ʼ��
        cout<<"Person �вι��캯���ĵ���"<<endl;
    }
//    �������캯��
    Person(const Person &p){
//        ������������ϵ��������ԣ�������������
        age = p.age;
        cout<<"Person �������캯���ĵ���"<<endl;
    }
    ~Person(){
        cout<<"Person ���������ĵ���"<<endl;
    }

    int age;
};


//����
void test01(){
//    1.���ŷ�     ��ʦϲ������
//    Person p1;//Ĭ�Ϲ��캯���ĵ���
//    Person p2(10);//�вι��캯��
//    Person p3(p2);  //�������캯��

//    ע������
//    ����Ĭ�Ϲ��캯����ʱ�򣬲�Ҫ�ӣ���С����
//    ��Ϊ�������д��룬����������Ϊ��һ������������,������Ϊ�ڴ�������
//    Person p1();//û���κ����

//    cout<<"p2������Ϊ��"<<p2.age<<endl;
//    cout<<"p3������Ϊ��"<<p3.age<<endl;


//    2.��ʾ��  ����
//    Person p1;  //Ĭ�Ϲ��캯��
//    Person p2 = Person(10); //�вι���
//    Person p3 = Person(p2); //��������

//    �ص㣺��ǰ��ִ�н�����ϵͳ���������յ���������
//    Person(10); //�������������   vector�����������õ���
//    cout<<"aaaaa"<<endl;

//    ע������2
//    ��Ҫ���ÿ������캯��  ��ʼ����������
//    ����������ΪPerson(p3) === Person p3; ��������
//                  ����С����
//    Person(p3); //ֱ�ӱ���


//    3.��ʽת����
    Person p4 = 10; //Person p4 = Person(10);   �вι���
    Person p5 = p4; //Person p5 = Person(p4);   ��������
}


int main(){

    test01();

    cout<<"HelloWorld1"<<endl;
    return 0;
}
