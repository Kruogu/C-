//
// Created by tianya on 2024/11/21.
//
#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"//��׼�㷨ͷ�ļ�
#include "functional"//greater
#include "ctime"

//5.3.3 ���������㷨 merge

//�� merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
//����Ԫ�غϲ������洢����һ������
//ע�⣺�������������� �����

//beg1����1��ʼ������
//end1����1����������
//beg2����2��ʼ�����
//end2����2����������
//dest Ŀ��������ʼ������


void myPrint(int val){
    cout<<val<<" ";
}
void test01(){
    vector<int>v1;
    vector<int>v2;

    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
        v2.push_back(i+1);
    }
    //    ��ӡv1
    for_each(v1.begin(),v1.end(), myPrint);
    cout<<endl;

    //    ��ӡv2
    for_each(v2.begin(),v2.end(), myPrint);
    cout<<endl;

//    Ŀ������
    vector<int>vTarget;

    //��ǰ��Ŀ����������ռ�
    vTarget.resize(v1.size()+v2.size());

//    �Զ��ź���  �ϲ���������
    merge(v1.begin(),v1.end(),v2.begin(),v2.end(),vTarget.begin());
//    ��ӡvTarget
    for_each(vTarget.begin(),vTarget.end(), myPrint);
    cout<<endl;

}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
