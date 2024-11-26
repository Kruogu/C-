//
// Created by tianya on 2024/11/20.
//
#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"
#include "functional"//内建函数对象头文件

//5.2.1常用查找算法find

//· find(iterator beg, iterator end, value);
//按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
//beg开始迭代器
//end结束迭代器
//value查找的元素

class Person{
public:
    Person(string name,int age){
        this->m_Name = name;
        this->m_Age = age;
    }
//    重载 == 符号 让底层find知道如何对比person数据类型
    bool operator==(const Person &p){
        if(this->m_Name==p.m_Name && this->m_Age== this->m_Age){
            return true;
        } else{
            return false;
        }

    }
    string m_Name;//姓名
    int m_Age;//年龄
};

//查找内置数据类型

void test01(){
    vector<int>v;

    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }

    //查找 容器中 是否有 5 这个元素
    vector<int>::iterator it = find(v.begin(),v.end(),5);
//    vector<int>::iterator it = find(v.begin(),v.end(),50);
    if(it==v.end()){
        cout<<"没有找到！"<<endl;
    } else{
        cout<<"找到："<<*it<<endl;
    }
}

//查找自定义数据类型
void test02(){
    vector<Person>v;
//    创建数据
    Person p1("aaa",10);
    Person p2("bbb",20);
    Person p3("ccc",30);
    Person p4("ddd",40);

//    放入到容器中
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    Person pp("bbb",20);

//    find报错，没有重载运算符  两种方法都可以比较
//    vector<Person>::iterator it = find(v.begin(),v.end(),p2);
    vector<Person>::iterator it = find(v.begin(),v.end(),pp);

    if(it==v.end()){
        cout<<"没有找到！"<<endl;
    } else{
        cout<<"找到元素 姓名："<<it->m_Name
            <<"年龄："<<(*it).m_Age<<endl;
    }
}
int main(){
    test01();
    test02();
    cout<<"HelloWorld"<<endl;
    return 0;
}
