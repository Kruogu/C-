//
// Created by tianya on 2024/11/3.
//

#ifndef INC_24_11_03_WORKER_H
#define INC_24_11_03_WORKER_H

#pragma onceonce//防止头文件重复包含
#include "iostream"//包含输入输出流头文件
using namespace std;//使用标准命名空间




//6.1创建职工抽象类
class Worker{
public:
//    显示个人信息
    virtual void showInfo() = 0;//纯虚函数

//    获取岗位名称
//    virtual string getDeptname() = 0;// Dept 部门  就一个小错误  Name 导致程序崩溃
    virtual string getDeptName() = 0;// Dept 部门


    int m_Id;//职工编号
    string m_Name;//职工姓名
    int m_DeptId;//职工所在部门名称编号
};



#endif //INC_24_11_03_WORKER_H
