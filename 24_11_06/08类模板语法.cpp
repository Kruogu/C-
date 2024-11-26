//
// Created by tianya on 2024/11/8.
//
#include "iostream"
using namespace std;
//1.3.1类模板语法
template<class NameType,class AgeType>//两个类型 模板
class Person{
public:
    Person(NameType name,AgeType age){
        this->m_Name = name;
        this->m_Age = age;
    }

    void showPerson()//打印输出一下
    {
        cout<<"name："<<this->m_Name<< endl;
        cout<<"age："<<this->m_Age<< endl;
    }
    //姓名
//    string m_Name;//把 string 这个属性改成 类模板
    NameType m_Name;
    //年龄
//    int m_Age;
    AgeType m_Age;
};
void test01(){
    Person<string,int> p1("孙悟空",99);
    p1.showPerson();//输出正常
}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
