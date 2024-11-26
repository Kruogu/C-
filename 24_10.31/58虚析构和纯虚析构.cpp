//
// Created by tianya on 2024/11/1.
//
#include "iostream"
using namespace std;
//虚析构和纯虚析构
class Animal{
public:
    Animal(){
        cout<<" Animal的构造函数调用"<<endl;
    }

//    利用虚析构可以解决父类指针释放子类对象时不干净的问题
//    ~Animal(){ // 为了避免内存泄露，父类改成虚析构就会先释放子类中的析构
    virtual ~Animal(){
        cout<<" Animal的虚析构函数调用"<<endl;
    }

//    纯虚析构  需要声明也需要实现   和上面的虚析构只能有 一个
//    有了纯虚析构之后，这个类也属于抽象类，无法实例化对象
//    virtual ~Animal() = 0;//不能为空，也需要在下面写函数内部实现

//    纯虚函数
    virtual void speak() = 0;
};

//Animal::~Animal() {
//    cout<<" Animal的纯虚析构函数调用"<<endl;
//}

class Cat:public Animal{
public:
    Cat(string name){
        cout<<"Cat的构造函数调用"<<endl;
        m_Name = new string(name);
    }
    virtual void speak() {
        cout<<*m_Name<<"小猫在说话"<<endl;
    }
    ~Cat(){//释放内存
        if(m_Name != NULL){
            cout<<"Cat的析构函数调用"<<endl;
            delete m_Name;
            m_Name = NULL;
        }
    }
    string * m_Name;
};

void test01(){
    Animal *animal = new Cat("Tom");
    animal->speak();
//    父类指针在析构时候不会调用子类中析构函数，导致子类如果有堆区属性，出现内存泄漏
    delete animal;
}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
