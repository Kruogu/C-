//
// Created by tianya on 2024/7/26.
//
#include "iostream"
using namespace std;

//打印数据函数
//void showValue(int &val){  //可以修改原始值
void showValue(const int &val){//加了const不能修改原始值
//    val = 1000;
    cout<<"val = "<<val<< endl;
}
int main(){
//    常量引用
//    使用场景：用来修饰形参，防止误操作
//    int a = 10;
//    加上const.之后编译器将代码修改int temp=10;int & ref=temp;
//    const int & ref = 10;//引用必须引一块合法的内存空间
//    ref = 20;//加入const之后变为只读，不可以修改

    int a = 100;
    showValue(a);
    cout<<"a = "<<a<<endl;//a的值也发生了改变

    cout<<"HelloWorld"<<endl;
    return 0;
}
