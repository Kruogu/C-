//
// Created by tianya on 2024/11/1.
//
#include "iostream"
using namespace std;

//���麯���ͳ�����
class Base{
public:
//    virtual void func(){ }
//    ���麯��
//    ֻҪ��һ�����麯���������Ҳ��Ϊ������
//    �������ص㣺
//      1.�޷�ʵ��������
//      2.����������������д�������еĴ��麯��������Ҳ���ڳ�����
    virtual void func() = 0; //����Ҳ��
};

class Son:public Base{
public:
    void func(){
        cout<<"Son�е�func��������"<<endl;
    }
};
void dofunc(Base &base){
    base.func();
}
void test01(){
//    Base b;//����  ������ʹ�ó��������
//    new Base;//����  �������޷�ʵ��������

    Son s;//���������д�������еĴ��麯���������޷�ʵ��������
    dofunc(s);//�ɵ���  ����

    Base *base = new Son;//ָ��
    base->func();//�ɵ���
}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
