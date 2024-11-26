//
// Created by tianya on 2024/11/10.
//

#include "iostream"
using namespace std;

//1.3.5类模板与继承

template<class T>
class Base{
public:
    T m;
};
//class Son:public Base{//错误，必须要知道父类中的T类型，才能继承给子类
class Son:public Base<int>{
public:
};
void test01(){
    Son s1;//可以通过子类来实例化对象
}

//如果想灵活指定父类中T类型，子类也需要变类模板
template<class T1,class T2>
class Son2:public Base<T2>{
public:
    Son2(){
        cout<<"T1的泛型为："<< typeid(T1).name()<<endl;//i  int
        cout<<"T2的泛型为："<< typeid(T2).name()<<endl;//c  char
    }
    T1 obj;
};
void test02(){
    Son2<int,char> s2;//可以通过子类来实例化对象
}
int main(){
//    test01();
    test02();
    cout<<"HelloWorld"<<endl;
    return 0;
}
