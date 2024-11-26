//
// Created by tianya on 2024/11/1.
//
#include "iostream"
using namespace std;

//纯虚函数和抽象类
class Base{
public:
//    virtual void func(){ }
//    纯虚函数
//    只要有一个纯虚函数，这个类也称为抽象类
//    抽象类特点：
//      1.无法实例化对象
//      2.抽象类的子类必须重写抽象类中的纯虚函数，否则也属于抽象类
    virtual void func() = 0; //这样也行
};

class Son:public Base{
public:
    void func(){
        cout<<"Son中的func函数调用"<<endl;
    }
};
void dofunc(Base &base){
    base.func();
}
void test01(){
//    Base b;//报错  不允许使用抽象类对象
//    new Base;//报错  抽象类无法实例化对象

    Son s;//子类必须重写抽象类中的纯虚函数，否则无法实例化对象
    dofunc(s);//可调用  引用

    Base *base = new Son;//指针
    base->func();//可调用
}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
