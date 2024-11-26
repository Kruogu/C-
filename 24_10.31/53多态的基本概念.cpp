//
// Created by tianya on 2024/10/31.
//



#include "iostream"
using namespace std;

//多态

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
//    void speak(){
    virtual void speak(){//这个子类的virtual是可写可不写的，都行
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

int main(){
//    doSpeak();
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
