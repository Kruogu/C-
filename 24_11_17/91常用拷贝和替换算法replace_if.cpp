//
// Created by tianya on 2024/11/21.
//
#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"//��׼�㷨ͷ�ļ�

//5.4.3 ���ÿ������滻�㷨 replace_if

//����������
    //��������������������Ԫ�أ��滻��ָ��Ԫ��
//
//-����ԭ�ͣ�
    //��replace_if(iterator beg,iterator end,_pred,newvalue);
    //�������滻Ԫ�أ������������滻��ָ��Ԫ��
    //beg��ʼ������
    //end����������
    //_pred ν��
    //newvalue�滻����Ԫ��

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

//    ���ڵ���30 �滻�� 3000
    replace_if(v.begin(),v.end(),Greater30(),3000);

    cout<<"�滻��"<<endl;
    for_each(v.begin(),v.end(), MyPrint());//�º���
    cout<<endl;
}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
