//
// Created by tianya on 2024/11/23.
//

#ifndef INC_2024_11_23_IDENTIY_H
#define INC_2024_11_23_IDENTIY_H

#pragma once //��ֹͷ�ļ��ظ�����
#include "iostream"
using namespace std;


//��ݳ������ ����
class  Identity{
public:
//    �����˵�  ���麯��
    virtual void openMenu() = 0;//�� �˵�

    string m_Name;//�û���
    string m_Pwd;//����
};

#endif //INC_2024_11_23_IDENTIY_H
