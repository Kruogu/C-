//
// Created by tianya on 2024/11/21.
//
#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"//��׼�㷨ͷ�ļ�

//5.4.2 ���ÿ������滻�㷨 replace

//����������
//����������ָ����Χ�ľ�Ԫ���޸�Ϊ��Ԫ��
//
//����ԭ�ͣ�
//�� replace(iterator beg, iterator end, oldvalue, newvalue);
//�������ھ�Ԫ���滻����Ԫ��
//beg��ʼ������
//end����������
//oldvalue1��Ԫ��
//newvalue��Ԫ��

void myPrint(int val){
    cout<<val<<" ";
}

//�º�����ӡ
class MyPrint{
public:
    void operator()(int val){
        cout<<val<<" ";
    }
};
void test01(){
    vector<int>v;

    v.push_back(20);
    v.push_back(30);
    v.push_back(50);
    v.push_back(30);
    v.push_back(40);
    v.push_back(20);
    v.push_back(10);
    v.push_back(20);

    cout<<"�滻ǰ��"<<endl;
//    for_each(v.begin(),v.end(), myPrint);
    for_each(v.begin(),v.end(), MyPrint());//�º���
    cout<<endl;

//    ��20�滻�� 2000
    replace(v.begin(),v.end(),20,2000);

    cout<<"�滻��"<<endl;
    for_each(v.begin(),v.end(), MyPrint());//�º���
    cout<<endl;
}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
