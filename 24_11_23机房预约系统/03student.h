//
// Created by tianya on 2024/11/23.
//

#ifndef INC_2024_11_23_STUDENT_H
#define INC_2024_11_23_STUDENT_H

#pragma once //��ֹͷ�ļ��ظ�����
#include "iostream"
using namespace std;
#include "vector"
//#include "02Identiy.h"
#include "07computerroom.h"
//#include "08orderFile.h"//Ҫ���ú�����������.h,ֱ�ӱ���
#include "08orderFile.cpp"

//#include "fstream"
//#include "06globalfile.h"
//ѧ�������
class Student:public Identity{
public:
//    Ĭ�Ϲ���
    Student();

//    �вι��� ������ѧ�š�����������
    Student(int id,string name,string pwd);

//    �˵�����  ��д���麯��
    virtual void openMenu();

//    ����ԤԼ
    void applyOrder();//apply ����  order˳�� ����

//    �鿴����ԤԼ
    void showMyOerder();

//    �鿴����ԤԼ
    void showAllOrer();

//    ȡ��ԤԼ
    void cancelOrder();//cancel ȡ��

//    8.2.1��ȡ������Ϣ  ��������
    vector<ComputerRoom> vCom;

//    ѧ��ѧ��
    int m_Id;
};
#endif //INC_2024_11_23_STUDENT_H
