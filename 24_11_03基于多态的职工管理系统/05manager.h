//
// Created by tianya on 2024/11/3.
//

#ifndef INC_24_11_03_MANAGER_H
#define INC_24_11_03_MANAGER_H

#pragma onceonce//��ֹͷ�ļ��ظ�����
#include "iostream"//�������������ͷ�ļ�
using namespace std;//ʹ�ñ�׼�����ռ�
#include "03worker.h"

//6.3����������
class Manager:public Worker{
public:
    //    ���캯��
    Manager(int id,string name,int dId);

//    ��ʾ������Ϣ
    virtual void showInfo();

//    ��ȡְ����λ����
    virtual string getDeptName();
};

#endif //INC_24_11_03_MANAGER_H
