//
// Created by tianya on 2024/11/19.
//
#include "list"

#include "iostream"
using namespace std;

//3.7.6list���� ���ݴ�ȡ

//front();   //���ص�һ��Ԫ�ء�
//back();    //�������һ��Ԫ�ء�

void test01(){
//    ����list����
    list<int>L1; //Ĭ�Ϲ���

//    �������  β��
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);

//    L1[0]     //��������[]����1ist�����е�Ԫ��
//    L1.at(0)  //��������at��ʽ����1ist�����е�Ԫ��
//    ԭ����1ist���������������������Կռ�洢����,������Ҳ�ǲ�֧��������ʵ�

//    ��ȡ��һ��Ԫ��
    cout<<"��һ��Ԫ��Ϊ��"<<L1.front()<<endl;
//    ��ȡ���һ��Ԫ��
    cout<<"���һ��Ԫ��Ϊ��"<<L1.back()<<endl;

//    ��֤�������ǲ�֧�ַ��ʵ�
    list<int>::iterator it = L1.begin();
    it++;//��������  ֧��˫��  ��ǰ��
//    it--;//��������
//    it = it+1;//������  ��֧���������
}


int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}

