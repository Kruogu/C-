//
// Created by tianya on 2024/11/3.
//

#ifndef INC_24_11_03_BOSS_H
#define INC_24_11_03_BOSS_H
#include "03worker.h"

//6.4�����ϰ���
class Boss:public Worker{
public:
    //    ���캯��
    Boss(int id,string name,int dId);

//    ��ʾ������Ϣ
    virtual void showInfo();

//    ��ȡְ����λ����
    virtual string getDeptName();
};
#endif //INC_24_11_03_BOSS_H
