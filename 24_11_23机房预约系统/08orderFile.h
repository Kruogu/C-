//
// Created by tianya on 2024/11/24.
//

#ifndef INC_2024_11_23_08ORDERFILE_H
#define INC_2024_11_23_08ORDERFILE_H

#pragma once //��ֹͷ�ļ��ظ�����
#include "iostream"
using namespace std;
#include "06globalfile.h"
#include "fstream"
#include "map"

//8.3.1����ԤԼ��
class OrderFile{
public:
//    ���캯��
    OrderFile();

//    ����ԤԼ��¼
    void updateOrder();

//    ��¼ԤԼ����
    int m_Size;

//    ��¼����ԤԼ��Ϣ������  key��¼����   value�����¼��ֵ����Ϣ
    map<int,map<string,string>> m_orderData;
};


#endif //INC_2024_11_23_08ORDERFILE_H
