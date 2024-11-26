//
// Created by tianya on 2024/11/8.
//
#include "iostream"
using namespace std;

//1.2.5普通函数与函数模板的调用规则
//1.如果函数模板和普通函数都可以实现，优先调用普通函数
//2.可以通过空模板参数列表来强制调用函数模板
//3.函数模板也可以发生重载
//4.如果函数模板可以产生更好的匹配,优先调用函数模板

//void myPrint(int a,int b);//如果只保留函数声明，那么优先调用谁？
void myPrint(int a,int b){
    cout<<"调用的普通函数"<<endl;
}

template<class T>
void myPrint(T a,T b){
    cout<<"调用的函数模板"<<endl;
}

template<class T>
void myPrint(T a,T b,T c){
    cout<<"调用重载的函数模板"<<endl;
}

void test01(){
    int a = 10;
    int b = 20;
//    myPrint(a,b);//优先普通

//    通过空模板参数列表来强制调用函数模板
//    myPrint<>(a,b);//优先调用模板
//    myPrint(a,b,100);//优先调用重载模板

//    如果函数模板可以产生更好的匹配,优先调用函数模板
    char c1 = 'a';
    char c2 = 'd';
    myPrint(c1,c2);//优先调用模板,普通函数要多一个转换，所以优先度不高
    myPrint<>(c1,c2,'d');//优先调用重载模板
}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
