//
// Created by tianya on 2024/7/23.
//
#include "iostream"
using namespace std;
//#include <string>

struct Student{
    string name;
    int age;
    int score;
}s3{"王五",30,80};

struct teacher{
    int id;
    string name;
    int age;
    struct Student stu;
}stu1;

int main(){

//    2.1 struct Student s1
//    struct Student s1;
    Student s1;
//    给s1属性赋值，通过.访问结构体变量中的属性
    s1.name = "张三";
    s1.age = 18;
    s1.score = 100;
    cout<<"姓名："<<s1.name<<" 年龄："<<s1.age<<" 成绩："<<s1.score<< endl;

//    2.2 struct Student s2 ={...}
    struct Student s2 = {"李四",24,90};
    cout<<"姓名："<<s2.name<<" 年龄："<<s2.age<<" 成绩："<<s2.score<< endl;
//    2.3在定义结构体时顺便创建结构体变量
    cout<<"姓名："<<s3.name<<" 年龄："<<s3.age<<" 成绩："<<s3.score<< endl;

//    结构体指针
    Student *p = &s1;
    cout<<" 姓名："<<p->name
        <<" 年龄："<<p->age
        <<" 成绩："<<p->score<< endl;

    teacher *q = &stu1;
    q->stu = {"赵六"};
    cout<<"姓名："<<q->stu.name<< endl;
    cout<<"HelloWorld"<<endl;
    return 0;
}

