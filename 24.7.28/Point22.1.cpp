//
// Created by tianya on 2024/7/30.
//
// .h 中写过头文件，.cpp中可以不写头文件
//#include "iostream"
//using namespace std;
#include "Point22.1.h"

//点类

//设置x Point作用域下的一个setX函数,代表是成员函数，不是全局函数
void Point::setX(int x){
    m_X = x;
}
//获取x
int Point::getX(){
    return m_X;
}
//设置y
void Point::setY(int y){
    m_Y = y;
}
//获取y
int Point::getY(){
    return m_Y;
}






