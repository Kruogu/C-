//
// Created by tianya on 2024/11/24.
//

#ifndef INC_2024_11_23_08ORDERFILE_H
#define INC_2024_11_23_08ORDERFILE_H

#pragma once //防止头文件重复包含
#include "iostream"
using namespace std;
#include "06globalfile.h"
#include "fstream"
#include "map"

//8.3.1创建预约类
class OrderFile{
public:
//    构造函数
    OrderFile();

//    更新预约记录
    void updateOrder();

//    记录预约条数
    int m_Size;

//    记录所有预约信息的容器  key记录条数   value具体记录键值对信息
    map<int,map<string,string>> m_orderData;
};


#endif //INC_2024_11_23_08ORDERFILE_H
