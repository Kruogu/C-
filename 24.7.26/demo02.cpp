//
// Created by tianya on 2024/7/26.
//
#include "iostream"
using namespace std;
int main(){
//    引用基本语法
//    数据类型&别名 = 原名
    int a = 10;
//    创建引用
    int &b = a;
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
//    b = 20;
//    cout<<"a = "<<a<<endl;
//    cout<<"b = "<<b<<endl;

    int c = 20;//赋值操作，而不是更改引用            y
    b = c;
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    cout<<"c = "<<c<<endl;
    return 0;
}
