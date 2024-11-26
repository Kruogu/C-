//
// Created by tianya on 2024/11/21.
//

#include "iostream"
using namespace std;
#include "vector"
#include"numeric"  //算法库
//5.5.1 常用算术生成算法 accumulate

//accumulate   计算容器元素累计总和   积累
//fill         向容器中添加元素      填满

//功能描述：
//    ·计算区间内容器元素累计总和
//
//函数原型：
//    · accumulate(iterator beg, iterator end, value);
//    计算容器元素累计总和
//    beg开始迭代器
//    end结束迭代器
//    value起始值    参数3  起始的累加值


void test01(){
    vector<int>v;
    for (int i = 0; i <= 100; ++i) {
        v.push_back(i);
    }

//    参数3  起始的累加值
    int total = accumulate(v.begin(),v.end(),0);//total = 5050
//    int total = accumulate(v.begin(),v.end(),1000);//total = 6050
    cout<<"total = "<<total<<endl;
}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
