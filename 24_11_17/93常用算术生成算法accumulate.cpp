//
// Created by tianya on 2024/11/21.
//

#include "iostream"
using namespace std;
#include "vector"
#include"numeric"  //�㷨��
//5.5.1 �������������㷨 accumulate

//accumulate   ��������Ԫ���ۼ��ܺ�   ����
//fill         �����������Ԫ��      ����

//����������
//    ����������������Ԫ���ۼ��ܺ�
//
//����ԭ�ͣ�
//    �� accumulate(iterator beg, iterator end, value);
//    ��������Ԫ���ۼ��ܺ�
//    beg��ʼ������
//    end����������
//    value��ʼֵ    ����3  ��ʼ���ۼ�ֵ


void test01(){
    vector<int>v;
    for (int i = 0; i <= 100; ++i) {
        v.push_back(i);
    }

//    ����3  ��ʼ���ۼ�ֵ
    int total = accumulate(v.begin(),v.end(),0);//total = 5050
//    int total = accumulate(v.begin(),v.end(),1000);//total = 6050
    cout<<"total = "<<total<<endl;
}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
