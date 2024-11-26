//
// Created by tianya on 2024/11/21.
//
#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"//标准算法头文件
#include "functional"//greater

//5.3.1 常用排序算法 sort

//·sort(iterator beg,iterator end,_Pred);
//按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
//beg开始迭代器

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

    //利用sort进行升序
    sort(v.begin(),v.end());

//    打印输出 升序 两种
    for_each(v.begin(),v.end(), myPrint);
    cout<<endl;

//    for(vector<int>::iterator it = v.begin();it!=v.end();it++){
//        cout<<*it<<" ";
//    }
//    cout<<endl;

//    降序
    sort(v.begin(),v.end(),greater<int>());//直接改变容器内顺序
    for_each(v.begin(),v.end(), myPrint);
    cout<<endl;

    sort(v.begin(),v.end());
    for_each(v.rbegin(),v.rend(), myPrint);//倒序打印，容器内没变
    cout<<endl;
}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
