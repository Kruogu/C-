//
// Created by tianya on 2024/7/29.
//
#include "iostream"
using namespace std;
//练习案例1：设计一个立方体类
//    1.创建立方体类(Cube)
//    2.设计立方体的属性
//    3.设计行为 求出立方体的面积和体积
//    4.分别用全局函数和成员函数判断两个立方体是否相等
//    5.m是mumber成员的意思



class Cube{

public://行为  set获取立方体的 长 宽 高   get返回立方体的 长 宽 高
    void setL(int l){
        m_L = l;
    }
    int getL(){
        return m_L;
    }
    void setW(int w){
        m_W = w;
    }
    int getW(){
        return m_W;
    }
    void setH(int h){
        m_H = h;
    }
    int getH(){
        return m_H;
    }
//    设置立方体的面积  没必要
//    void setArea(int l,int w){
//        m_area = l*w;
//    }
//    获取立方体的表面积
//    calculateS(){ //计算S  写法都可以
    int getArea(){
//        return m_area;    //可以直接计算
        return 2 * (m_L*m_W + m_W*m_H + m_L*m_H);
    }
//    设置立方体的体积  没必要
//    void setVolume(int l,int w,int h){
//        m_volume = l*w*h;
//    }
//    获取立方体的体积
//    calculateV(){ //计算V  写法都可以
    int getVolume(){
//        return m_volume;  没必要
        return m_L*m_W*m_H;
    }

//    利用成员函数判断两个立方体是否相等
    bool isSameByClass(Cube &c){   //值传毒 引用就不会拷贝一份数据了，用原始数据做判断
        if(m_L ==c.getL() && m_W==c.getW() && m_H==c.getH()){
            return true;    //代表两个立方体相等
        }
        return false;   //代表两个立方体不相等
    }
private://属性
    int m_L;    //长
    int m_W;    //宽
    int m_H;    //高
    int m_area;   //表面积
//    int m_volume = m_L*m_W*m_H; //体积 不能计算
    int m_volume; //体积
};

//全局函数 需要传递两个立方体参数进去才可以做判断
//成员函数 只需要传递一个立方体参数进去就可以做判断
//利用全局函数判断两个立方体是否相等
bool isSame(Cube &c1,Cube &c2){   //值传毒 引用就不会拷贝一份数据了，用原始数据做判断
    if(c1.getL()==c2.getL()&&c1.getW()==c2.getW()&&c1.getH()==c2.getH()){
        return true;    //代表两个立方体相等
    }
    return false;   //代表两个立方体不相等
}

int main(){

//    实例化一个立方体对象
    Cube c1;    //创建第一个立方体对象
    c1.setL(10);
    c1.setW(20);
    c1.setH(30);
    cout<<"长："<<c1.getL()<<endl;
    cout<<"宽："<<c1.getW()<<endl;
    cout<<"高："<<c1.getH()<<endl;
//    c.setArea(10,20); 没必要二次输入
    cout<<"c1表面积："<<c1.getArea()<<endl;
//    c.setVolume(10,20,30);  没必要二次输入
    cout<<"c1体积："<<c1.getVolume()<<endl;

    Cube c2;    //创建第二个立方体对象
    c2.setL(10);
    c2.setW(20);
    c2.setH(20);
    cout<<"c2表面积："<<c2.getArea()<<endl;
    cout<<"c2体积："<<c2.getVolume()<<endl;

//    用全局函数判断两个立方体是否相等
    bool ret1 = isSame(c1,c2);
    if(ret1){
        cout<<"全局函数判断：c1和c2是相等的"<<endl;
    } else{
        cout<<"全局函数判断：c1和c2是不相等的"<<endl;
    }

//    用成员函数判断两个立方体是否相等
    int ret2 = c1.isSameByClass(c2); //用c2和c1做对比  而不是c1和c2 有区别
    if(ret2){
        cout<<"成员函数判断：c1和c2是相等的"<<endl;
    } else{
        cout<<"成员函数判断：c1和c2是不相等的"<<endl;
    }

    cout<<"HelloWorld"<<endl;
    return 0;
}
