//
// Created by tianya on 2024/11/3.
//

#ifndef INC_24_11_03_BOSS_H
#define INC_24_11_03_BOSS_H
#include "03worker.h"

//6.4创建老板类
class Boss:public Worker{
public:
    //    构造函数
    Boss(int id,string name,int dId);

//    显示个人信息
    virtual void showInfo();

//    获取职工岗位名称
    virtual string getDeptName();
};
#endif //INC_24_11_03_BOSS_H
