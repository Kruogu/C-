//
// Created by tianya on 2024/7/29.
//
#include "iostream"
using namespace std;

class C1{
    int m_A; //Ĭ��Ȩ����˽��
};

struct C2{
    int m_A; //Ĭ��Ȩ���ǹ���
};


int main(){
    //structi��class����
    //��structĬ��Ȩ��Ϊ����  ����public
    //��classĬ��Ȩ��Ϊ˽��  ˽��private
    C1 c1;
    c1.m_A = 100;//����˽��Ȩ��
//    ��class��Ĭ��Ȩ��˽�У�������ⲻ���Է���

    C2 c2;
    c2.m_A = 100;//����������Ȩ��
//    ��structĬ�ϵ�Ȩ��Ϊ��������˿��Է���

    cout<<"HelloWorld"<<endl;
    return 0;
}
