//
// Created by tianya on 2024/11/21.
//
#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"//标准算法头文件
#include "functional"//greater
#include "ctime"

//5.3.4 常用排序算法 reverse

//功能描述：
//·将容器内元素进行反转
//
//函数原型：
//· reverse(iterator beg, iterator end);
//反转指定范围的元素
//beg开始迭代器
//end结束迭代器

void myPrint(int val){
    cout<<val<<" ";
}
void test01(){
    vector<int>v;

    v.push_back(10);
    v.push_back(40);
    v.push_back(30);
    v.push_back(40);
    v.push_back(20);

//    打印v
    cout<<"反转前："<<endl;
    for_each(v.begin(),v.end(), myPrint);
    cout<<endl;


    cout<<"反转后："<<endl;
    reverse(v.begin(),v.end());
    for_each(v.begin(),v.end(), myPrint);
    cout<<endl;
}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}

