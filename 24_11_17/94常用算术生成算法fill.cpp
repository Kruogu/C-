//
// Created by tianya on 2024/11/21.
//

#include "iostream"
using namespace std;
#include "vector"
#include"numeric"  //�㷨��
#include "algorithm"//��׼�㷨ͷ�ļ�

//5.5.2 �������������㷨 fill

//accumulate   ��������Ԫ���ۼ��ܺ�   ����
//fill         �����������Ԫ��      ����

//����������
//    �������������ָ����Ԫ��
//
//����ԭ�ͣ�
//    �� fill(iterator beg, iterator end, value);
//    �����������Ԫ��
//    beg��ʼ������
//    end����������
//    value����ֵ

//�º�����ӡ
class MyPrint{
public:
    void operator()(int val){
        cout<<val<<" ";
    }
};

void myPrint(int val){
    cout<<val<<" ";
}

void test01(){
    vector<int>v;
    v.resize(10);//�޸Ŀռ�  �и����ذ汾��������ǰ�����

    cout<<"���ǰ��"<<endl;
    for_each(v.begin(),v.end(), myPrint);//��ͨ����
    cout<<endl;

//    �����������
    fill(v.begin(),v.end(),100);

    cout<<"����"<<endl;
    for_each(v.begin(),v.end(), MyPrint());//�º���
    cout<<endl;
}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
