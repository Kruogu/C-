//
// Created by tianya on 2024/11/21.
//
#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"//��׼�㷨ͷ�ļ�

//5.4.4 ���ÿ������滻�㷨 swap

//����������
//    ����������������Ԫ��
//
//����ԭ�ͣ�
//    �� swap(container c1, container c2);
//    ��������������Ԫ��
//    c1����1
//    c2����2

//ν��
class Greater30{
public:
    bool operator()(int val){
        return val>=30;
    }
};
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
    vector<int>v1;
    vector<int>v2;

    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
        v2.push_back(i+100);
    }

    cout<<"����ǰ��"<<endl;
//    for_each(v1.begin(),v1.end(), myPrint);
    for_each(v1.begin(),v1.end(), MyPrint());//�º���
    cout<<endl;
    for_each(v2.begin(),v2.end(), MyPrint());//�º���
    cout<<endl;

    swap(v1,v2);

    cout<<"��������������������������������"<<endl;
    cout<<"������"<<endl;
    for_each(v1.begin(),v1.end(), MyPrint());//�º���
    cout<<endl;
    for_each(v2.begin(),v2.end(), MyPrint());//�º���
    cout<<endl;

}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
