//
// Created by tianya on 2024/11/20.
//
#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"
#include "functional"//内建函数对象头文件

//5.1.2 78常用遍历算法transfrom

//·transform(iterator beg1,iterator end1,iterator beg2,_func);
//beg1源容器开始迭代器
//end1 源容器结束迭代器
//beg2目标容器开始迭代器
//_func函数或者函数对象

//仿函数
class Transform{
public:
    int operator()(int v){//取出来 再放回去
//        return v;
        return v+1000;
    }
};

//仿函数
class MyPrint{
public:
    void operator()(int val){
        cout<<val<<" ";
    }
};
void test01(){
    vector<int>v;

    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }

    vector<int>vTarget;//目标容器  Target 目标
    vTarget.resize(v.size());//目标容器 需要提前开辟空间

    transform(v.begin(),v.end(),vTarget.begin(),Transform());

//    仿函数遍历   重载了小括号  匿名对象才行
    for_each(vTarget.begin(),vTarget.end(), MyPrint());
    cout<<endl;
}

int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
