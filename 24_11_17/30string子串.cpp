//
// Created by tianya on 2024/11/17.
//


#include "iostream"
using namespace std;

//3.1.9 string�Ӵ�
//string substr(int pos=0,int n=npos)const; //������pos��ʼ��n���ַ���ɵ��ַ���

void test01(){
    string str = "abcdef";
//    ����
    string subStr = str.substr(1,3);

    cout <<"subStr = "<<subStr<<endl;
}

void test02(){
    string email = "zhangsan@sina.com";
//    string email = "lisi@sina.com";//��һ��Ҳ����

//    ���ʼ���ַ�� ��ȡ �û�����Ϣ
    int pos = email.find("@");//8  position  λ��
//    string usrName =email.substr(pos);//@sina.com   sub ��
    string usrName =email.substr(0,pos);//zhangsan
    cout <<"usrName = "<<usrName<<endl;//
}
int main(){
    test01();
    test02();
    cout<<"HelloWorld"<<endl;
    return 0;
}

