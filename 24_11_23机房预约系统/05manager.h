//
// Created by tianya on 2024/11/23.
//

#ifndef INC_2024_11_23_05MANAGER_H
#define INC_2024_11_23_05MANAGER_H

#pragma once //��ֹͷ�ļ��ظ�����
#include "iostream"
using namespace std;
#include "vector"       //����
#include "algorithm"    //�㷨��  ����for_each
#include "02Identiy.h"
#include "06globalfile.h"
#include "07computerroom.h"
//����Ա�����
class Manager:public Identity{
public:
//    Ĭ�Ϲ���
    Manager();

//    �вι��� ������ְ����š�����������
    Manager(string name,string pwd);

//    �˵�����  ��д���麯��
    virtual void openMenu();

//    ����˺�
    void addPerson();

//    �鿴�˺�
    void showPerson();

//    ���ڿ��Լ�һ��ɾ���˺Ź���

//    �鿴������Ϣ
    void showComputer();

//    ���ԤԼ��¼
    void cleanFile();

//    7.2.2ȥ�ز���
//    ��ʼ������
    void initVertor();

//    7.2.2.2ȥ�غ�����װ
//    ����1 ���ѧ��/ְ����   ����2  �������
//    ����ظ�������������id,�������ͣ�����ֵ��(true�������ظ���false����û���ظ�)
    bool checkRepeat(int id,int type);

//    7.4.3��ʼ��������Ϣ����
    vector<ComputerRoom> vCom;

//    ѧ������
    vector<Student> vStu; //��Ա����

//    ��ʦ����
    vector<Teacher> vTea; //��Ա����

    int m_Select;//����ѡ��

};


#endif //INC_2024_11_23_05MANAGER_H
