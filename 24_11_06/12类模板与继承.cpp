//
// Created by tianya on 2024/11/10.
//

#include "iostream"
using namespace std;

//1.3.5��ģ����̳�

template<class T>
class Base{
public:
    T m;
};
//class Son:public Base{//���󣬱���Ҫ֪�������е�T���ͣ����ܼ̳и�����
class Son:public Base<int>{
public:
};
void test01(){
    Son s1;//����ͨ��������ʵ��������
}

//��������ָ��������T���ͣ�����Ҳ��Ҫ����ģ��
template<class T1,class T2>
class Son2:public Base<T2>{
public:
    Son2(){
        cout<<"T1�ķ���Ϊ��"<< typeid(T1).name()<<endl;//i  int
        cout<<"T2�ķ���Ϊ��"<< typeid(T2).name()<<endl;//c  char
    }
    T1 obj;
};
void test02(){
    Son2<int,char> s2;//����ͨ��������ʵ��������
}
int main(){
//    test01();
    test02();
    cout<<"HelloWorld"<<endl;
    return 0;
}
