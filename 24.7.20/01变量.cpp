//
// Created by tianya on 2024/7/20.
#include <iostream>
using namespace std;
#include "01变量.h"
#define day 7
int main() {
    std::cout << "Hello, World!" << std::endl;
//  变量  数据类型+变量名=变量初始值
    int a = 10;
    cout<<"a="<<a<<endl;
//    int day = 14;  //day是常量，不能修改
    cout<<"一周共有"<<day<<"天"<<endl;
    cout<<"一周共有\\"<<day<<"天"<<endl;
    cout<<"一周共有"<<day<<"天\n";
    cout<<"一周共有\\"<<day<<"天"<<endl;

//    2.const修饰的变量
    int month =12;
//    const int month =12;
    month = 24; //错误，const修饰的变量也称为常量，

    return 0;
}
