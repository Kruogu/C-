//
// Created by tianya on 2024/7/30.
//

#ifndef INC_24_7_28_CIRCLE22_1_H
#define INC_24_7_28_CIRCLE22_1_H
#include "iostream"
using namespace std;
#include "Point22.1.h"
//Բ��
class Circle{
public:
//    ���ð뾶
    void setR(int r);
//    ��ȡ�뾶
    int getR();
//    ����Բ��
    void setCenter(Point center);
//    ��ȡԲ��
    Point getCenter();

private:
    int m_R;    //�뾶
//    ��һ�����п�������һ������Ϊ�����еĳ�Ա
    Point m_Center; //Բ��
};
#endif //INC_24_7_28_CIRCLE22_1_H
