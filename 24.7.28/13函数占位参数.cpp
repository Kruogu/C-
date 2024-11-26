//
// Created by tianya on 2024/7/28.
//
#include "iostream"
using namespace std;

//占位参数
//返回值类型  函数名（数据类型）
//目前阶段的占位参数，我们还用不到，后面课程中会用到
void func(int a,int){
    cout<<"this is funcc"<<endl;
}

void func1(int a,int = 10){  //占位参数还可以有默认参数  匿名参数？？
    cout<<"this is funcc"<<endl;
}
int main(){
//    func(10); //报错
    func(10,10);
    func1(10);
    cout<<"HelloWorld"<<endl;
    return 0;
}
