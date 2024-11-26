//
// Created by tianya on 2024/11/23.
//

#ifndef INC_2024_11_23_04TEACHER_H
#define INC_2024_11_23_04TEACHER_H

#pragma once //防止头文件重复包含
#include "iostream"
using namespace std;
#include "02Identiy.h"

//教师类设计
class Teacher:public Identity{
public:
    //    默认构造
    Teacher();

//    有参构造 参数：职工编号、姓名、密码
    Teacher(int empId,string name,string pwd);

//    菜单界面  重写纯虚函数
    virtual void openMenu();

//    查看所有预约
    void showAllOrer();

//    审核预约
    void validOrder(); //valid  有效的

//    职工编号
    int m_EmpId;    //employee  雇员
};
#endif //INC_2024_11_23_04TEACHER_H
