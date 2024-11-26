//
// Created by tianya on 2024/11/6.
//
#include "iostream"
using namespace std;


//02函数模板基本语法
//除了数据类型不一样，其他都一样
//两个整型交换的函数
void swapInt(int &a,int &b){
//void swapInt(int a,int b){//不加 & 不行
    int temp = a;
    a = b;
    b = temp;
}

//交换两个浮点型函数
void swapDouble(double &a,double &b){
    double temp = a;
    a = b;
    b = temp;
}

//函数模板
// 声明一个模板，告诉编译器后面代码中紧跟着的 T 不要报错，
// T 是一个通用的数据类型
//模板其实就是将 类型 参数化
template<typename T>
void mySwap(T &a,T &b){
    T temp = a;
    a = b;
    b = temp;
}

void test01(){
    int a = 10;
    int b = 20;

//    swapInt(a,b);//注释掉
    //利用函数模板交换
//    两种方式使用函数模板
//    1、自动类型推导  根据传入的参数数据类型 推导 函数模板的数据类型
//    mySwap(a,b);
//    2、显示指定类型
    mySwap<int>(a,b);
    cout<<"a = "<<a<<" b = "<<b<<endl;

    double c = 1.1;
    double d = 2.2;
    swapDouble(c,d);
    cout<<"c = "<<c<<" d = "<<d<<endl;
}
int main(){
    test01();
//    int x,y;
//    x = 1;
//    y = 2;
//    cout<<"x = "<<x<<" y = "<<y<<endl;
//    swapInt(x,y);
//    cout<<"x = "<<x<<" y = "<<y<<endl;
    cout<<"HelloWorld"<<endl;
return 0;
}
