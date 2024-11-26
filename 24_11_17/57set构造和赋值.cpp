//
// Created by tianya on 2024/11/19.
//
#include "iostream"
using namespace std;
#include "set"
//3.8.2set构造和赋值

//构造：
//    set<T> st;                          //默认构造函数：
//    set(const set &st);                 //拷贝构造函数
//
//赋值：
//    set& operator=(const set &st);      //重载等号操作符

void printSet(set<int> &s){
    for(set<int>::iterator it = s.begin();it!=s.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

void test01(){
    set<int>s1;

//    插入数据 只有insert方式
    s1.insert(10);
    s1.insert(40);
    s1.insert(30);
    s1.insert(20);
    s1.insert(30);

//    遍历容器
//    set容器特点：所有元素插入时候自动被排序
//    set容器不允许插入重复值,插了白插，不显示
    printSet(s1);//无序出来变有序  10 20 30 40

//    拷贝构造
    set<int>s2(s1);
    printSet(s2);//10 20 30 40

//    赋值
    set<int>s3(s1);
    s3 = s2;
    printSet(s3 );//10 20 30 40

}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
