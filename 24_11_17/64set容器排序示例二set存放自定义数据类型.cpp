//
// Created by tianya on 2024/22/19.
//
#include "iostream"
using namespace std;
#include "set"
//3.8.8set容器排序

//示例一 set存放 自定义 数据类型

class Person{
public:
    //类内实现
    Person(string name,int age){
        this->m_Name = name;
        this->m_Age = age;
    }
//private:
    string m_Name;
    int m_Age;
};

class comparePerson{
public:
//    注意，因为C++11新特性的缘故，你们需要在参数列表后添加const
    bool operator()(const Person &p1,const Person &p2)const{//第一个小括号代表要重载的符号，第二个小括号代表参数列表
//        大于是降序  默认是升序
        return p1.m_Age>p2.m_Age;
    }
};

void test01(){
//    自定义数据类型 都会指定排序规则
//    set<Person>s1;//会直接报错
    set<Person,comparePerson>s1;//仿函数指定类型

    //    准备数据
    Person p1("刘备",35);
    Person p2("曹操",45);
    Person p3("孙权",40);
    Person p4("赵云",25);
    Person p5("张飞",35);
    Person p6("关羽",35);
//    s1.emplace("关羽",35);//c++11新特性，目前不能用

    s1.insert(p1);
    s1.insert(p2);
    s1.insert(p3);
    s1.insert(p4);
    s1.insert(p5);
    s1.insert(p6);


//    自动排好序了已经，打印检测一下  重复数据自动抹除
    for(set<Person,comparePerson>:: iterator it=s1.begin();it!=s1.end();it++){//comparePerson可以加上
//    for(set<Person>:: iterator it=s1.begin();it!=s1.end();it++){
        cout<<"姓名："<<it->m_Name<<" "
//        cout<<"姓名："<<(*it).m_Name<<" "
            <<" 年龄："<<(*it).m_Age<<endl;
    }
    cout<<endl;

}

int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
