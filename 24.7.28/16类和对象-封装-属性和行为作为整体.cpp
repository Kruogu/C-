//
// Created by tianya on 2024/7/28.
//
#include "iostream"
using namespace std;
//#define PI 3.14
const double PI = 3.14;
//设计一个圆类，求圆的周长
//圆求周长的公式：2米PI*半径
//class代表设计一个类，类后面紧跟着的就是类名称
class Circle{
//    访问权限
//    公共权限
public:
//    属性
//    半径
    int m_r;

//    行为
//    获取圆的周长
    double calculateZC() {  //calculate 计算
        return 2 * PI * m_r;
    }

};
double yuan(int r){
    return 2*r*PI;
}
int main(){
    cout<<"园的周长："<<yuan(10)<<endl;

//    通过圆类创建具体的圆（对象）
//    实例化(通过一个类创建一个对象的过程)
    Circle c1;
//    给圆对象的属性进行赋值
    c1.m_r = 10;

    cout<<"园的周长："<<c1.calculateZC()<<endl;

    cout<<"HelloWorld"<<endl;
    return 0;
}
