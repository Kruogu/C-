//
// Created by tianya on 2024/7/30.
//
#include "iostream"
using namespace std;
#include "Point22.1.h"
#include "Circle22.1.h"

//判断点和圆的关系  传进来一个圆和一个点
void isInCircle(Circle &c,Point &p){
//    计算两点之间距离的平方 (x1-x2)^2-(y1-y2)^2   distance  距离
    int distance =
            (c.getCenter().getX()-p.getX()) * (c.getCenter().getX()-p.getX())+
            (c.getCenter().getY()-p.getY()) * (c.getCenter().getY()-p.getY());
//    计算半径的平方
    int rDistance = c.getR() * c.getR();

//    判断关系
    if(distance == rDistance){
        cout<<"点在圆上"<<endl;
    }else if(distance > rDistance){
        cout<<"点在圆外"<<endl;
    } else{
        cout<<"点在圆内"<<endl;
    }
}

int main(){

//    创建圆
    Circle c1;
    c1.setR(10); //半径为 10
    Point center;
    center.setX(10);    // 圆心坐标为 (10,0)
    center.setY(0);
    c1.setCenter(center);

//    创建点
    Point p1;
    p1.setX(10); // p1点坐标为：(21,0)
    p1.setY(10);

//    判断关系
    isInCircle(c1,p1);

    cout<<"HelloWorld"<<endl;
    return 0;
}