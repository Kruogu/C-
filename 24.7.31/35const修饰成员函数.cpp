//
// Created by tianya on 2024/9/18.
//

#include "iostream"
using namespace std;

//const���γ�Ա����
//������
class Person{
public:
//    Person(){}//��ʼ��pֵ
    //thisָ��ı���  ��ָ�볣��  ָ���ָ���ǲ������޸ĵ�  ֵ�����޸�
    // const Person *const this;��һ��const�൱�� 15������
//    �ڳ�Ա���������const�����ε���thisָ����ָ��ָ���ֵҲ�������޸�
//    void showPerson()
    void showPerson() const//���ϾͲ����޸�ֵ��
    {
//        m_A = 100;//�����޸�ֵ
//        this->m_A = 100;//ͬ��һ��
//        this = NULL;//thisָ���ǲ������޸�ָ���ָ���
        this->m_B = 10;
    }
    void func()//����const�Ͳ�������ã������޸�ֵ
    {
        m_A = 100;
    }
    int m_A;
    mutable int m_B;//�����������ʹ�ڳ������У�Ҳ�����޸����ֵ,�ӹؼ���mutable
};

void test01(){
    Person p;
    p.showPerson();
    cout<<"m_A:"<<p.m_A<<endl;
    cout<<"m_B:"<<p.m_B<<endl;
}

//������
void test02(){
//    const Person p;//ԭ��  ����
    const Person p{};
//    p.m_A = 100;//���� �����޸�  �ڶ���ǰ��const,��Ϊ������
    p.m_B = 200;//�����޸�  m_B������ֵ���ڳ�������Ҳ�����޸�
    cout<<"m_B:"<<p.m_B<<endl;

//    ������ֻ�ܵ��ó�����
    p.showPerson();
//    p.func();//���� ���ǳ�����  �����󲻿��Ե�����ͨ��Ա��������Ϊ��ͨ��Ա���������޸�����
}
int main(){
    test01();
    test02();
    cout<<"HelloWorld"<<endl;
    return 0;
}

