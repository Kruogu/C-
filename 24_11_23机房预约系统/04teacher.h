//
// Created by tianya on 2024/11/23.
//

#ifndef INC_2024_11_23_04TEACHER_H
#define INC_2024_11_23_04TEACHER_H

#pragma once //��ֹͷ�ļ��ظ�����
#include "iostream"
using namespace std;
#include "02Identiy.h"

//��ʦ�����
class Teacher:public Identity{
public:
    //    Ĭ�Ϲ���
    Teacher();

//    �вι��� ������ְ����š�����������
    Teacher(int empId,string name,string pwd);

//    �˵�����  ��д���麯��
    virtual void openMenu();

//    �鿴����ԤԼ
    void showAllOrer();

//    ���ԤԼ
    void validOrder(); //valid  ��Ч��

//    ְ�����
    int m_EmpId;    //employee  ��Ա
};
#endif //INC_2024_11_23_04TEACHER_H
