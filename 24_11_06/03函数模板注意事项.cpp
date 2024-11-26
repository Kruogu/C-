//
// Created by tianya on 2024/11/7.
//
#include "iostream"
using namespace std;

//1.2.2函数模板注意事项
//template <typename T>  //typename可以替换成class
template <class T>
void mySwap(T &a,T &b){
    T temp = a;
    a = b;
    b = temp;
}

//1、自动类型推导，必须推导出一致的数据类型T,才可以使用
void test01(){
    int a = 10;
    int b = 20;
    char c = 'c';
    mySwap(a,b);//正确
//    mySwap(a,c);//错误  整型和字符型进行交换  推导不出一致的T类型

    cout<<"a = "<<a<<" b = "<<b<<endl;
}

//2、模板必须要确定出 T 的数据类型，才可以使用
template<class T>
void func(){
    cout<<"func调用"<<endl;
}
void test02(){
//    func();//报错  必须指定类型才不报错
    func<int>();
}
int main(){
    test01();
    test02();
    cout<<"HelloWorld"<<endl;
    return 0;
}
