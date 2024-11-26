//
// Created by tianya on 2024/11/19.
//
#include "iostream"
using namespace std;
#include "set"
//3.8.5set容器 查找和统计

//find(key);   //查找key是否存在，若存在，返回该键的元素的迭代器；
//                             若不存在，返回set.end();

//count(key);  //统计key的元素个数 (0或者1)

void printSet(set<int> &s){
    for(set<int>::iterator it = s.begin();it!=s.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

//    查找
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

//    查找
    set<int>::iterator pos = s1.find(30);//pos  迭代器位置
//    set<int>::iterator pos = s1.find(300);//pos  未找到

    //    判断是否为空
    if(pos != s1.end()){
        cout<<"找到元素："<<*pos<<endl;
    } else{
        cout<<"未找到元素"<<endl;
    }
}

//统计
void test02(){
    set<int>s1;

//    插入数据 只有insert方式
    s1.insert(10);
    s1.insert(40);
    s1.insert(30);
    s1.insert(20);
    s1.insert(30);

//    统计30的个数
//    对于set而言   统计结果要么是0  要么是1
    int num1 = s1.count(30);//不管有几个都是一个
    cout<<"num1 = "<<num1<<endl;//num = 1

    int num2 = s1.count(50);//没有
    cout<<"num2 = "<<num2<<endl;//num = 0
}

int main(){
    test01();
    test02();
    cout<<"HelloWorld"<<endl;
    return 0;
}
