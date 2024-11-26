//
// Created by tianya on 2024/7/30.
//
#include "iostream"
using namespace std;

//点和圆关系判断
//        点到圆心的距离 == 半径  点在圆上
//        点到圆心的距离 >  半径  点在圆外
//        点到圆心的距离 <  半径  点在圆内
//        点到圆心的距离？？？
//            √(x1-x2)^2+(y1-y2)^2 = 两点之间的距离  和 m_R做对比
//                                             或者和 m_R^2做对比

//点类
class Point{
public:
    //设置x
    void setX(int x){
        m_X = x;
    }
    //获取x
    int getX(){
        return m_X;
    }
    //设置y
    void setY(int y){
        m_Y = y;
    }
    //获取y
    int getY(){
        return m_Y;
    }

private:
    int m_X;    //圆心位于x坐标轴的位置
    int m_Y;    //圆心位于y坐标轴的位置
};

//圆类
class Circle{
public:
//    设置半径
    void setR(int r){
        m_R = r;
    }
//    获取半径
    int getR(){
        return m_R;
    }
//    设置圆心
    void setCenter(Point center){
        m_Center = center;
    }
//    获取圆心
    Point getCenter(){
        return m_Center;
    }

private:
    int m_R;    //半径
//    在类中可以让另一个类作为本来中的成员
    Point m_Center; //圆心
};

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
    p1.setX(21); // p1点坐标为：(21,0)
    p1.setY(0);

//    判断关系
    isInCircle(c1,p1);

    cout<<"HelloWorld"<<endl;
    return 0;
}
