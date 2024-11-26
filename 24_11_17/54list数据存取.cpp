//
// Created by tianya on 2024/11/19.
//
#include "list"

#include "iostream"
using namespace std;

//3.7.6list容器 数据存取

//front();   //返回第一个元素。
//back();    //返回最后一个元素。

void test01(){
//    创建list容器
    list<int>L1; //默认构造

//    添加数据  尾插
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);

//    L1[0]     //不可以用[]访问1ist容器中的元素
//    L1.at(0)  //不可以用at方式访问1ist容器中的元素
//    原因是1ist本质链表，不是用连续线性空间存储数据,迭代器也是不支持随机访问的

//    获取第一个元素
    cout<<"第一个元素为："<<L1.front()<<endl;
//    获取最后一个元素
    cout<<"最后一个元素为："<<L1.back()<<endl;

//    验证迭代器是不支持访问的
    list<int>::iterator it = L1.begin();
    it++;//这样可以  支持双向  向前走
//    it--;//这样可以
//    it = it+1;//不可以  不支持随机访问
}


int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}

