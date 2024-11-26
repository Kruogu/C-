//
// Created by tianya on 2024/11/1.
//
#include "iostream"
using namespace std;

//多态案例一 - 计算器类

//分别利用普通的写法和多态技术实现计算器
//普通写法
class Calculator{
public:
    int getResult(string oper){//获取运算结果
        if(oper == "+"){
            return m_Num1+m_Num2;
        }
        else if(oper == "-"){
            return m_Num1-m_Num2;
        }
        else if(oper == "*"){
            return m_Num1*m_Num2;
        }
        //如果想扩展新的功能，需求修改源码  除法
        //在真实开发中 提倡 开闭原则
        //开闭原则：对扩展进行开放，对修改进行关闭

    }
    int m_Num1;//操作数1
    int m_Num2;//操作数2
};


//利用多态实现计算器
//多态好处：
//    1.组织结构清晰
//    2.可读性强
//    3.对于前期和后期扩展以及维护性高
//实现计算器抽象类 基类
class AbstractCalculator{
public:
    virtual int getResult(){ //写成虚函数
        return 0;
    }
    int m_Num1;
    int m_Num2;
};

//加法计算器类
class AddCalcultor:public AbstractCalculator{
public:
//    int getResult(string oper){//获取运算结果
//        if(oper == "+"){
//            return m_Num1+m_Num2;
//        }
//    }
    int getResult(){//获取运算结果
            return m_Num1+m_Num2;
        cout<<m_Num1<<"+"<<m_Num1<<"="<<m_Num1+m_Num2<<endl;
    }
};

//减法计算器类  subtraction
class SubCalcultor:public AbstractCalculator{
public:
    int getResult(){//获取运算结果
        return m_Num1-m_Num2;
        cout<<m_Num1<<"-"<<m_Num1<<"="<<m_Num1-m_Num2<<endl;
    }
};
//乘法计算器类  multiplication
class MulCalcultor:public AbstractCalculator{
public:
    int getResult(){//获取运算结果
        return m_Num1*m_Num2;
        cout<<m_Num1<<"*"<<m_Num1<<"="<<m_Num1*m_Num2<<endl;
    }
};
void test01(){
    //创建计算器对象
    Calculator c;
    c.m_Num1 = 10;
    c.m_Num2 = 10;
    cout<<c.m_Num1<<"+"<<c.m_Num2<<"="<<c.getResult("+")<<endl;
    cout<<c.m_Num1<<"-"<<c.m_Num2<<"="<<c.getResult("-")<<endl;
    cout<<c.m_Num1<<"*"<<c.m_Num2<<"="<<c.getResult("*")<<endl;
}

void dogetResult(AbstractCalculator & abstractCalculator){
    abstractCalculator.getResult();
}
void test02(){
//    多态使用条件
//      父类指针或者引用指向子类对象

//    加法运算
    AbstractCalculator *abc = new AddCalcultor;//创建堆区
    abc->m_Num1 = 20;
    abc->m_Num2 = 20;
    cout<<abc->m_Num1<<"+"<<abc->m_Num1<<"="<<abc->getResult()<<endl;
//    用完后记得销毁
    delete abc;

//    减法运算
    abc = new SubCalcultor;
    abc->m_Num1 = 20;
    abc->m_Num2 = 20;
    cout<<abc->m_Num1<<"-"<<abc->m_Num1<<"="<<abc->getResult()<<endl;
    delete abc;

    //    乘法运算
    abc = new MulCalcultor;
    abc->m_Num1 = 20;
    abc->m_Num2 = 20;
    cout<<abc->m_Num1<<"*"<<abc->m_Num1<<"="<<abc->getResult()<<endl;
    delete abc;
}

//    引用
void test03(){
    AddCalcultor a;
    a.m_Num1 = 30;
    a.m_Num2 = 30;
    dogetResult(a);

    SubCalcultor s;
    s.m_Num1 = 30;
    s.m_Num2 = 30;
    dogetResult(s);

    MulCalcultor m;
    m.m_Num1 = 30;
    m.m_Num2 = 30;
    dogetResult(m);
}
int main(){
//    test01();//常规写法
//    test02();//指针  多态
    test03();//引用  多态
    cout<<"HelloWorld"<<endl;
    return 0;
}
