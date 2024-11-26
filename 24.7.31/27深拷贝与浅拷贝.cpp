//
// Created by tianya on 2024/8/1.
//

#include "iostream"
using namespace std;

//深拷贝与浅拷贝
class Person{
public:
    Person(){
        cout<<"Person默认构造函数调用"<<endl;

    }
    Person(int age,int height){
        cout<<"Person有参构造函数调用"<<endl;
        m_Age = age;
        m_Height = new int(height);//把数据创建到堆区
    }
//    Person(const Person &p){
//        cout<<"Person拷贝构造函数调用"<<endl;
//        m_Age = p.m_Age;
//    }

    //自己实现拷贝构造函数，解决浅拷贝带来的问题
    Person(const Person &p){
        cout<<"Person 拷贝构造函数的调用"<<endl;
        m_Age = p.m_Age;
        m_Height = p.m_Height;//编译器默认实现就是这行代码

//        深拷贝操作
        m_Height = new int(*p.m_Height);
    }

    ~Person(){
//        析构代码，将堆区开辟数据做释放操作
//        浅拷贝带来的问题就是堆区的内存重复释放
//        浅拷贝的问题要利用深拷贝进行解决
        if(m_Height != NULL){
            delete m_Height;    //释放内存
            m_Height = NULL;    //为了防止野指针出现，赋值为空
        }
        cout<<"Person析构函数调用"<<endl;
    }

    int m_Age;  //年龄
    int *m_Height;  //身高
};

void test01(){
    Person p1(18,160);
    cout<<"p1的年龄为："<<p1.m_Age
        <<" p1的身高为："<<*p1.m_Height<<endl;

    Person p2(p1);
    cout<<"p2的年龄为："<<p2.m_Age
        <<" p2的身高为："<<*p2.m_Height<<endl;
}
int main(){

    test01();

    cout<<"HelloWorld"<<endl;
    return 0;
}
