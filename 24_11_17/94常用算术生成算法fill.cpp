//
// Created by tianya on 2024/11/21.
//

#include "iostream"
using namespace std;
#include "vector"
#include"numeric"  //算法库
#include "algorithm"//标准算法头文件

//5.5.2 常用算术生成算法 fill

//accumulate   计算容器元素累计总和   积累
//fill         向容器中添加元素      填满

//功能描述：
//    ·向容器中填充指定的元素
//
//函数原型：
//    · fill(iterator beg, iterator end, value);
//    向容器中填充元素
//    beg开始迭代器
//    end结束迭代器
//    value填充的值

//仿函数打印
class MyPrint{
public:
    void operator()(int val){
        cout<<val<<" ";
    }
};

void myPrint(int val){
    cout<<val<<" ";
}

void test01(){
    vector<int>v;
    v.resize(10);//修改空间  有个重载版本，适用于前期填充

    cout<<"填充前："<<endl;
    for_each(v.begin(),v.end(), myPrint);//普通函数
    cout<<endl;

//    后期重新填充
    fill(v.begin(),v.end(),100);

    cout<<"填充后："<<endl;
    for_each(v.begin(),v.end(), MyPrint());//仿函数
    cout<<endl;
}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
