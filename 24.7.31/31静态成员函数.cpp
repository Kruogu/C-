//
// Created by tianya on 2024/9/9.
//
#include "iostream"
using namespace std;

//��̬��Ա����
//���ж�����ͬһ������
//��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����
class Person{
public:
//    ��̬��Ա����
    static void func(){
        m_A = 100;//��̬��Ա�������Է��ʾ�̬��Ա����,��ҹ�������Ҫ����
//        m_B = 200;//������̬��Ա���������Է��ʷǾ�̬��Ա�������޷����ֵ������ĸ������m_B����
        cout<<"static void func����"<<endl;
    }

    static int m_A;//��̬��Ա����
    int m_B; //�Ǿ�̬��Ա����

//    ��̬��Ա����Ҳ���з���Ȩ�޵�
private:
    static void func2(){
        cout<<"static void func2����"<<endl;
    }
};

//��̬��Ա�������������������ʼ��
int Person::m_A = 0;



//�����ַ��ʷ�ʽ
void test01(){
//    1.ͨ��������з���
    Person p;
    p.func();

//    2.ͨ����������
    Person::func();

//    Person::func2();//�����޷����� ˽�� ��̬��Ա����
}

int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
