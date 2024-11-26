//
// Created by tianya on 2024/11/17.
//
#include "iostream"
using namespace std;
#include "vector"//迭代器头文件
#include "algorithm"//标准算法头文件

//2.5.2 Vector存放自定义数据类型
//未能实现全局函数 和 for_each

class Person{
public:
    //类内实现
    Person(string name,int age){
        this->m_Name = name;
        this->m_Age = age;
    }

    void showPerson();
//    void showPerson(){
//        cout<<"姓名："<< this->m_Name<< endl;
//        cout<<"年龄："<< this->m_Age<< endl;
//    }
    string m_Name;
    int m_Age;
};

void Person::showPerson(){
    cout<<"姓名："<< this->m_Name
        <<"年龄："<< this->m_Age<< endl;
}

void test(){
    Person p1("aaa",10);
    p1.showPerson();
}

void test01(){
    vector<Person>v;

    Person p1("aaa",10);
    Person p2("bbb",20);
    Person p3("ccc",30);
    Person p4("ddd",40);
    Person p5("eee",50);

//    向容器中插入数据  尾插法
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

//    遍历容器中的数据
    for(vector<Person>::iterator it=v.begin();it!=v.end();it++){
//        cout<<"姓名："<< (*it).m_Name
//            <<" 年龄："<< (*it).m_Age<< endl;//it本质是指针
        cout<<"姓名："<< it->m_Name
            <<" 年龄："<< it->m_Age<< endl;
    }
//    for_each(v.begin(),v.end(),Person::showPerson);
//    for_each(v.begin(),v.end(),showPerson);
}

//存放自定义类型的指针
void test02(){
    vector<Person*>v;//对象指针

    Person p1("aaa",10);
    Person p2("bbb",20);
    Person p3("ccc",30);
    Person p4("ddd",40);
    Person p5("eee",50);

//    向容器中插入数据  尾插法
    v.push_back(&p1);//取值符
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);

    //    遍历容器中的数据
    for(vector<Person *>::iterator it=v.begin();it!=v.end();it++){
        cout<<"2姓名："<< (*it)->m_Name
            <<" 2年龄："<< (*it)->m_Age<< endl;//指针的指针
    }
}
int main(){
//    test01();
    test02();
//    test();
    cout<<"HelloWorld"<<endl;
    return 0;
}
