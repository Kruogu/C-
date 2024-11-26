//
// Created by tianya on 2024/11/3.
//

#ifndef INC_24_11_03_02WORKERMANAGER_H
#define INC_24_11_03_02WORKERMANAGER_H

#pragma onceonce//防止头文件重复包含
#include "iostream"//包含输入输出流头文件
using namespace std;//使用标准命名空间
#include "03worker.h"
#include "04employee.h"
#include "05manager.h"
#include "06boss.h"

//8.1设定文件路径
#include "fstream"
#define FILENAME "empFile.txt"//指定文件目录和文件名

//类中不需要写实现
class WorkerManager{
public:
    //构造函数
    WorkerManager();

//  3.展示菜单  功能描述：与用户的沟通界面
    void Show_Menu();

//    5.2实现退出系统
    void Exitsystem();


//    7.2功能实现
//    记录职工人数   文件中人数个数
    int m_EmpNum;
    //职工数组的指针
    Worker ** m_EmpArray;//重要！！！  二级指针

//    添加职工
    void Add_Emp();

//    8.2成员函数声明  保存文件
    void save();

//    9.1文件未创建  判断文件是否为空 标志
    bool m_FileIsEmpty;//Empty 空

//    9.3文件存在且保存职工数据
//    9.3.1获取记录的职工人数  统计文件中人数
    int get_EmpNum();

//    9.3.2初始化数组  初始化员工
    void init_Emp();

//    10.1显示职工函数声明
    void Show_Emp();

//    11.1删除职工函数声明  employee  职工/雇员
    void Del_Emp();

//    11.2职工是否存在函数声明
    //按照职工编号判断职工是否存在，若存在返回职工在数组中位置，不存在返回-1
    int IsExist(int id); // Exist  存在

//    12.1修改职工函数声明   modification  修改
    void Mod_Emp();

//    13.1查找职工函数声明
    void Find_Emp();

//    14.1排序函数声明
    void Sort_Emp();

//    15.1清空函数声明
    void Clean_File();


//    析构函数
    ~WorkerManager();
};

void test01();


#endif //INC_24_11_03_02WORKERMANAGER_H
