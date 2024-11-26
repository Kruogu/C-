//
// Created by tianya on 2024/11/3.
//

#ifndef INC_24_11_03_MANAGER_H
#define INC_24_11_03_MANAGER_H

#pragma onceonce//防止头文件重复包含
#include "iostream"//包含输入输出流头文件
using namespace std;//使用标准命名空间
#include "03worker.h"

//6.3创建经理类
class Manager:public Worker{
public:
    //    构造函数
    Manager(int id,string name,int dId);

//    显示个人信息
    virtual void showInfo();

//    获取职工岗位名称
    virtual string getDeptName();
};

#endif //INC_24_11_03_MANAGER_H
