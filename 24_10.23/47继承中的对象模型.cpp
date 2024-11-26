//
// Created by tianya on 2024/10/24.
//

//利用开发人员命令提示工具查看对象模型

//E:\0Work\0workspace\24_10.23
//E:\0Work\0workspace\24_10.23\47继承中的对象模型.cpp
//1.CLion可以复制路径的，然后用win+R键输入cmd打开命令行  命令行不行
//1. 在任务栏搜索框中搜索 vs  用管理员身份打开x64 Native Tools Command Prompt for VS 2022即可正常使用
//2.先跳转到E盘， E:
//3.输入 cd E:\0Work\0workspace\24_10.23
//4.查看目录  dir
//5.  输入 cl /d1 reportSingleClassLayout + 要查看的类 空格 输入47按Tab键 后面自动补全   //报告 单个 类的 布局
//5.   cl /d1 reportSingleClassLayoutSon 47继承中的对象模型.cpp


#include "iostream"
using namespace std;

//继承中的对象模型

class Base{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};

class Son:public Base{
public:
    int m_D;
};

void test01(){
//     4 12 16   // 结果是 16  说明私有属性也继承了
//    父类中所有非静态成员属性都会被子类继承下去
//    父类中私有成员属性是被编译器给隐藏了，因此是访问不到，但是确实被继承下去了
    cout<<"size of Son = "<<sizeof(Son)<<endl;
}


int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
