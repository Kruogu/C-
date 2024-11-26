//
// Created by tianya on 2024/7/26.
//
#include "iostream"
using namespace std;

//1.值传递
void mySwap01(int a,int b){
    int temp = a;
    a = b;
    b = temp;
}

//2.地址传递
void mySwap02(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
//3.引用传递
void mySwap03(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}
int main(){
    int a=10,b=20;
//    mySwap01(a,b);//实参 a和b 没有发生改变
//    mySwap02(&a,&b);//地址传递，形参会修饰实参的
    mySwap03(a,b);//引用传递，形参会修饰实参的

    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;

    cout<<"HelloWorld"<<endl;
    return 0;
}

