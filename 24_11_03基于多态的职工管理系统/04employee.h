//
// Created by tianya on 2024/11/3.
//

#ifndef INC_24_11_03_EMPLOYEE_H
#define INC_24_11_03_EMPLOYEE_H

#pragma onceonce//��ֹͷ�ļ��ظ�����
#include "iostream"//�������������ͷ�ļ�
using namespace std;//ʹ�ñ�׼�����ռ�
#include "03worker.h"
//6.2������ͨԱ����
class Employee:public Worker{
public:
//    ���캯��
    Employee(int id,string name,int dId);

//    ��ʾ������Ϣ
    virtual void showInfo();

//    ��ȡְ����λ����
//    virtual string getDeptName();
    string getDeptName();
//    string getDeptname();//��Сд���³������  Name

};
#endif //INC_24_11_03_EMPLOYEE_H
