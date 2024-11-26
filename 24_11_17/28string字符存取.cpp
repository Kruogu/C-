//
// Created by tianya on 2024/11/17.
//

#include "iostream"
using namespace std;

//3.1.7 string字符存取
//string中单个字符存取方式有两种
//char& operator[](int n);    //通过[]方式取字符
//char& at(int n);            //通过at方法获取字符

void test01(){
    string str = "hello";
    cout <<"str = "<<str<<endl;

    //1、通过[]方式取字符
    for(int i=0;i<str.size();i++){
        cout<<str[i]<<" ";
    }
    cout<<endl;

    //2、通过at方法获取字符
    for(int i=0;i<str.size();i++){
        cout<<str.at(i)<<" ";
    }
    cout<<endl;

    //修改单个字符
    str[0] = 'x';
    cout <<"str = "<<str<<endl;

    str.at(1) = 'c';
    cout <<"str = "<<str<<endl;
}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
