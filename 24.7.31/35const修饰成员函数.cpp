//
// Created by tianya on 2024/9/18.
//

#include "iostream"
using namespace std;

//const修饰成员函数
//常函数
class Person{
public:
//    Person(){}//初始化p值
    //this指针的本质  是指针常量  指针的指向是不可以修改的  值可以修改
    // const Person *const this;第一个const相当于 15行内容
//    在成员函数后面加const，修饰的是this指向，让指针指向的值也不可以修改
//    void showPerson()
    void showPerson() const//加上就不能修改值了
    {
//        m_A = 100;//可以修改值
//        this->m_A = 100;//同上一行
//        this = NULL;//this指针是不可以修改指针的指向的
        this->m_B = 10;
    }
    void func()//不加const就不允许调用，不能修改值
    {
        m_A = 100;
    }
    int m_A;
    mutable int m_B;//特殊变量，即使在常函数中，也可以修改这个值,加关键字mutable
};

void test01(){
    Person p;
    p.showPerson();
    cout<<"m_A:"<<p.m_A<<endl;
    cout<<"m_B:"<<p.m_B<<endl;
}

//常对象
void test02(){
//    const Person p;//原版  报错
    const Person p{};
//    p.m_A = 100;//报错 不能修改  在对象前加const,变为常对象
    p.m_B = 200;//可以修改  m_B是特殊值，在常对象下也可以修改
    cout<<"m_B:"<<p.m_B<<endl;

//    常对象只能调用常函数
    p.showPerson();
//    p.func();//报错 不是常函数  常对象不可以调用普通成员函数，因为普通成员函数可以修改属性
}
int main(){
    test01();
    test02();
    cout<<"HelloWorld"<<endl;
    return 0;
}

