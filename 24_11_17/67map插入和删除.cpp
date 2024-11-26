//
// Created by tianya on 2024/11/19.
//
#include "iostream"
using namespace std;
#include "map"
//3.9.4map容器 插入和删除

//insert(elem);        //在容器中插入元素。
//clear();             //清除所有元素
//erase(pos);          //删除pos迭代器所指的元素，返回下一个元素的迭代器。
//erase(beg,end);      //删除区间[beg,end)的所有元素，返回下一个元素的迭代器。
//erase(key);          //删除容器中值为key的元素。

void printMap(map<int,int> &s){
    for(map<int,int>::iterator it = s.begin();it!=s.end();it++){
        cout<<"key = "<<(*it).first
            <<" value = "<<it->second<<endl;
    }
    cout<<endl;
}

void test01(){
    map<int,int>m1;
    
//    第一种 插入数据
    m1.insert(pair<int,int>(1,10));
    m1.insert(pair<int,int>(3,30));
    m1.insert(pair<int,int>(2,20));

//    遍历容器
//    map容器特点：所有元素插入时候自动被排序
//    map容器不允许插入重复值,插了白插，不显示
    printMap(m1);//无序出来变有序  10 20 30

//    第二种插入  老师喜欢这种
    m1.insert(make_pair(4,40));
    printMap(m1);//无序出来变有序  10 20 30 40

//    第三种插入  map作用域下的值类型
    m1.insert(map<int,int>::value_type (5,50));
    printMap(m1);//无序出来变有序  10 20 30 40 50

//    第四种  []不建议插入，用途可以利用key访问到value
    m1[6] = 60;
    printMap(m1);//无序出来变有序  10 20 30 40 50 60

    cout<<m1[7]<< endl;//没有7 ，输出0，会自动创建出一个value出来，不建议使用[]方式插入
    cout<<"访问m1[6]："<<m1[6]<< endl;//访问
    printMap(m1);//无序出来变有序  10 20 30 40 50 60 0

//    删除
    cout<<"删除："<< endl;
    m1.erase(m1.begin());//删除头 10
    printMap(m1);//20 30 40 50 60 0

//    删除重载版本
    m1.erase(3);//按照key删除，和value没关系
    printMap(m1);//20 40 50 60 0

//    清空
//    m1.erase(m1.begin(),m1.end());
    m1.clear();
    printMap(m1);//空
}

int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
