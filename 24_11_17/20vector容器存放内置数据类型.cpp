//
// Created by tianya on 2024/11/17.
//
#pragma once
#include "iostream"
using namespace std;
#include "vector"//������ͷ�ļ�
#include "algorithm"//��׼�㷨ͷ�ļ�
//2.5.1 vector�������������������

void myPrint(int val){
    cout<<val<<endl;
}

void test01(){
//    MyArray<int> v;//֮ǰ�Լ�д��ģ��

//    ������һ��vector����������
    vector<int> v;

//    �������в�������  β�巨
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

//    ͨ�����������������е�����
//    vector<int>::iterator itBegin = v.begin();//��ʼ������  ָ�������е�һ��Ԫ��
//    vector<int>::iterator itEnd= v.end();//����������  ָ�����������һ��Ԫ�ص���һ��λ��
//
//    //��һ�ֱ�����ʽ
//    while (itBegin!=itEnd){
//        cout<<*itBegin<<endl;//
//        itBegin++;
//    }

//    �ڶ��ֱ�����ʽ  ����
//    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
//        cout<<*it<<endl;//
//    }

//    �����ֱ�����ʽ  ����STL�ṩ�����㷨
//    ͷ�ļ�,���,�յ㣬�������������ص���
    for_each(v.begin(),v.end(), myPrint);//���㷨ͷ�ļ�

}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
