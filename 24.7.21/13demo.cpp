//
// Created by tianya on 2024/7/21.
//
#include "13demo.h"
#include <iostream>
#include <iomanip>
//#include "stdlib.h"
//#include "time.h"
#include<ctime>//这个time也行

using namespace std;
int main(){
//    1.C语言风格
    char str[] ="HelloWorld哈哈哈";
    cout<<str<<endl;

//    2.C++语言风格
    string str1 = "Hello嘿嘿嘿";
    cout<<str1<<endl;

//    cin输入
//    int a = 0;
//    cout<<"请给整型变量a赋值："<<endl;
//    cin>>a;
//    cout<<"a="<<a<<endl;

//    float f = 0;
//    cout<<"请给浮点型变量f赋值："<<endl;
//    cin>>f;
//    cout<<"f="<<f<<endl;

//    char ch = 'a';
//    cout<<"请给字符型变量ch赋值："<<endl;
//    cin>>ch;
//    cout<<"ch="<<ch<<endl;

//    string str2 = "Hello";
//    cout<<"请给字符串str型变量赋值："<<endl;
//    cin>>str2;
//    cout<<"str="<<str2<<endl;

//    bool flag = true;
//    cout<<"请给布尔类型flag变量赋值："<<endl;
//    cin>>flag;
//    cout<<"flag="<<flag<<endl;

//    四则运算
//    int a3=10,b3=0;
//    cout<<"结果为："<<a3/b3<<endl;//不出结果

//    小数运算
//    int d = 2;
//    double d1=0.5,d2=0.22;
//    cout<<"结果为："<<d1/d2<<endl;
//    cout<<setprecision(2)<<d1/d2<<endl;//四舍五入
//    cout<<fixed<<setprecision(2)<<d1/d2<<endl;//保留两位小数

//    前置递增
    int a = 10;
    ++a;
    cout<<"a="<<a<<endl;

//    后置递增
    int b = 10;
    b++;
    cout<<"b="<<b<<endl;

    //3、前置和后置的区别
//前置递增先让变量+1然后进行表达式运算
    int a2 = 10;
    int b2 = ++a2*10;
    cout<<"a2="<<a2<<endl;
    cout<<"b2="<<b2<<endl;

//    后置递增先进行表达式运算，后让变量+1
    int a3 = 10;
    int b3 = a3++*10;
    cout<<"a3="<<a3<<endl;
    cout<<"b3="<<b3<<endl;

    srand((unsigned int)time(NULL));
//    srand(time(0));  // 随机数相关
    int m = rand()%100+1;  //生成随机数  加1可以避免 0
    cout<<"m="<<m<<endl;

    int num = rand()%100 +1;
    cout<<"num="<<num<<endl;

    cout<<endl;//换行

    int num2 = rand()%100 +1;
    cout<<"num2="<<num2<<endl;


//    数组名
//    int arr[10]={1,2,3,4,5,6,7,8,9,10};
////    cout<<"数组首地址为："<<arr<<endl;
////    用int不行，精度丢书，可以用long long
//    cout<<"数组首地址为："<<(long long )arr<<endl;
//    cout<<"数组首地址为："<<(long long )&arr[0]<<endl;
////    第二个元素地址差4位
//    cout<<"数组首地址为："<<(long long )&arr[1]<<endl;


//    二维数组
    int arr[2][3]={
            {1,2,3},
            {4,5,6}
    };
    cout<<"二维数组占用内存空间为："<<sizeof(arr)<<endl;
    cout<<"二维数组第一行占用内存为："<<sizeof(arr[0])<<endl;
    cout<<"二维数组第一列占用内存为："<<sizeof(arr[1][0])<<endl;//不能
    cout<<"二维数组第一个元素占用内存为："<<sizeof(arr[0][0])<<endl;

    return 0;
}



