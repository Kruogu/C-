//
// Created by tianya on 2024/11/18.
//
#include "iostream"
using namespace std;
#include "vector"//������ͷ�ļ�

void printVector(vector<int> &v){//����������
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

//3.2.6 vector���ݴ�ȡ

//at(int idx);     //��������idx��ָ������
//operator[];      //��������idx��ָ������
//front();         //���������е�һ������Ԫ��
//back();          //�������������һ������Ԫ��

void test01(){
    vector<int>v1;
    for(int i=0;i<10;i++){
        v1.push_back(i);//0-9
    }
//    ����[]��ʽ����������Ԫ��
    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<" ";
    }
    cout<<endl;

//    ����at��ʽ����Ԫ��
    for(int i=0;i<v1.size();i++){
        cout<<v1.at(i)<<" ";
    }
    cout<<endl;

//    ��ȡ��һ��Ԫ��
    cout<<"��һ��Ԫ��Ϊ��"<<v1.front()<<endl;
//    ��ȡ���һ��Ԫ��
    cout<<"���һ��Ԫ��Ϊ��"<<v1.back()<<endl;
}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
