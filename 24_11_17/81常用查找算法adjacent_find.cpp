//
// Created by tianya on 2024/11/20.
//
#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"
#include "functional"//内建函数对象头文件

//5.2.3 常用查找算法adjacent_find

//adjacent_find(iterator beg,iterator end);
//查找相邻重复元素，返回相邻元素的第一个位置的迭代器
//beg开始迭代器
//end结束迭代器

//查找内置数据类型
void test01(){
    vector<int>v;

//    观察哪些同时 重复和相邻
    for (int i = 0; i < 8; ++i) {
        int ret = rand()%5;//1 2 4 0 4 4 3 3
        v.push_back(ret);
    }

    //遍历
    for(vector<int>::iterator it = v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

//    查找相邻重复元素  如果有两组相邻重复元素呢？
//    返回第一个相邻重复元素的迭代器
    vector<int>::iterator pos = adjacent_find(v.begin(),v.end());
    if(pos==v.end()){
        cout<<"未找到相邻重复元素"<<endl;
    } else{
        cout<<"找到相邻重复元素："<<*pos<<endl;//找到元素：4
    }
}

int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
