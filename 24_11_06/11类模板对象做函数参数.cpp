//
// Created by tianya on 2024/11/8.
//

#include "iostream"
using namespace std;

//1.3.4类模板对象做函数参数

template<class T1,class T2>
class Person{
public:
    Person(T1 name,T2 age){
        this->m_Name = name;
        this->m_Age = age;
    }

    void showPerson(){
        cout<<"姓名:"<< this->m_Name<< endl;
        cout<<"年龄:"<< this->m_Age<< endl;
    }
    T1 m_Name;
    T2 m_Age;
};

//最常用的类型
//1.指定传入的类型——直接显示对象的数据类型  类模板的对象,做函数中的参数
void printPerson1(Person<string ,int>&p){//直接引用,不加引用就是值传递
    p.showPerson();
}
void test01(){
    Person<string ,int>p("张三",18);
    printPerson1(p);//第一种
//    p.showPerson();
}


//2.参数模板化——将对象中的参数变为模板进行传递
template<class T1,class T2>
void printPerson2(Person<T1,T2>&p){
    p.showPerson();
    cout<<"T1的类型为:"<< typeid(T1).name()<< endl;//查看编译器推导出来的T数据类型
    cout<<"T2的类型 为:"<< typeid(T2).name()<< endl;
}
void test02(){
    Person<string ,int>p("猪八戒",90);
    printPerson2(p);
}


//3.整个类模板化——将这个对象类型模板化进行传递
template<class T>
void printPerson3(T &p){
    p.showPerson();
    cout<<"T的类型为:"<< typeid(T).name()<< endl;//查看编译器推导出来的T数据类型
//    6PersonINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE
//     Person类                   string                           int
}
void test03(){
    Person<string ,int>p("唐僧",30);
    printPerson3(p);
}
int main(){
    test01();
    test02();
    test03();
    cout<<"HelloWorld"<<endl;
    return 0;
}
