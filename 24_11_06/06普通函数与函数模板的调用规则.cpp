//
// Created by tianya on 2024/11/8.
//
#include "iostream"
using namespace std;

//1.2.5��ͨ�����뺯��ģ��ĵ��ù���
//1.�������ģ�����ͨ����������ʵ�֣����ȵ�����ͨ����
//2.����ͨ����ģ������б���ǿ�Ƶ��ú���ģ��
//3.����ģ��Ҳ���Է�������
//4.�������ģ����Բ������õ�ƥ��,���ȵ��ú���ģ��

//void myPrint(int a,int b);//���ֻ����������������ô���ȵ���˭��
void myPrint(int a,int b){
    cout<<"���õ���ͨ����"<<endl;
}

template<class T>
void myPrint(T a,T b){
    cout<<"���õĺ���ģ��"<<endl;
}

template<class T>
void myPrint(T a,T b,T c){
    cout<<"�������صĺ���ģ��"<<endl;
}

void test01(){
    int a = 10;
    int b = 20;
//    myPrint(a,b);//������ͨ

//    ͨ����ģ������б���ǿ�Ƶ��ú���ģ��
//    myPrint<>(a,b);//���ȵ���ģ��
//    myPrint(a,b,100);//���ȵ�������ģ��

//    �������ģ����Բ������õ�ƥ��,���ȵ��ú���ģ��
    char c1 = 'a';
    char c2 = 'd';
    myPrint(c1,c2);//���ȵ���ģ��,��ͨ����Ҫ��һ��ת�����������ȶȲ���
    myPrint<>(c1,c2,'d');//���ȵ�������ģ��
}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
