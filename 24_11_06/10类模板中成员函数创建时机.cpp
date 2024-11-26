//
// Created by tianya on 2024/11/8.
//

#include "iostream"
using namespace std;

//类模板中成员函数创建时机
//类模板中的成员函数在调用时才创建,一开始不会创建

//template<class NameType,class AgeType>//两个类型 模板
class Person1{
public:
    void showPerson1()
    {
        cout<<"Person1 show"<< endl;
    }
};

class Person2{
public:
    void showPerson2()
    {
        cout<<"Person2 show"<< endl;
    }
};

template<class T>
class MyClass{
public:
    T obj;//obj是对象的意思

    //类模板中的成员函数
    void func1()
    {
        obj.showPerson1();

    }
    void func2()
    {
        obj.showPerson2();
    }

};

void test01(){
    MyClass<Person1>m;
//    MyClass<Person1,Person2>m;//不行,只要一个类型
    m.func1();
//    m.func2();
}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
