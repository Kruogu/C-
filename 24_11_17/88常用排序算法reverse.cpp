//
// Created by tianya on 2024/11/21.
//
#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"//��׼�㷨ͷ�ļ�
#include "functional"//greater
#include "ctime"

//5.3.4 ���������㷨 reverse

//����������
//����������Ԫ�ؽ��з�ת
//
//����ԭ�ͣ�
//�� reverse(iterator beg, iterator end);
//��תָ����Χ��Ԫ��
//beg��ʼ������
//end����������

void myPrint(int val){
    cout<<val<<" ";
}
void test01(){
    vector<int>v;

    v.push_back(10);
    v.push_back(40);
    v.push_back(30);
    v.push_back(40);
    v.push_back(20);

//    ��ӡv
    cout<<"��תǰ��"<<endl;
    for_each(v.begin(),v.end(), myPrint);
    cout<<endl;


    cout<<"��ת��"<<endl;
    reverse(v.begin(),v.end());
    for_each(v.begin(),v.end(), myPrint);
    cout<<endl;
}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}

