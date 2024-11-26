//
// Created by tianya on 2024/10/28.
//

//打开vs工具
//E:
//cd E:\0Work\0workspace\24_10.23
//dir
//cl /d1 reportSingleClassLayoutSheepTuo 52菱形继承.cpp

#include "iostream"
using namespace std;

//菱形继承


//动物类
class Animal{
public:
    int m_Age;
};

//利用虚继承解决菱形继承的问题  virtual修饰  虚拟
//继承之前 加上关键字virtual 变为虚继承
//Animal类称为 虚基类
//vbptr 为虚基类指针  指向   vbtable虚基类表
//        v-vIrtua
//        b base
//        ptr pointer
//羊类
//class Sheep:public Animal{
class Sheep:virtual public Animal{

};

//骆驼类
//class Tuo:public Animal{
class Tuo:virtual public Animal{

};

//羊驼 （草泥马）
class SheepTuo:public Sheep,public Tuo{

};

void test01(){
    SheepTuo st;
//    st.m_Age = 18;//多继承不明确
    st.Sheep::m_Age = 18;
    st.Tuo::m_Age = 28;

//    当菱形继承，两个类拥有相同数据，需要加以作用域区分
    cout<<"st.Sheep::m_Age："<<st.Sheep::m_Age<<endl;
    cout<<"st.Tuo::m_Age："<<st.Tuo::m_Age<<endl;

//    这份数据我们知道只有有一份就可以，菱形继承导致数据有两份，资源浪费
}

int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
