//
// Created by tianya on 2024/9/10.
//
#include "iostream"
using namespace std;

class Person{
public:
    Person(int age){
//        age = age;
//    this指针指向被调用成员函数所属的对象
        this->age = age;
    }

//    void PersonAddAge(Person &p){
//        this->age += p.age;
//    }

//    进阶  如果删掉 &引用  返回的是值  结果20
    Person& PersonAddAge(Person &p){
        this->age += p.age;
//        this指向的是一个p2的指针，而*this指向的就是p2这个对象本体
        return *this;//p2的本体
    }
    int age;
    int m_Age;//好的习惯，编码规范   成员Age
};

//1.解决名称冲突
void test01(){
    Person p1(18);
    cout<<"p1的年龄为："<<p1.age<<endl;
}

//2.返回对象本身用 *this
void test02(){
    Person p1(10);

    Person p2(10);

//    p2.PersonAddAge(p1);
//    cout<<"p2的年龄为："<<p2.age<<endl;//20   p1加到p2上

//    链式编程思想，可以无限往后追加  cout也是
    p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);//报错
    cout<<"p2的年龄为："<<p2.age<<endl;//40   p1连续加到p2上
}
int main(){
    test01();
    test02();
    cout<<"HelloWorld"<<endl;
    return 0;
}
