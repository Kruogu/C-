//
// Created by tianya on 2024/9/10.
//
#include "iostream"
using namespace std;

//��Ա���� �� ��Ա���� �Ƿֿ��洢��

class Person{
     int m_A;//�Ǿ�̬��Ա������������Ķ�����

     static int m_B;//��̬��Ա��������������Ķ����� ����4

     void func(){}//�Ǿ�̬��Ա��������������Ķ�����  ����4

     static void func2(){}//��̬��Ա��������������Ķ�����  ����4
};
int Person::m_B = 0;//��ʼ����̬����

void test01(){
    Person p;
//    �ն���ռ���ڴ�ռ�Ϊ��1���ֽ�
//    C++���������ÿ���ն���Ҳ����һ���ֽڿռ䣬Ϊ�����ֿն���ռ�ڴ��λ��
//    ÿ���ն���ҲӦ����һ����һ�޶����ڴ��ַ
    cout<<"size of p = "<<sizeof(p)<<endl;
}
void test02(){
    Person p;
    cout<<"size of p = "<<sizeof(p)<<endl;
}
int main(){
    test01();//1���ֽ�
    test02();//���4���ֽ���
    cout<<"HelloWorld"<<endl;
    return 0;
}
