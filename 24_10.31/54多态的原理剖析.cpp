//
// Created by tianya on 2024/11/1.
//
//接53代码

//打开vs工具
//E:
//cd E:\0Work\0workspace\24_10.31
//dir
//cl /d1 reportSingleClassLayoutSheep类名 54tab键
//cl /d1 reportSingleClassLayoutSheepAnimal 54多态的原理剖析.cpp


#include "iostream"
using namespace std;

//多态的原理剖析

//    vfptr - 虚函数（表）指针  指向表
//        v   - virtual
//        f   - function
//        ptr - pointer

//    vftable - 虚函数表 表内记录虚函数的地址
//        v     - virtual
//        f     - function
//        table - table
//        &Animal::speak

//当子类重写父类的虚函数
//        子类中的虚函数表  内部  会替换成  子类的虚数地址
//        &Cat::speak   其他一样继承，但speak函数完全覆盖父类的speak函数
//        当父类的指针或者引用指向子类对象时候，发生多态
//            Animal & animal = cat:
//            animal.speak()

//多态的定义
//由于类的内部发生了结构的改变，多了一个虚函数表指针，指向虚函数表
//虚函数表内部写了虚函数的函数入口地址，当子类重写了虚函数的时候
//会把自身虚函数表中函数替换掉，替换成子类的函数
//当你用父类引用指向子类的对象时，当调用公共speak接口时，
// 就会从子类的里边找函数确值的入口地址，猫就是猫，狗就是狗

//动物类
class Animal{
public:
//    void speak(){
    virtual void speak(){ //虚函数
        cout<<"动物在说话"<<endl;
    }
};

// 派生类 猫类
class Cat:public Animal{
public:
    //重写  函数返回值类型  函数名  参数列表  完全相同  和重载不一样
    void speak(){
//    virtual void speak(){//这个子类的virtual是可写可不写的，都行
        cout<<"小猫在说话"<<endl;
    }
};

// 派生类 狗类
class Dog:public Animal{
public:
    void speak(){
        cout<<"小狗在说话"<<endl;
    }
};

//执行说话的函数
//地址早绑定  在编译阶段就确定函数地址
//如果想执行让猫说话，那这个函数的地址就不能提前绑定，需要在运行阶段进行绑定，地址晚绑定

//动态多态满足条件
// 1、有继承关系
// 2、子类重写父类的虚函数

//动态多态使用
// 父类的指针或者引用 指向 子类对象
void doSpeak(Animal &animal){  //Animal &animal = cat;
    animal.speak();//改成虚继承之后，就是动态函数，传入猫就是猫，狗就是狗
}

void test01(){
    Cat cat;//创建一只猫
//    cat.speak(); // 这样也行  小猫在说话
    doSpeak(cat);//把猫传进去  动物在说话  父类引用接受子类对象
//                  加上虚继承之后  小猫在说话
    Dog dog;
    doSpeak(dog);//小狗在说话

}

void test02(){
    //不加virtual就是显示1
    //加上就是显示8  教学视频显示 4  是个指针
    cout<<"sizeof Animal = "<<sizeof(Animal)<<endl;
}

int main(){
//    test01();
    test02();
    cout<<"HelloWorld"<<endl;
    return 0;
}
