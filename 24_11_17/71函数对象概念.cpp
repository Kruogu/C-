//
// Created by tianya on 2024/11/20.
//
#include "iostream"
using namespace std;

//4.1.1函数对象概念  (仿函数)

//函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
//函数对象超出普涌函数的概念，函数对象可以有自己的状态
//函数对象可以作为参数传递


class MyAdd{
public:
    int operator()(int v1,int v2){
        return v1+v2;
    }
};

//1、函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
void test01(){
    MyAdd myAdd;//函数对象
    cout<<myAdd(10,10)<< endl;
}



//2、函数对象超出普涌函数的概念，函数对象可以有自己的状态
class MyPrint{
public:
    MyPrint(){
        this->count = 0;
    }
    void operator()(string test){
        cout<<test<<endl;
        this->count++;//统计使用次数
    }
    int count;//内部自己的状态
};

void test02(){
//    有问题，函数对象只能调用一次，不能调用多次  函数类型写成int了，改成void已解决
    MyPrint myPrint;
    myPrint("hello world");
    myPrint("hello world");
    myPrint("hello world");

    cout << "myPrint调用次数为："<< myPrint. count << endl;
}


//3、函数对象可以作为参数传递
void doPrint(MyPrint &mp,string test){
    mp(test);//字符串传进了函数对象里面
}
void test03(){
    MyPrint myPrint;
    doPrint(myPrint,"Hello c++");
}
int main(){
    test01();
    test02();
    test03();
    cout<<"HelloWorld"<<endl;
    return 0;
}

