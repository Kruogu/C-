//
// Created by tianya on 2024/11/20.
//
#include "iostream"
using namespace std;
#include "map"

//3.9.6map容器 自定义数据类型排序

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

//运算符重载
class MyCompare{
public:
//    Person在后用第一种，Person在前用第二种
//    bool operator()(int v1,int v2)const{//第一个小括号代表要重载的符号，第二个小括号代表参数列表
////        大于是降序  默认是升序
//        return v1>v2;
//    }

    bool operator()(const Person &p1,const Person &p2)const{
    //        降序
        return p1.m_Age>p2.m_Age;
    }
};

//第一种输出规则  可以利用key值从大到小降序排序，从小到大升序不需要函数也可以
////void printMap(map<int,Person> &m){
//void printMap(map<int,Person,MyCompare> &m){
////    升序和降序不一样
////    for(map<int,Person>::iterator it = m.begin();it!=m.end();it++){
//    for(map<int,Person,MyCompare>::iterator it = m.begin();it!=m.end();it++){
//        cout<<"key = "<<(*it).first
//            <<"  value姓名："<<it->second.m_Name
//            <<"  value年龄："<<it->second.m_Age<<endl;
//    }
//    cout<<endl;
//}

//第二种输出规则  这种可以排序
//void printMap(map<Person,int> &m){
void printMap(map<Person,int,MyCompare> &m){
//    升序和降序不一样
//    for(map<Person,int>::iterator it = m.begin();it!=m.end();it++){
    for(map<Person,int,MyCompare>::iterator it = m.begin();it!=m.end();it++){
        cout<<"key姓名："<<(*it).first.m_Name
            <<"  key年龄："<<it->first.m_Age
            <<"  value = "<<it->second<<endl;
    }
    cout<<endl;
}

void test01(){

//    这个不算自定义数据类型，这个其实是int类型，value是什么类型都不影响
//    map<int,Person>m1;//可以利用key值从小到大升序排序，但不能用value值年龄排序
//    map<int,Person,MyCompare>m1;//可以利用key值从大到小降序排序，，但不能用value值年龄排序

//    自定义数据类型 必须指定排序规则
//    map<Person,int>m1;//直接报错 因为没有指定，但可以在MyCompare更改 < 达到从小到大升序效果
    map<Person,int,MyCompare>m1;//降序  可以正常用key值中的年龄进行从大到小排序

    //    准备数据
    Person p1("刘备",35);
    Person p2("曹操",45);
    Person p3("孙权",40);
    Person p4("赵云",25);
    Person p5("张飞",30);
    Person p6("关羽",35);

//    插入数据 <int,Person>
    m1.insert(make_pair(p1,1));//insert报错 是因为MyCompare中的运算符重载错了，用第二种规则就好了
    m1.insert(make_pair(p2,2));
    m1.insert(make_pair(p3,3));
    m1.insert(make_pair(p4,4));
    m1.insert(make_pair(p5,5));
    m1.insert(make_pair(p6,6));

//    插入数据 <int,Person,MyCompare>
//    m1.insert(make_pair(1,p1));
//    m1.insert(make_pair(3,p3));
//    m1.insert(make_pair(2,p2));
//    m1.insert(make_pair(3,p3));//本行插不进去，count是1
//    m1.insert(make_pair(4,p4));
//    m1.insert(make_pair(5,p5));
//    m1.insert(pair<int,Person>(6,p6));

    printMap(m1);

}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}

