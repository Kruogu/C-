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

//3.2.4 vector�����ʹ�С

void test01(){
    vector<int>v1;
    for(int i=0;i<10;i++){
        v1.push_back(i);//0-9
    }
    printVector(v1);

    if(v1.empty()){//Ϊ���������Ϊ��
        cout<<"v1Ϊ��"<<endl;
    } else{
        cout<<"v1��Ϊ��"<<endl;
        cout<<"v1������Ϊ��"<<v1.capacity()<<endl;
        cout<<"v1�Ĵ�СΪ��"<<v1.size()<<endl;
    }
//    ����ָ����С
    v1.resize(15);//�������ذ汾������ָ��Ĭ�����ֵ������2
    printVector(v1);//�������ָ���ı�ԭ�����ˣ�Ĭ����0����µ�λ��
    cout<<"v1���ݺ������Ϊ��"<<v1.capacity()<<endl;
    cout<<"v1���ݺ�Ĵ�СΪ��"<<v1.size()<<endl;

    //���ذ汾
    v1.resize(20,100);//��100�����
    printVector(v1);

    //��ԭ������
    v1.resize(5);//�������ָ���ı�ԭ�����ˣ��������ֻ�ɾ����
    printVector(v1);

}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
