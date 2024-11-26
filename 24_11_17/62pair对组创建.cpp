//
// Created by tianya on 2024/11/19.
//
#include "iostream"
using namespace std;
//3.8.7pair对组创建

//pair<type,type> p (value1,value2 );
//pair<type,type> p = make_pair(value1,value2);


void test01(){
//    pair是模板类
//    第一种方式
    pair<string ,int>p("Tom",20);
    cout<<"姓名："<<p.first<<" "
        <<" 年龄："<<p.second<<endl;

//    第二种方式  老师喜欢这种 make_pair（对组）比较容易记忆
    pair<string ,int>p2 = make_pair("Jerry",30);
    cout<<"姓名："<<p2.first<<" "
        <<" 年龄："<<p2.second<<endl;
}

int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
