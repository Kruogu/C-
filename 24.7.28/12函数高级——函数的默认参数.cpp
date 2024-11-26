//
// Created by tianya on 2024/7/28.
//
#include "iostream"
using namespace std;

//函数的默认参数
int func1(int a,int b,int c){
    return a+b+c;
}

//如果我们自己传入数据，就用自己的数据，如果没有，那么用默认值
//语法：返回值类型函数名（形参=默认值）{ }
int func2(int a,int b=20,int c=30){
    return a+b+c;
}

//注意事项
//1、如果某个位置己经有了默认参数，那么从这个位置往后，从左到右都必须有默认值
//int func3(int a,int b=20,int c){ // c也得有参数，否则报错
int func3(int a,int b=20,int c=30){
    return a+b+c;
}

//2.如果函数声明有默认参数，函数实现就不能有默认参数
//声明和实现只能有一个有默认参数
int func4(int a,int b=10);

//int func4(int a=10,int b=20){  //报错
int func4(int a=10,int b){
    return a+b;
}

int main(){
    cout<<func1(10,20,30)<<endl;
    cout<<func2(20,30)<<endl;
    cout<<func4(10,20)<<endl;

    cout<<"HelloWorld"<<endl;
    return 0;
}
