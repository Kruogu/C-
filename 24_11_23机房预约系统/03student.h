//
// Created by tianya on 2024/11/23.
//

#ifndef INC_2024_11_23_STUDENT_H
#define INC_2024_11_23_STUDENT_H

#pragma once //防止头文件重复包含
#include "iostream"
using namespace std;
#include "vector"
//#include "02Identiy.h"
#include "07computerroom.h"
//#include "08orderFile.h"//要调用函数，不能用.h,直接报错
#include "08orderFile.cpp"

//#include "fstream"
//#include "06globalfile.h"
//学生类设计
class Student:public Identity{
public:
//    默认构造
    Student();

//    有参构造 参数：学号、姓名、密码
    Student(int id,string name,string pwd);

//    菜单界面  重写纯虚函数
    virtual void openMenu();

//    申请预约
    void applyOrder();//apply 申请  order顺序 订单

//    查看自身预约
    void showMyOerder();

//    查看所有预约
    void showAllOrer();

//    取消预约
    void cancelOrder();//cancel 取消

//    8.2.1获取机房信息  机房容器
    vector<ComputerRoom> vCom;

//    学生学号
    int m_Id;
};
#endif //INC_2024_11_23_STUDENT_H
