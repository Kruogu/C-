//
// Created by tianya on 2024/11/19.
//
#include "iostream"
using namespace std;
#include "stack"

//3.5.2stack容器常用接口

void test01(){
//    特点：符合先进后出数据结构
    stack<int>s;

//    入栈
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout<<"栈的大小为："<<s.size()<<endl;
//    只要栈不为空，就查看栈顶，并且执行出栈操作  不能遍历
    while (!s.empty()){
//        查看栈顶元素
        cout<<"栈顶元素为："<<s.top()<<endl;

//        出栈
        s.pop();
    }
    cout<<"栈的大小为："<<s.size()<<endl;

}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
