//
// Created by tianya on 2024/11/19.
//
#include "iostream"
using namespace std;
//3.8.7pair���鴴��

//pair<type,type> p (value1,value2 );
//pair<type,type> p = make_pair(value1,value2);


void test01(){
//    pair��ģ����
//    ��һ�ַ�ʽ
    pair<string ,int>p("Tom",20);
    cout<<"������"<<p.first<<" "
        <<" ���䣺"<<p.second<<endl;

//    �ڶ��ַ�ʽ  ��ʦϲ������ make_pair�����飩�Ƚ����׼���
    pair<string ,int>p2 = make_pair("Jerry",30);
    cout<<"������"<<p2.first<<" "
        <<" ���䣺"<<p2.second<<endl;
}

int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
