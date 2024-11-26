//
// Created by tianya on 2024/11/17.
//
#pragma once
#include "iostream"
using namespace std;
#include "vector"//迭代器头文件
#include "algorithm"//标准算法头文件
//2.5.1 vector容器存放内置数据类型

void myPrint(int val){
    cout<<val<<endl;
}

void test01(){
//    MyArray<int> v;//之前自己写的模板

//    创建了一个vector容器，数组
    vector<int> v;

//    向容器中插入数据  尾插法
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

//    通过迭代器访问容器中的数据
//    vector<int>::iterator itBegin = v.begin();//起始迭代器  指向容器中第一个元素
//    vector<int>::iterator itEnd= v.end();//结束迭代器  指向容器中最后一个元素的下一个位置
//
//    //第一种遍历方式
//    while (itBegin!=itEnd){
//        cout<<*itBegin<<endl;//
//        itBegin++;
//    }

//    第二种遍历方式  常用
//    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
//        cout<<*it<<endl;//
//    }

//    第三种遍历方式  利用STL提供遍历算法
//    头文件,起点,终点，函数名（函数回调）
    for_each(v.begin(),v.end(), myPrint);//加算法头文件

}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
