//
// Created by tianya on 2024/11/21.
//
#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"//标准算法头文件

//5.4.3 常用拷贝和替换算法 replace_if

//功能描述：
    //·将区间内满足条件的元素，替换成指定元素
//
//-函数原型：
    //·replace_if(iterator beg,iterator end,_pred,newvalue);
    //按条件替换元素，满足条件的替换成指定元素
    //beg开始迭代器
    //end结束迭代器
    //_pred 谓词
    //newvalue替换的新元素

//谓词
class Greater30{
public:
    bool operator()(int val){
        return val>=30;
    }
};
void myPrint(int val){
    cout<<val<<" ";
}

//仿函数打印
class MyPrint{
public:
    void operator()(int val){
        cout<<val<<" ";
    }
};
void test01(){
    vector<int>v;

    v.push_back(20);
    v.push_back(30);
    v.push_back(50);
    v.push_back(30);
    v.push_back(40);
    v.push_back(20);
    v.push_back(10);
    v.push_back(20);

    cout<<"替换前："<<endl;
//    for_each(v.begin(),v.end(), myPrint);
    for_each(v.begin(),v.end(), MyPrint());//仿函数
    cout<<endl;

//    大于等于30 替换成 3000
    replace_if(v.begin(),v.end(),Greater30(),3000);

    cout<<"替换后："<<endl;
    for_each(v.begin(),v.end(), MyPrint());//仿函数
    cout<<endl;
}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
