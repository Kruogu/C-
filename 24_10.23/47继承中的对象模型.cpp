//
// Created by tianya on 2024/10/24.
//

//���ÿ�����Ա������ʾ���߲鿴����ģ��

//E:\0Work\0workspace\24_10.23
//E:\0Work\0workspace\24_10.23\47�̳��еĶ���ģ��.cpp
//1.CLion���Ը���·���ģ�Ȼ����win+R������cmd��������  �����в���
//1. �������������������� vs  �ù���Ա��ݴ�x64 Native Tools Command Prompt for VS 2022��������ʹ��
//2.����ת��E�̣� E:
//3.���� cd E:\0Work\0workspace\24_10.23
//4.�鿴Ŀ¼  dir
//5.  ���� cl /d1 reportSingleClassLayout + Ҫ�鿴���� �ո� ����47��Tab�� �����Զ���ȫ   //���� ���� ��� ����
//5.   cl /d1 reportSingleClassLayoutSon 47�̳��еĶ���ģ��.cpp


#include "iostream"
using namespace std;

//�̳��еĶ���ģ��

class Base{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};

class Son:public Base{
public:
    int m_D;
};

void test01(){
//     4 12 16   // ����� 16  ˵��˽������Ҳ�̳���
//    ���������зǾ�̬��Ա���Զ��ᱻ����̳���ȥ
//    ������˽�г�Ա�����Ǳ��������������ˣ�����Ƿ��ʲ���������ȷʵ���̳���ȥ��
    cout<<"size of Son = "<<sizeof(Son)<<endl;
}


int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
