//
// Created by tianya on 2024/7/29.
//
#include "iostream"
using namespace std;

class C1{
    int m_A; //默认权限是私有
};

struct C2{
    int m_A; //默认权限是公共
};


int main(){
    //structi和class区别
    //·struct默认权限为公共  公共public
    //·class默认权限为私有  私有private
    C1 c1;
    c1.m_A = 100;//报错，私有权限
//    在class里默认权限私有，因此类外不可以访问

    C2 c2;
    c2.m_A = 100;//不报错，公共权限
//    在struct默认的权限为公共，因此可以访问

    cout<<"HelloWorld"<<endl;
    return 0;
}
