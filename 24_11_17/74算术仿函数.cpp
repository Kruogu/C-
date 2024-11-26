//
// Created by tianya on 2024/11/20.
//
#include "iostream"
using namespace std;
#include "functional"//内建函数对象头文件

//4.3.2算术仿函数

//template < class T >  plus <T>           //加法仿函数
//template < class T >  minus <T>          //减法仿函数
//template < class T > multiplies  <T>     //乘法仿函数
//template < class T > divides <T>         //除法仿函数
//template < class T > modulus <T>         //取模仿函数
//template < class T > negate <T>          //取反仿函数

//内建函数对象
//negate 一元仿函数 取反仿函数
void test01(){
    negate<int>n;
    n(50);
    cout<<n(50)<<endl;//取反  -50
}

//plus   二元仿函数 加法
void test02(){
    plus<int>p;//默认两个数同种数据类型
    cout<<p(50,50)<<endl;//相加  100
}
int main(){
    test01();
    test02();
    cout<<"HelloWorld"<<endl;
    return 0;
}
