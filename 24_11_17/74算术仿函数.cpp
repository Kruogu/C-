//
// Created by tianya on 2024/11/20.
//
#include "iostream"
using namespace std;
#include "functional"//�ڽ���������ͷ�ļ�

//4.3.2�����º���

//template < class T >  plus <T>           //�ӷ��º���
//template < class T >  minus <T>          //�����º���
//template < class T > multiplies  <T>     //�˷��º���
//template < class T > divides <T>         //�����º���
//template < class T > modulus <T>         //ȡģ�º���
//template < class T > negate <T>          //ȡ���º���

//�ڽ���������
//negate һԪ�º��� ȡ���º���
void test01(){
    negate<int>n;
    n(50);
    cout<<n(50)<<endl;//ȡ��  -50
}

//plus   ��Ԫ�º��� �ӷ�
void test02(){
    plus<int>p;//Ĭ��������ͬ����������
    cout<<p(50,50)<<endl;//���  100
}
int main(){
    test01();
    test02();
    cout<<"HelloWorld"<<endl;
    return 0;
}
