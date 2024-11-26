//
// Created by tianya on 2024/11/19.
//
#include "iostream"
using namespace std;
#include "set"
//3.8.3set大小和交换

//size();        //返回容器中元素的数目
//empty();       //判断容器是否为空
//swap(st);      //交换两个集合容器


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

//    判断是否为空
    if(s1.empty()){
        cout<<"s1为空"<<endl;
    } else{
        cout<<"s1不为空"<<endl;
        cout<<"s1的元素个数为："<<s1.size()<<endl;
    }


}

//交换
void test02(){
    set<int>s1;

//    插入数据 只有insert方式
    s1.insert(10);
    s1.insert(40);
    s1.insert(30);
    s1.insert(20);
    s1.insert(30);

    set<int>s2;

//    插入数据 只有insert方式
    s2.insert(200);
    s2.insert(400);
    s2.insert(300);
    s2.insert(200);
    s2.insert(300);

    cout<<"交换前："<<endl;
    printSet(s1);
    printSet(s2);

    s1.swap(s2);//交换

    cout<<"交换后："<<endl;
    printSet(s1);
    printSet(s2);


}

int main(){
//    test01();
    test02();
    cout<<"HelloWorld"<<endl;
    return 0;
}
