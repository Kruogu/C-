//
// Created by tianya on 2024/10/23.
//
#include "iostream"
using namespace std;

//函数调用运算符重载

//打印输出
class MyPrint{
public:
//    重载函数调用运算符
    void operator()(string test){
        cout<<test<<endl;
    }
};

void MyPrint02(string test){
    cout<<test<<endl;
};
void test01(){
    MyPrint myPrint;
    myPrint("Hello World");//由于使用起来非常类似于函数调用，因此称为仿函数

    MyPrint02("Hello World");//调用MyPrint02函数
}

//仿函数非常灵活，没有固定的写法
//加法类
class MyAdd{
public:
    int operator()(int num1,int num2){
        return num1+num2;
    }
};

void test02(){
    MyAdd myAdd;
    int ret = myAdd(100,100);
    cout<<"ret= "<<ret<<endl;

//    匿名函数对象  当前行执行完，立即被释放
    cout<<MyAdd()(100,100)<<endl;
}
int main(){
//    test01();
    test02();
    cout<<"HelloWorld"<<endl;
    return 0;
}
