//
// Created by tianya on 2024/11/19.
//
#include "iostream"
using namespace std;
#include "map"
//3.9.3map大小和交换

//mize();        //返回容器中元素的数目
//empty();       //判断容器是否为空
//mwap(mt);      //交换两个集合容器


void printMap(map<int,int> &m){
    for(map<int,int>::iterator it = m.begin();it!=m.end();it++){
        cout<<"key = "<<(*it).first
            <<" value = "<<it->second<<endl;
    }
    cout<<endl;
}

void test01(){
    map<int,int>m;

//    插入数据
    m.insert(pair<int,int>(1,10));
    m.insert(pair<int,int>(3,30));
    m.insert(pair<int,int>(2,20));
    m.insert(pair<int,int>(4,40));

//    遍历容器
//    map容器特点：所有元素插入时候自动被排序
//    map容器不允许插入重复值,插了白插，不显示
    printMap(m);//无序出来变有序  10 20 30 40

//    判断是否为空
    if(m.empty()){
        cout<<"m为空"<<endl;
    } else{
        cout<<"m不为空"<<endl;
        cout<<"m的元素个数为："<<m.size()<<endl;
    }


}

//交换
void test02(){

    map<int,int>m;
//    插入数据
    m.insert(pair<int,int>(1,10));
    m.insert(pair<int,int>(3,30));
    m.insert(pair<int,int>(2,20));
    m.insert(pair<int,int>(4,40));


    map<int,int>m2;
//    插入数据
    m2.insert(pair<int,int>(5,100));
    m2.insert(pair<int,int>(7,200));
    m2.insert(pair<int,int>(8,400));
    m2.insert(pair<int,int>(6,300));

    cout<<"\n交换前："<<endl;
    printMap(m);
    printMap(m2);

    m.swap(m2);//交换

    cout<<"交换后："<<endl;
    printMap(m);
    printMap(m2);
}

int main(){
    test01();
    test02();
    cout<<"HelloWorld"<<endl;
    return 0;
}
