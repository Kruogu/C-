//
// Created by tianya on 2024/7/30.
//

#ifndef INC_24_7_28_CIRCLE22_1_H
#define INC_24_7_28_CIRCLE22_1_H
#include "iostream"
using namespace std;
#include "Point22.1.h"
//圆类
class Circle{
public:
//    设置半径
    void setR(int r);
//    获取半径
    int getR();
//    设置圆心
    void setCenter(Point center);
//    获取圆心
    Point getCenter();

private:
    int m_R;    //半径
//    在一个类中可以让另一个类作为本来中的成员
    Point m_Center; //圆心
};
#endif //INC_24_7_28_CIRCLE22_1_H
