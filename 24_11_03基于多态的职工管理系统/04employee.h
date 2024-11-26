//
// Created by tianya on 2024/11/3.
//

#ifndef INC_24_11_03_EMPLOYEE_H
#define INC_24_11_03_EMPLOYEE_H

#pragma onceonce//防止头文件重复包含
#include "iostream"//包含输入输出流头文件
using namespace std;//使用标准命名空间
#include "03worker.h"
//6.2创建普通员工类
class Employee:public Worker{
public:
//    构造函数
    Employee(int id,string name,int dId);

//    显示个人信息
    virtual void showInfo();

//    获取职工岗位名称
//    virtual string getDeptName();
    string getDeptName();
//    string getDeptname();//大小写导致程序崩溃  Name

};
#endif //INC_24_11_03_EMPLOYEE_H
