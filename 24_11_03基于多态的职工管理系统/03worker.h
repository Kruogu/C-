//
// Created by tianya on 2024/11/3.
//

#ifndef INC_24_11_03_WORKER_H
#define INC_24_11_03_WORKER_H

#pragma onceonce//��ֹͷ�ļ��ظ�����
#include "iostream"//�������������ͷ�ļ�
using namespace std;//ʹ�ñ�׼�����ռ�




//6.1����ְ��������
class Worker{
public:
//    ��ʾ������Ϣ
    virtual void showInfo() = 0;//���麯��

//    ��ȡ��λ����
//    virtual string getDeptname() = 0;// Dept ����  ��һ��С����  Name ���³������
    virtual string getDeptName() = 0;// Dept ����


    int m_Id;//ְ�����
    string m_Name;//ְ������
    int m_DeptId;//ְ�����ڲ������Ʊ��
};



#endif //INC_24_11_03_WORKER_H
