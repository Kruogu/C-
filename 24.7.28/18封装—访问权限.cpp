//
// Created by tianya on 2024/7/29.
//
#include "iostream"
using namespace std;

//����Ȩ�������֣�
//1.public      ����Ȩ��    ��Ա ���ڿ��Է���,������Է���
//2.protected   ����Ȩ��    ��Ա ���ڿ��Է���,���ⲻ���Է���  ���ӿ��Է��ʸ��׵�˽������
//3.private     ˽��Ȩ��    ��Ա ���ڿ��Է���,���ⲻ���Է���  ���Ӳ����Է��ʸ��׵�˽������

class Person{

public://����Ȩ��
    string m_Name;  //����

protected://����Ȩ��
    string m_Car;   //����

private://˽��Ȩ��
    int m_Password; //���п�����

public:
//private://���⺯�����ʲ�����
    void func(){
        m_Name = "����";
        m_Car = "������";
        m_Password = 123456;
    }

};

int main(){

    //ʵ�����������
    Person p1;

    p1.m_Name = "����";
//    p1.m_Car = "�γ�";    //��������Ȩ�����ݣ���������ʲ���
//    p1.m_Password = "123123"; //����˽��Ȩ�����ݣ���������ʲ���
    p1.func();
    cout<<p1.m_Name<<endl;
//    cout<<p1.m_Car<<endl;
//    cout<<p1.m_Password<<endl;
    cout<<"HelloWorld"<<endl;
    return 0;
}
