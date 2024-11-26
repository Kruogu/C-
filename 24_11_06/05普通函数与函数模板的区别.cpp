//
// Created by tianya on 2024/11/8.
//

#include "iostream"
using namespace std;

//1.2.4普通函数与函数模板的区别

//1、普通函数调用时可以发生隐式类型转换（自动类型转换）
//2、函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
//3、如果利用显示指定类型的方式，可以发生隐式类型转换

//普通函数
int myAdd(int a,int b){
    return a+b;
}

//函数模板
template<class T>
T myAdd02(T a,T b){
    return a+b;
}

void test01(){
    int a = 10;
    int b = 20;
    char c = 'c';//ASCII  99
//    cout<<myAdd(a,b)<<endl;//正常
//    cout<<myAdd(a,c)<<endl;

//    自动类型推导   不会发生隐式类型转换
    myAdd02(a,b);//正常
//    cout<<myAdd02(a,b)<<endl;//正常
//    cout<<myAdd02(a,c)<<endl;//不能运行  正常

    //显示指定类型   会发生隐式类型转换
    myAdd02<int>(a,c);//正常  109
    cout<<myAdd02<int>(a,c)<<endl;//正常  109
}

int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
