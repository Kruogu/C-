//
// Created by tianya on 2024/7/28.
//
#include "iostream"
using namespace std;

//函数重载
//可以让函数名相同，提高复用性

//函数重载满足条件：
//    1.同一个作用域下
//    2.函数名称相同
//    3.函数参数类型不同或者个数不同或者顺序不同


void func(){
    cout<<"func的调用1"<<endl;
}

void func(int a){
    cout<<"func的调用2"<<endl;
}

//类型不同
void func(double a){
    cout<<"func的调用3"<<endl;
}

//顺序不同
void func(int a,double b){
    cout<<"func的调用4"<<endl;
}
void func(double b,int a){
    cout<<"func的调用5"<<endl;
}

//注意事项
//注意：函数的返回值不可以作为函数重载的条件
//int func(double b,int a){  //改成 int 的就报错
//    cout<<"func的调用5"<<endl;
//}
int main(){
    func();
    func(10);
    func(1.0);
    func(9,1.0);
    func(1.1,9);
//    func(1.1,9);
    cout<<"HelloWorld"<<endl;
    return 0;
}
