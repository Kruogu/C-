//
// Created by tianya on 2024/10/28.
//

//��vs����
//E:
//cd E:\0Work\0workspace\24_10.23
//dir
//cl /d1 reportSingleClassLayoutSheepTuo 52���μ̳�.cpp

#include "iostream"
using namespace std;

//���μ̳�


//������
class Animal{
public:
    int m_Age;
};

//������̳н�����μ̳е�����  virtual����  ����
//�̳�֮ǰ ���Ϲؼ���virtual ��Ϊ��̳�
//Animal���Ϊ �����
//vbptr Ϊ�����ָ��  ָ��   vbtable������
//        v-vIrtua
//        b base
//        ptr pointer
//����
//class Sheep:public Animal{
class Sheep:virtual public Animal{

};

//������
//class Tuo:public Animal{
class Tuo:virtual public Animal{

};

//���� ��������
class SheepTuo:public Sheep,public Tuo{

};

void test01(){
    SheepTuo st;
//    st.m_Age = 18;//��̳в���ȷ
    st.Sheep::m_Age = 18;
    st.Tuo::m_Age = 28;

//    �����μ̳У�������ӵ����ͬ���ݣ���Ҫ��������������
    cout<<"st.Sheep::m_Age��"<<st.Sheep::m_Age<<endl;
    cout<<"st.Tuo::m_Age��"<<st.Tuo::m_Age<<endl;

//    �����������֪��ֻ����һ�ݾͿ��ԣ����μ̳е������������ݣ���Դ�˷�
}

int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
