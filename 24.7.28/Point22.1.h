//
// Created by tianya on 2024/7/30.
//

#ifndef INC_24_7_28_POINT22_1_H
#define INC_24_7_28_POINT22_1_H
#include "iostream"
using namespace std;

//����  .h��ֻд������������дʵ��
class Point{
public:
    //����x
    void setX(int x);
    //��ȡx
    int getX();
    //����y
    void setY(int y);
    //��ȡy
    int getY();
private:
    int m_X;    //Բ��λ��x�������λ��
    int m_Y;    //Բ��λ��y�������λ��
};




#endif //INC_24_7_28_POINT22_1_H
