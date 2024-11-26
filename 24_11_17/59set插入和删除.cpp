//
// Created by tianya on 2024/11/19.
//
#include "iostream"
using namespace std;
#include "set"
//3.8.4set容器 插入和删除

//insert(elem);        //在容器中插入元素。
//clear();             //清除所有元素
//erase(pos);          //删除pos迭代器所指的元素，返回下一个元素的迭代器。
//erase(beg,end);      //删除区间[beg,end)的所有元素，返回下一个元素的迭代器。
//erase(elem);         //删除容器中值为elem的元素。



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

//    删除
    s1.erase(s1.begin());//删除头 10
    printSet(s1);//20 30 40

//    删除重载版本
    s1.erase(30);
    printSet(s1);//20 40

//    清空
//    s1.erase(s1.begin(),s1.end());
    s1.clear();
    printSet(s1);//空
}

int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
