//
// Created by tianya on 2024/11/8.
//

#include "iostream"
using namespace std;

//��ģ���г�Ա��������ʱ��
//��ģ���еĳ�Ա�����ڵ���ʱ�Ŵ���,һ��ʼ���ᴴ��

//template<class NameType,class AgeType>//�������� ģ��
class Person1{
public:
    void showPerson1()
    {
        cout<<"Person1 show"<< endl;
    }
};

class Person2{
public:
    void showPerson2()
    {
        cout<<"Person2 show"<< endl;
    }
};

template<class T>
class MyClass{
public:
    T obj;//obj�Ƕ������˼

    //��ģ���еĳ�Ա����
    void func1()
    {
        obj.showPerson1();

    }
    void func2()
    {
        obj.showPerson2();
    }

};

void test01(){
    MyClass<Person1>m;
//    MyClass<Person1,Person2>m;//����,ֻҪһ������
    m.func1();
//    m.func2();
}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
