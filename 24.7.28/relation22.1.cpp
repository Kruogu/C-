//
// Created by tianya on 2024/7/30.
//
#include "iostream"
using namespace std;
#include "Point22.1.h"
#include "Circle22.1.h"

//�жϵ��Բ�Ĺ�ϵ  ������һ��Բ��һ����
void isInCircle(Circle &c,Point &p){
//    ��������֮������ƽ�� (x1-x2)^2-(y1-y2)^2   distance  ����
    int distance =
            (c.getCenter().getX()-p.getX()) * (c.getCenter().getX()-p.getX())+
            (c.getCenter().getY()-p.getY()) * (c.getCenter().getY()-p.getY());
//    ����뾶��ƽ��
    int rDistance = c.getR() * c.getR();

//    �жϹ�ϵ
    if(distance == rDistance){
        cout<<"����Բ��"<<endl;
    }else if(distance > rDistance){
        cout<<"����Բ��"<<endl;
    } else{
        cout<<"����Բ��"<<endl;
    }
}

int main(){

//    ����Բ
    Circle c1;
    c1.setR(10); //�뾶Ϊ 10
    Point center;
    center.setX(10);    // Բ������Ϊ (10,0)
    center.setY(0);
    c1.setCenter(center);

//    ������
    Point p1;
    p1.setX(10); // p1������Ϊ��(21,0)
    p1.setY(10);

//    �жϹ�ϵ
    isInCircle(c1,p1);

    cout<<"HelloWorld"<<endl;
    return 0;
}