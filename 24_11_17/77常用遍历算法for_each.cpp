//
// Created by tianya on 2024/11/20.
//
#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"//本期不加也行
#include "functional"//内建函数对象头文件 本期不加也行

//5.1.1 常用遍历算法 for_each

//·for_each(iterator beg,iterator end,_func);
//遍历算法 遍历容器元素
//beg开始迭代器
//end结束迭代器
//_func函数或者函数对象

//普通函数
void print01(int val){
    cout<<val<<" ";
}

//仿函数
class print02{
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

//    普通函数遍历
    for_each(v.begin(),v.end(), print01);
    cout<<endl;

//    仿函数遍历   重载了小括号  匿名对象才行
    for_each(v.begin(),v.end(), print02());
    cout<<endl;
}

int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
