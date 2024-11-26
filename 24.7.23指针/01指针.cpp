//
// Created by tianya on 2024/7/23.
//
#include "iostream"
using namespace std;
int main(){
//    1.定义指针
//    int a = 10;
//    int b = 10;
//    int *p;
//    p = &a;
//    int *q = &b; //也可以
//    cout<<"a的地址为："<<&a<<endl;
//    cout<<"指针p为："<<p<<endl;
//    cout<<"指针p为："<<&p<<endl;

//    2、使用指针
//    可以通过解引用的方式来找到指针指向的内存
//    指针前加*代表解引用，找到指针指向的内存中的数据
//    *p = 1000;
//    cout<<"a= "<<a<<endl;
//    cout<<"*p= "<<*p<<endl;

//    指针所占内存空间
    cout<<"sizeof(int*)="<<sizeof(int*)<<endl;//64位
    cout<<"sizeof(float*)="<<sizeof(float*)<<endl;//64位
    cout<<"sizeof(ouble*)="<<sizeof(double *)<<endl;//64位
    cout<<"sizeof(char*)="<<sizeof(char *)<<endl;//64位


//    1、空指针用于给指针变量进行初始化
//    int *p = NULL;
//    2、空指针是不可以进行访问的
//    0~255之间的内存编号是系统占用的，因此不可以访问
//    *p=100;


//    野指针
//    在程序中，尽量避免出现野指针
//    int *p = (int *)0x1100;
//    cout<<*p<<endl;

//    1.const修饰指针-指针常量
//    特点：指针的指向可以修改，但是指针指向的值不可以改
    int a = 10;
    int b = 10;
//    int * p = &a;
//    const int *p = &a;
//    *p = 20;    //错误，指针指向的值不可以改
//    p = &b;     //正确，指针指向可以改

//    2.const修饰常量-常量指针
//    特点：指针的指向不可以改，指针指向的值可以改
//    int * const p = &a;
//    *p = 20;    //正确，指向的值可以改
//    p = &b; //错误，指针指向不可以改

//    3.const即修饰指针，又修饰常量
//    特点：指针的指向和指针指向的值都不可以改
//    const int * const p = &a;
//    *p = 20;    //错误，指向的值不可以改
//    p = &b; //错误，指针指向不可以改
    cout<<"HelloWorld哈哈"<<endl;
    return 0;
}
