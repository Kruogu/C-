//
// Created by tianya on 2024/11/19.
//
#include "iostream"
using namespace std;
#include "queue"

//3.6.2 队列queue常用接口

class Person{
public:
    Person(string name,int age){
        this->m_Name = name;
        this->m_Age = age;
    }
    string m_Name;//姓名
    int m_Age;//评分
};

void test01(){
//    特点：符合先进先出数据结构
//    queue<int>q;
//    创建队列
    queue<Person>q;//试试其他数据类型

//    准备数据
    Person p1("唐僧",30);
    Person p2("孙悟空",1000);
    Person p3("猪八戒",900);
    Person p4("沙僧",800);

//    入队
    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);

    cout<<"队列的大小为："<<q.size()<<endl;
    
//    只要队列不为空，就查看队头，查看队尾
    while (!q.empty()){//不为空

//        查看队头元素
        cout<<"队头元素——姓名："<<q.front().m_Name
            <<"年龄："<<q.front().m_Age<<endl;

//        查看队尾元素
        cout<<"队尾元素——姓名："<<q.back().m_Name
            <<"年龄："<<q.back().m_Age<<endl;

//        出队
        q.pop();
        cout<<endl;
    }
    cout<<"队列的大小为："<<q.size()<<endl;

}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
