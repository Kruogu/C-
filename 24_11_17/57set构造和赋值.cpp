//
// Created by tianya on 2024/11/19.
//
#include "iostream"
using namespace std;
#include "set"
//3.8.2set����͸�ֵ

//���죺
//    set<T> st;                          //Ĭ�Ϲ��캯����
//    set(const set &st);                 //�������캯��
//
//��ֵ��
//    set& operator=(const set &st);      //���صȺŲ�����

void printSet(set<int> &s){
    for(set<int>::iterator it = s.begin();it!=s.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

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

//    ��������
    set<int>s2(s1);
    printSet(s2);//10 20 30 40

//    ��ֵ
    set<int>s3(s1);
    s3 = s2;
    printSet(s3 );//10 20 30 40

}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
