//
// Created by tianya on 2024/11/21.
//
#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"//��׼�㷨ͷ�ļ�
#include "functional"//greater

//5.3.1 ���������㷨 sort

//��sort(iterator beg,iterator end,_Pred);
//��ֵ����Ԫ�أ��ҵ�����ָ��λ�õ��������Ҳ������ؽ���������λ��
//beg��ʼ������

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

    //����sort��������
    sort(v.begin(),v.end());

//    ��ӡ��� ���� ����
    for_each(v.begin(),v.end(), myPrint);
    cout<<endl;

//    for(vector<int>::iterator it = v.begin();it!=v.end();it++){
//        cout<<*it<<" ";
//    }
//    cout<<endl;

//    ����
    sort(v.begin(),v.end(),greater<int>());//ֱ�Ӹı�������˳��
    for_each(v.begin(),v.end(), myPrint);
    cout<<endl;

    sort(v.begin(),v.end());
    for_each(v.rbegin(),v.rend(), myPrint);//�����ӡ��������û��
    cout<<endl;
}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
