//
// Created by tianya on 2024/9/17.
//
#include "iostream"
using namespace std;
//��ָ����ó�Ա����
class Person{
public:
    void showClassName(){
        cout<<"this is Person class"<<endl;
    }
    void showPersonAge(){
//        ����ԭ������Ϊ�����ָ��Ϊ��NULL
    if(this==NULL){  //��ֹ����
        return;
    }
        cout<<"age = "<<m_Age<<endl;
//        cout<<"age = "<<this.m_Age<<endl;
    }
    int m_Age;
};

void test01(){
    Person *p = NULL;
    p->showClassName();//û��
//    p->showPersonAge();//����
}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
