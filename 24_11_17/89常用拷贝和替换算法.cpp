//
// Created by tianya on 2024/11/21.
//
#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"//��׼�㷨ͷ�ļ�

//5.4���ÿ������滻�㷨

//�㷨��飺
//.copy              //������ָ����Χ��Ԫ�ؿ�������һ������
//��replace           //��������ָ����Χ�ľ�Ԫ���޸�Ϊ��Ԫ��
//��replace_if        //������ָ����Χ����������Ԫ���滻Ϊ��Ԫ��
//��swap              //��������������Ԫ��

//�ײ�ʵ����foѭ��+ָ���ƶ�+��ֵ����

void myPrint(int val){
    cout<<val<<" ";
}

void test01(){
    vector<int>v1;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }

    //    ��ӡv1
    cout<<"v1��"<<endl;
    for_each(v1.begin(),v1.end(), myPrint);
    cout<<endl;

//    �����㷨  ʵ�ʿ���������� ���򵥵ĸ�ֵ���� ����ֱ��ʹ��
    vector<int>v2;
    v2.resize(v1.size());
    copy(v1.begin(),v1.end(),v2.begin());

    //    ��ӡv2
    cout<<"������v2��"<<endl;
    for_each(v2.begin(),v2.end(), myPrint);
    cout<<endl;
}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
