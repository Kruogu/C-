//
// Created by tianya on 2024/11/19.
//
#include "iostream"
using namespace std;
#include "map"
//3.9.5map容器 查找和统计

//find(key);   //查找key是否存在，若存在，返回该键的元素的迭代器；
//                             若不存在，返回map.end();

//count(key);  //统计key的元素个数 (0或者1)

void printMap(map<int,int> &m){
    for(map<int,int>::iterator it = m.begin();it!=m.end();it++){
        cout<<"key = "<<(*it).first
            <<" value = "<<it->second<<endl;
    }
    cout<<endl;
}

//查找
void test01(){
    map<int,int>m1;

//    插入数据
    m1.insert(pair<int,int>(1,10));
    m1.insert(pair<int,int>(3,30));
    m1.insert(pair<int,int>(2,20));

//    遍历容器
//    map容器特点：所有元素插入时候自动被排序
//    map容器不允许插入重复值,插了白插，不显示
    printMap(m1);//无序出来变有序  10 20 30 40

//    查找
    map<int,int>::iterator pos = m1.find(3);//pos  迭代器位置
//    map<int,int>::iterator pos = m1.find(300);//pos  未找到

    //    判断是否为空
    if(pos != m1.end()){
        cout<<"找到元素 key = "<<(*pos).first
            <<" value = "<<pos->second<<endl;
    } else{
        cout<<"未找到元素"<<endl;
    }
}

//统计
void test02(){
    map<int,int>m1;

//    插入数据
    m1.insert(pair<int,int>(1,10));
    m1.insert(pair<int,int>(3,30));
    m1.insert(pair<int,int>(2,20));
    m1.insert(pair<int,int>(3,30));//本行插不进去，count是1

//    统计30的个数
//    map不允许插入重复key，coount统计结果，要么是0  要么是1
//    multimap的count统计可能大于 1
    int num1 = m1.count(3);//不管有几个都是一个
    cout<<"num1 = "<<num1<<endl;//num = 1

    int num2 = m1.count(50);//没有
    cout<<"num2 = "<<num2<<endl;//num = 0
}

int main(){
    test01();
    test02();
    cout<<"HelloWorld"<<endl;
    return 0;
}
