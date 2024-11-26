//
// Created by tianya on 2024/7/30.
//
#include "iostream"
using namespace std;

//���Բ��ϵ�ж�
//        �㵽Բ�ĵľ��� == �뾶  ����Բ��
//        �㵽Բ�ĵľ��� >  �뾶  ����Բ��
//        �㵽Բ�ĵľ��� <  �뾶  ����Բ��
//        �㵽Բ�ĵľ��룿����
//            ��(x1-x2)^2+(y1-y2)^2 = ����֮��ľ���  �� m_R���Ա�
//                                             ���ߺ� m_R^2���Ա�

//����
class Point{
public:
    //����x
    void setX(int x){
        m_X = x;
    }
    //��ȡx
    int getX(){
        return m_X;
    }
    //����y
    void setY(int y){
        m_Y = y;
    }
    //��ȡy
    int getY(){
        return m_Y;
    }

private:
    int m_X;    //Բ��λ��x�������λ��
    int m_Y;    //Բ��λ��y�������λ��
};

//Բ��
class Circle{
public:
//    ���ð뾶
    void setR(int r){
        m_R = r;
    }
//    ��ȡ�뾶
    int getR(){
        return m_R;
    }
//    ����Բ��
    void setCenter(Point center){
        m_Center = center;
    }
//    ��ȡԲ��
    Point getCenter(){
        return m_Center;
    }

private:
    int m_R;    //�뾶
//    �����п�������һ������Ϊ�����еĳ�Ա
    Point m_Center; //Բ��
};

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
    p1.setX(21); // p1������Ϊ��(21,0)
    p1.setY(0);

//    �жϹ�ϵ
    isInCircle(c1,p1);

    cout<<"HelloWorld"<<endl;
    return 0;
}
