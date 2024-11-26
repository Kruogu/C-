//
// Created by tianya on 2024/7/26.
//
#include "iostream"
using namespace std;

//引用做函数的返回值
//1、不要返回局部变量的引用
int& test01()
{
    int a = 10;//局部变量存放在四区中的 栈区
    return a;
}

//2、函数的调用可以作为左值
int& test02(){
    static int a = 10;//静态变量，存放在全局区，全局区上的数据在程序结束后系统释放
    return a;
}

int main(){

//    int &ref = test01();
//    cout<<"ref = "<<ref<<endl;//报错  vs2022可以出现值
//    X86环境下会给你保留一次，X64环境下一次都不会保留
//    x64返回的是野指针，x86返回的是值(VS2022)

    int &ref2 = test02();
    cout<<"ref2 = "<<ref2<<endl;//10

    //如果函数的返回值是引用，这个函数调用可以作为左值
    test02() = 1000;
    cout<<"ref2 = "<<ref2<<endl;//10


//    引用的本质  就是一个指针常量
//    int a = 10;
//    int& ref = a;
//    int* const ref = &a;//等价于上一行 指针常量是指针指向不可改，也说明为什么引用不可更改
//    ref = 20;//内部发现ref是引用，自动帮我们转换为：*ref = 20
    cout<<"HelloWorld"<<endl;
    return 0;
}