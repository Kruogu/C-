//
// Created by tianya on 2024/8/1.
//

#include "iostream"
using namespace std;

//�����ǳ����
class Person{
public:
    Person(){
        cout<<"PersonĬ�Ϲ��캯������"<<endl;

    }
    Person(int age,int height){
        cout<<"Person�вι��캯������"<<endl;
        m_Age = age;
        m_Height = new int(height);//�����ݴ���������
    }
//    Person(const Person &p){
//        cout<<"Person�������캯������"<<endl;
//        m_Age = p.m_Age;
//    }

    //�Լ�ʵ�ֿ������캯�������ǳ��������������
    Person(const Person &p){
        cout<<"Person �������캯���ĵ���"<<endl;
        m_Age = p.m_Age;
        m_Height = p.m_Height;//������Ĭ��ʵ�־������д���

//        �������
        m_Height = new int(*p.m_Height);
    }

    ~Person(){
//        �������룬�����������������ͷŲ���
//        ǳ����������������Ƕ������ڴ��ظ��ͷ�
//        ǳ����������Ҫ����������н��
        if(m_Height != NULL){
            delete m_Height;    //�ͷ��ڴ�
            m_Height = NULL;    //Ϊ�˷�ֹҰָ����֣���ֵΪ��
        }
        cout<<"Person������������"<<endl;
    }

    int m_Age;  //����
    int *m_Height;  //���
};

void test01(){
    Person p1(18,160);
    cout<<"p1������Ϊ��"<<p1.m_Age
        <<" p1�����Ϊ��"<<*p1.m_Height<<endl;

    Person p2(p1);
    cout<<"p2������Ϊ��"<<p2.m_Age
        <<" p2�����Ϊ��"<<*p2.m_Height<<endl;
}
int main(){

    test01();

    cout<<"HelloWorld"<<endl;
    return 0;
}
