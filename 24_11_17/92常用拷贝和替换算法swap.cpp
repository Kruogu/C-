//
// Created by tianya on 2024/11/21.
//
#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"//标准算法头文件

//5.4.4 常用拷贝和替换算法 swap

//功能描述：
//    ·互换两个容器的元素
//
//函数原型：
//    · swap(container c1, container c2);
//    互换两个容器的元素
//    c1容器1
//    c2容器2

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
    vector<int>v1;
    vector<int>v2;

    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
        v2.push_back(i+100);
    }

    cout<<"交换前："<<endl;
//    for_each(v1.begin(),v1.end(), myPrint);
    for_each(v1.begin(),v1.end(), MyPrint());//仿函数
    cout<<endl;
    for_each(v2.begin(),v2.end(), MyPrint());//仿函数
    cout<<endl;

    swap(v1,v2);

    cout<<"————————————————"<<endl;
    cout<<"交换后："<<endl;
    for_each(v1.begin(),v1.end(), MyPrint());//仿函数
    cout<<endl;
    for_each(v2.begin(),v2.end(), MyPrint());//仿函数
    cout<<endl;

}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
