//
// Created by tianya on 2024/11/6.
//
#include "iostream"
using namespace std;


//02����ģ������﷨
//�����������Ͳ�һ����������һ��
//�������ͽ����ĺ���
void swapInt(int &a,int &b){
//void swapInt(int a,int b){//���� & ����
    int temp = a;
    a = b;
    b = temp;
}

//�������������ͺ���
void swapDouble(double &a,double &b){
    double temp = a;
    a = b;
    b = temp;
}

//����ģ��
// ����һ��ģ�壬���߱�������������н����ŵ� T ��Ҫ����
// T ��һ��ͨ�õ���������
//ģ����ʵ���ǽ� ���� ������
template<typename T>
void mySwap(T &a,T &b){
    T temp = a;
    a = b;
    b = temp;
}

void test01(){
    int a = 10;
    int b = 20;

//    swapInt(a,b);//ע�͵�
    //���ú���ģ�彻��
//    ���ַ�ʽʹ�ú���ģ��
//    1���Զ������Ƶ�  ���ݴ���Ĳ����������� �Ƶ� ����ģ�����������
//    mySwap(a,b);
//    2����ʾָ������
    mySwap<int>(a,b);
    cout<<"a = "<<a<<" b = "<<b<<endl;

    double c = 1.1;
    double d = 2.2;
    swapDouble(c,d);
    cout<<"c = "<<c<<" d = "<<d<<endl;
}
int main(){
    test01();
//    int x,y;
//    x = 1;
//    y = 2;
//    cout<<"x = "<<x<<" y = "<<y<<endl;
//    swapInt(x,y);
//    cout<<"x = "<<x<<" y = "<<y<<endl;
    cout<<"HelloWorld"<<endl;
return 0;
}
