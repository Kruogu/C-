//
// Created by tianya on 2024/7/28.
//
//示例2：设计一个学生类，属性有姓名和学号，
//可以给姓名和学号赋值，可以显示学生的姓名和学号
#include "iostream"
using namespace std;

//设计学生类
class Student{

public://公共权限
    //类中的属性和行为我们统一称为成员
//    属性    成员属性    成员变量
//    行为    成员属性    成员函数
    string m_Name;//姓名
    int m_Id;   //学号

//    行为
//    显示姓名和学号
public:
    void showStudent(){
        cout<<"姓名："<<m_Name<<" 学号："<< m_Id<<endl;
    }
//    给姓名赋值
    void setName(string name){
        m_Name = name;
//        m_Id = id;
    }
//    给学号赋值
    void setId(int id){
        m_Id = id;
    }
};
int main(){

//    创建一个具体的学生，实例化对象
    Student s1;
//    给s1对象，进行属性赋值操作
    s1.m_Name = "张三";
    s1.m_Id = 1;
    //显示学生信息
    s1.showStudent();

    Student s2;
    s1.m_Name = "李四";
    s1.m_Id = 2;
    s1.showStudent();

    Student s3;
    s3.setName("王五");
    s3.setId(99);
    s3.showStudent();
    cout<<"HelloWorld"<<endl;
    return 0;
}
