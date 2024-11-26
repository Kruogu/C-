//
// Created by tianya on 2024/7/30.
//

#ifndef INC_24_7_28_POINT22_1_H
#define INC_24_7_28_POINT22_1_H
#include "iostream"
using namespace std;

//点类  .h中只写函数声明，不写实现
class Point{
public:
    //设置x
    void setX(int x);
    //获取x
    int getX();
    //设置y
    void setY(int y);
    //获取y
    int getY();
private:
    int m_X;    //圆心位于x坐标轴的位置
    int m_Y;    //圆心位于y坐标轴的位置
};




#endif //INC_24_7_28_POINT22_1_H
