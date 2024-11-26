//
// Created by tianya on 2024/11/21.
//
#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"//标准算法头文件
#include "functional"//greater
#include "ctime"

//5.3.3 常用排序算法 merge

//· merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
//容器元素合并，并存储到另一容器中
//注意：两个容器必须是 有序的

//beg1容器1开始迭代器
//end1容器1结束迭代器
//beg2容器2开始达代器
//end2容器2结束迭代器
//dest 目标容器开始迭代器


void myPrint(int val){
    cout<<val<<" ";
}
void test01(){
    vector<int>v1;
    vector<int>v2;

    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
        v2.push_back(i+1);
    }
    //    打印v1
    for_each(v1.begin(),v1.end(), myPrint);
    cout<<endl;

    //    打印v2
    for_each(v2.begin(),v2.end(), myPrint);
    cout<<endl;

//    目标容器
    vector<int>vTarget;

    //提前给目标容器分配空间
    vTarget.resize(v1.size()+v2.size());

//    自动排好序  合并有序序列
    merge(v1.begin(),v1.end(),v2.begin(),v2.end(),vTarget.begin());
//    打印vTarget
    for_each(vTarget.begin(),vTarget.end(), myPrint);
    cout<<endl;

}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
