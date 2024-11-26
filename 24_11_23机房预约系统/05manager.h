//
// Created by tianya on 2024/11/23.
//

#ifndef INC_2024_11_23_05MANAGER_H
#define INC_2024_11_23_05MANAGER_H

#pragma once //防止头文件重复包含
#include "iostream"
using namespace std;
#include "vector"       //容器
#include "algorithm"    //算法库  遍历for_each
#include "02Identiy.h"
#include "06globalfile.h"
#include "07computerroom.h"
//管理员类设计
class Manager:public Identity{
public:
//    默认构造
    Manager();

//    有参构造 参数：职工编号、姓名、密码
    Manager(string name,string pwd);

//    菜单界面  重写纯虚函数
    virtual void openMenu();

//    添加账号
    void addPerson();

//    查看账号
    void showPerson();

//    后期可以加一个删除账号功能

//    查看机房信息
    void showComputer();

//    清空预约记录
    void cleanFile();

//    7.2.2去重操作
//    初始化容器
    void initVertor();

//    7.2.2.2去重函数封装
//    参数1 检测学号/职工号   参数2  检测类型
//    检测重复参数：（传入id,传入类型）返回值：(true代表有重复，false代表没有重复)
    bool checkRepeat(int id,int type);

//    7.4.3初始化机房信息容器
    vector<ComputerRoom> vCom;

//    学生容器
    vector<Student> vStu; //成员变量

//    教师容器
    vector<Teacher> vTea; //成员变量

    int m_Select;//测试选择

};


#endif //INC_2024_11_23_05MANAGER_H
