//
// Created by tianya on 2024/11/3.
//

#ifndef INC_24_11_03_02WORKERMANAGER_H
#define INC_24_11_03_02WORKERMANAGER_H

#pragma onceonce//��ֹͷ�ļ��ظ�����
#include "iostream"//�������������ͷ�ļ�
using namespace std;//ʹ�ñ�׼�����ռ�
#include "03worker.h"
#include "04employee.h"
#include "05manager.h"
#include "06boss.h"

//8.1�趨�ļ�·��
#include "fstream"
#define FILENAME "empFile.txt"//ָ���ļ�Ŀ¼���ļ���

//���в���Ҫдʵ��
class WorkerManager{
public:
    //���캯��
    WorkerManager();

//  3.չʾ�˵�  �������������û��Ĺ�ͨ����
    void Show_Menu();

//    5.2ʵ���˳�ϵͳ
    void Exitsystem();


//    7.2����ʵ��
//    ��¼ְ������   �ļ�����������
    int m_EmpNum;
    //ְ�������ָ��
    Worker ** m_EmpArray;//��Ҫ������  ����ָ��

//    ���ְ��
    void Add_Emp();

//    8.2��Ա��������  �����ļ�
    void save();

//    9.1�ļ�δ����  �ж��ļ��Ƿ�Ϊ�� ��־
    bool m_FileIsEmpty;//Empty ��

//    9.3�ļ������ұ���ְ������
//    9.3.1��ȡ��¼��ְ������  ͳ���ļ�������
    int get_EmpNum();

//    9.3.2��ʼ������  ��ʼ��Ա��
    void init_Emp();

//    10.1��ʾְ����������
    void Show_Emp();

//    11.1ɾ��ְ����������  employee  ְ��/��Ա
    void Del_Emp();

//    11.2ְ���Ƿ���ں�������
    //����ְ������ж�ְ���Ƿ���ڣ������ڷ���ְ����������λ�ã������ڷ���-1
    int IsExist(int id); // Exist  ����

//    12.1�޸�ְ����������   modification  �޸�
    void Mod_Emp();

//    13.1����ְ����������
    void Find_Emp();

//    14.1����������
    void Sort_Emp();

//    15.1��պ�������
    void Clean_File();


//    ��������
    ~WorkerManager();
};

void test01();


#endif //INC_24_11_03_02WORKERMANAGER_H
