//
// Created by tianya on 2024/9/9.
//
#include "iostream"
using namespace std;

//��̬��Ա����
class Person{
public:
//    1.���ж��󶼹���ͬһ������
//    2.����׶ξͷ������ڴ�
//    3.���������������ʼ������
    static int m_A;

//    ��̬��Ա����Ҳ���з���Ȩ�޵�
private:
    static int m_B;
};

int Person::m_A=100;  //���������������ʼ������
int Person::m_B=200;

void test01(){
    Person p;//p = 100
    cout<<p.m_A<<endl;

    Person p2;//p2 = 200
    p2.m_A = 200;
    cout<<p2.m_A<<endl;

    cout<<p.m_A<<endl;//p = 200
}
void test02(){
//    ��̬��Ա����������ĳ�������ϣ����ж�����ͬһ������
//    ��˾�̬��Ա���������ַ��ʷ�ʽ
//    1.ͨ��������з���
//    Person p;
//    cout<<p.m_A<<endl;

//    2.ͨ���������з���
//    Ҳ���Բ��ô�������ֱ�ӵ���Person�������µ�m_A���
//    �Ǿ�̬��Ա�������봴��������ܶ�д����̬����ֱ�ӷ���
    cout<<Person::m_A<<endl;

//    cout<<Person::m_B<<endl;//˽��Ȩ�ޣ������Է���
//    ������ʲ���˽�еľ�̬��Ա����
}
int main(){
//    test01();
    test02();
    cout<<"HelloWorld12"<<endl;
    return 0;
}
