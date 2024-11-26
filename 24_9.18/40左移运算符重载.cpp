//
// Created by tianya on 2024/10/3.
//
#include "iostream"
using namespace std;

//左移运算符重载
class Person{
    friend ostream &operator<<(ostream &cout,Person &p);//友元
public:
    Person(int a,int b){
        m_A = a;
        m_B = b;
    }
//    利用成员函数重载 左移运算符 p.operator<<(p)
//                           p.operator<<(cout) 简化版本 p<<cout
//    通常不会利用成员函数重载<<运算符，因为无法实现cout在左侧
//    void operator<<(Person &p){
//    void operator<<(cout){
//
//    }
private://如果是私有前面就要加上friend友元
    int m_A;
    int m_B;
};

//只能利用全局函数重载左移运算符
//void operator<<(cout,p)//本质 operator<<(cout,p) 简化 cout << p
//void operator<<(ostream &cout,Person &p)
ostream &operator<<(ostream &cout,Person &p)
{
    cout<<"m_A = "<<p.m_A<<" m_B = "<<p.m_B<<endl;
    return cout;
}

//ostream &operator<<(ostream &out,Person &p)// cout 改成 out 也可以
//{
//    out<<"m_A = "<<p.m_A<<" m_B = "<<p.m_B<<endl;
//    return out;
//}
void test01(){
//    Person p;
//    p.m_A = 10;
//    p.m_B = 10;

    Person p(10,10);


//    cout<<p.m_A<<endl;//不能直接输出p
//    cout<<p<<endl;
//    cout<<p;//加上 endl 就报错
    cout<<p<<endl;

}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
