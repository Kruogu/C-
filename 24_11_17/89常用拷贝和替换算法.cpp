//
// Created by tianya on 2024/11/21.
//
#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"//标准算法头文件

//5.4常用拷贝和替换算法

//算法简介：
//.copy              //容器内指定范围的元素拷贝到另一容器中
//·replace           //将容器内指定范围的旧元素修改为新元素
//·replace_if        //容器内指定范围满足条件的元素替换为新元素
//·swap              //互换两个容器的元素

//底层实现是fo循环+指针移动+赋值操作

void myPrint(int val){
    cout<<val<<" ";
}

void test01(){
    vector<int>v1;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }

    //    打印v1
    cout<<"v1："<<endl;
    for_each(v1.begin(),v1.end(), myPrint);
    cout<<endl;

//    拷贝算法  实际开发中如果有 更简单的赋值操作 可以直接使用
    vector<int>v2;
    v2.resize(v1.size());
    copy(v1.begin(),v1.end(),v2.begin());

    //    打印v2
    cout<<"拷贝后v2："<<endl;
    for_each(v2.begin(),v2.end(), myPrint);
    cout<<endl;
}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
