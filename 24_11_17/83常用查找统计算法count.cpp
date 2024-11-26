//
// Created by tianya on 2024/11/21.
//
//

#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"
//5.2.5常用查找  统计算法 count

//· count(iterator beg, iterator end, value);
//统计元素出现次数
//beg开始迭代器
//end结束迭代器
//value统计的元素


//1、统计内置数据类型
void test01(){
    vector<int>v;

    v.push_back(10);
    v.push_back(40);
    v.push_back(30);
    v.push_back(40);
    v.push_back(20);
    v.push_back(40);

    int num = count(v.begin(),v.end(),40);
    cout<<"40的元素个数为："<<num<<endl;

}


//2、统计自定义数据类型
class Person{
public:
    //类内实现
    Person(string name,int age){
        this->m_Name = name;
        this->m_Age = age;
    }
    //重载时要放在Person类下，报错要检测重载符号是否写错 operator==
    int operator==(const Person &p){//谓词
        if(this->m_Age == p.m_Age){
            return true;
        } else{
            return false;
        }
    }
    string m_Name;
    int m_Age;
};

void test02(){
    vector<Person>v;

    //    准备数据
    Person p1("刘备",35);
    Person p2("曹操",45);
    Person p3("赵云",25);
    Person p4("张飞",30);
    Person p5("关羽",35);

//    将人员插入到容器中
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    Person p("诸葛亮",35);

    int num = count(v.begin(),v.end(),p);
    cout<<"和诸葛亮同岁数的人员个数为："<<num<<endl;

}
int main(){
    test01();
    test02();
    cout<<"HelloWorld"<<endl;
    return 0;
}
