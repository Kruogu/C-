//
// Created by tianya on 2024/11/17.
//


#include "iostream"
using namespace std;

//3.1.9 string子串
//string substr(int pos=0,int n=npos)const; //返回由pos开始的n个字符组成的字符串

void test01(){
    string str = "abcdef";
//    插入
    string subStr = str.substr(1,3);

    cout <<"subStr = "<<subStr<<endl;
}

void test02(){
    string email = "zhangsan@sina.com";
//    string email = "lisi@sina.com";//换一个也可以

//    从邮件地址中 获取 用户名信息
    int pos = email.find("@");//8  position  位置
//    string usrName =email.substr(pos);//@sina.com   sub 子
    string usrName =email.substr(0,pos);//zhangsan
    cout <<"usrName = "<<usrName<<endl;//
}
int main(){
    test01();
    test02();
    cout<<"HelloWorld"<<endl;
    return 0;
}

