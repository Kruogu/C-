//
// Created by tianya on 2024/11/19.
//
#include "iostream"
using namespace std;
#include "set"
//3.8.5set���� ���Һ�ͳ��

//find(key);   //����key�Ƿ���ڣ������ڣ����ظü���Ԫ�صĵ�������
//                             �������ڣ�����set.end();

//count(key);  //ͳ��key��Ԫ�ظ��� (0����1)

void printSet(set<int> &s){
    for(set<int>::iterator it = s.begin();it!=s.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

//    ����
void test01(){
    set<int>s1;

//    �������� ֻ��insert��ʽ
    s1.insert(10);
    s1.insert(40);
    s1.insert(30);
    s1.insert(20);
    s1.insert(30);

//    ��������
//    set�����ص㣺����Ԫ�ز���ʱ���Զ�������
//    set��������������ظ�ֵ,���˰ײ壬����ʾ
    printSet(s1);//�������������  10 20 30 40

//    ����
    set<int>::iterator pos = s1.find(30);//pos  ������λ��
//    set<int>::iterator pos = s1.find(300);//pos  δ�ҵ�

    //    �ж��Ƿ�Ϊ��
    if(pos != s1.end()){
        cout<<"�ҵ�Ԫ�أ�"<<*pos<<endl;
    } else{
        cout<<"δ�ҵ�Ԫ��"<<endl;
    }
}

//ͳ��
void test02(){
    set<int>s1;

//    �������� ֻ��insert��ʽ
    s1.insert(10);
    s1.insert(40);
    s1.insert(30);
    s1.insert(20);
    s1.insert(30);

//    ͳ��30�ĸ���
//    ����set����   ͳ�ƽ��Ҫô��0  Ҫô��1
    int num1 = s1.count(30);//�����м�������һ��
    cout<<"num1 = "<<num1<<endl;//num = 1

    int num2 = s1.count(50);//û��
    cout<<"num2 = "<<num2<<endl;//num = 0
}

int main(){
    test01();
    test02();
    cout<<"HelloWorld"<<endl;
    return 0;
}
