//
// Created by tianya on 2024/11/8.
//

#include "iostream"
using namespace std;

//1.2.4��ͨ�����뺯��ģ�������

//1����ͨ��������ʱ���Է�����ʽ����ת�����Զ�����ת����
//2������ģ�����ʱ����������Զ������Ƶ������ᷢ����ʽ����ת��
//3�����������ʾָ�����͵ķ�ʽ�����Է�����ʽ����ת��

//��ͨ����
int myAdd(int a,int b){
    return a+b;
}

//����ģ��
template<class T>
T myAdd02(T a,T b){
    return a+b;
}

void test01(){
    int a = 10;
    int b = 20;
    char c = 'c';//ASCII  99
//    cout<<myAdd(a,b)<<endl;//����
//    cout<<myAdd(a,c)<<endl;

//    �Զ������Ƶ�   ���ᷢ����ʽ����ת��
    myAdd02(a,b);//����
//    cout<<myAdd02(a,b)<<endl;//����
//    cout<<myAdd02(a,c)<<endl;//��������  ����

    //��ʾָ������   �ᷢ����ʽ����ת��
    myAdd02<int>(a,c);//����  109
    cout<<myAdd02<int>(a,c)<<endl;//����  109
}

int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
