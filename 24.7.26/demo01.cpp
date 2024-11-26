//
// Created by tianya on 2024/7/26.
//
#include "iostream"
using namespace std;

int *func1(){//栈区，不返回值
    int a = 10;
    return &a;
}
int *func2(){//堆区
//    利用new关键字可以将数据开辟到堆区   new给的是指针而不是数据
    int * q = new int(10);//解引用  栈区的q指针指向堆区的地址
    return q;
}

void test01(){
    int *p = func2();
    cout<<*p<<endl;
    cout<<*p<<endl;
//    堆区的数据由程序员庸理开辟，程序员管理释放
//    如果想释放推区的数据，利用关键字delete
    delete p;
    cout<<*p<<endl;//内存已经被释放，无法打印数据了，野指针
}

//2.在堆区开辟数组
void test02(){
//    创建10整型数据的数组，在堆区
    int *arr = new int[10];//10代表数组有10个元素
    for(int i=0;i<10;i++){
        arr[i] = i+100; //给10个元素100~109
    }

//    遍历数组
    for(int i=0;i<10;i++){
        cout<<arr[i]<<endl;
    }

//    释放堆区数组
//    释放数组的时候要加[]才可以
    delete[] arr;//不加中括号，只会释放第1个元素

    //    遍历数组
    for(int i=0;i<10;i++){
        cout<<arr[i]<<endl;
    }

}

int main(){

//    int *p = func1();//栈区
//    cout<<*p<<endl;//局部变量不会返回值
//    int *p1;
//    cout<<"p1地址："<<&p1<<endl;


//    在堆区开辟数据
//    int *q = func2();
//    cout<<*q<<endl;//打印几次都行
//    cout<<*q<<endl;
//    cout<<*q<<endl;
//    cout<<"q地址："<<&q<<endl;


//    test01();//堆区

    test02();//new数组

    return 0;
}
