//
// Created by tianya on 2024/11/7.
//
#include "iostream"
using namespace std;

//1.2.2����ģ��ע������
//template <typename T>  //typename�����滻��class
template <class T>
void mySwap(T &a,T &b){
    T temp = a;
    a = b;
    b = temp;
}

//1���Զ������Ƶ��������Ƶ���һ�µ���������T,�ſ���ʹ��
void test01(){
    int a = 10;
    int b = 20;
    char c = 'c';
    mySwap(a,b);//��ȷ
//    mySwap(a,c);//����  ���ͺ��ַ��ͽ��н���  �Ƶ�����һ�µ�T����

    cout<<"a = "<<a<<" b = "<<b<<endl;
}

//2��ģ�����Ҫȷ���� T ���������ͣ��ſ���ʹ��
template<class T>
void func(){
    cout<<"func����"<<endl;
}
void test02(){
//    func();//����  ����ָ�����ͲŲ�����
    func<int>();
}
int main(){
    test01();
    test02();
    cout<<"HelloWorld"<<endl;
    return 0;
}
