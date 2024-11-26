//
// Created by tianya on 2024/9/17.
//
#include "iostream"
using namespace std;
//空指针调用成员函数
class Person{
public:
    void showClassName(){
        cout<<"this is Person class"<<endl;
    }
    void showPersonAge(){
//        报错原因是因为传入的指针为空NULL
    if(this==NULL){  //防止崩溃
        return;
    }
        cout<<"age = "<<m_Age<<endl;
//        cout<<"age = "<<this.m_Age<<endl;
    }
    int m_Age;
};

void test01(){
    Person *p = NULL;
    p->showClassName();//没崩
//    p->showPersonAge();//崩了
}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
