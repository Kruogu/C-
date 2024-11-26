//
// Created by tianya on 2024/11/23.
//

#ifndef INC_2024_11_23_IDENTIY_H
#define INC_2024_11_23_IDENTIY_H

#pragma once //防止头文件重复包含
#include "iostream"
using namespace std;


//身份抽象基类 共性
class  Identity{
public:
//    操作菜单  纯虚函数
    virtual void openMenu() = 0;//打开 菜单

    string m_Name;//用户名
    string m_Pwd;//密码
};

#endif //INC_2024_11_23_IDENTIY_H
