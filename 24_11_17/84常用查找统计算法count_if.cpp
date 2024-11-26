//
// Created by tianya on 2024/11/21.
//
//

#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"
//5.2.6常用查找  统计算法 count_if

//· count_if(iterator beg, iterator end,_Pred);
//按条件统计元素出现次数
//beg开始迭代器
//end结束达代器
//_Pred 谓词



//1、统计内置数据类型
//谓词
class Greater20{
public:
    bool operator()(int val){
        return val>20;
    }
};
void test01(){
    vector<int>v;

    v.push_back(10);
    v.push_back(40);
    v.push_back(30);
    v.push_back(40);
    v.push_back(20);
    v.push_back(40);

//    查找有多少大于20的数
    int num = count_if(v.begin(),v.end(),Greater20());
    cout<<"大于20的元素个数为："<<num<<endl;//大于20的元素个数为：4

//    用lambda表达式实现可能更简单
}


//2、统计自定义数据类型
class Person{
public:
    //类内实现
    Person(string name,int age){
        this->m_Name = name;
        this->m_Age = age;
    }
//    可以实现和对象做比较
    bool operator()(const Person &p){
        return p.m_Age> this->m_Age;
    }
    string m_Name;
    int m_Age;
};

//谓词
class AgeGreater20{
public:
    //可以实现和数字做比较，如何和Person对象做比较？将重载放在Person类内实现
    bool operator()(const Person &p){
        return p.m_Age>25;
    }
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

    Person p("诸葛亮",30);

    int num1 = count_if(v.begin(),v.end(),p);
    cout<<"比诸葛亮岁数大的人员个数为："<<num1<<endl;

    int num2 = count_if(v.begin(),v.end(),AgeGreater20());
    cout<<"比25岁数大的人员个数为："<<num2<<endl;

}
int main(){
    test01();
    test02();
    cout<<"HelloWorld"<<endl;
    return 0;
}
