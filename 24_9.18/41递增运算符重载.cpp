//
// Created by tianya on 2024/10/3.
//
#include "iostream"
using namespace std;

//���ص��������

//�Զ�������
class MyInteger{
//    friend ostream &operator<<(ostream &cout,MyInteger &myInt);
    friend ostream &operator<<(ostream &cout,MyInteger myInt);//�������ֵ��Ҫɾ��myIntǰ���&
public:
    MyInteger(){
        m_Num = 0;
    }

//    ����++�����  ǰ�õ���    ��������Ϊ��һֱ��һ�����ݽ��е�������
//    void operator++(){
    MyInteger &operator++(){
//        �Ƚ���++����
        m_Num++;
//        �ٽ�����������
        return *this;
    }

//    ����++�����  ���õ���  Ҫ���� ֵ ������ ������
//    void operator++(int){   int����ռλ���� ������������ǰ�úͺ��õ���
    MyInteger operator++(int){ //���õ���һ���Ƿ���ֵ��ǰ�õ����Ƿ��ؽ�����
//        �� ��¼��ʱ���
        MyInteger temp = *this;
//        �� ����++���� ����
        m_Num++;
//        ��� ����¼���������  �ֲ���������� ִ������ͷ���
        return temp;
    }

private:
    int m_Num;
};

//����<<�����
//ostream &operator<<(ostream &cout,MyInteger &myInt)
ostream &operator<<(ostream &cout,MyInteger myInt)//�������ֵ��Ҫɾ��myIntǰ���&
{
    cout<<myInt.m_Num;
    return cout;
}
void test01(){
    MyInteger myInt;
//    cout<<myInt<<endl;//����<<  ͨ������<< �� ��Ԫ ���
//    cout<<++myInt<<endl;//����++
    cout<<++(++myInt)<<endl;//���ؽ����� 2   ����ֵ 2
    cout<<myInt<<endl;      //���ؽ����� 2   ����ֵ 1  ���Բ��ܷ���ֵ
}

void test02(){
    MyInteger myInt;
    cout<<myInt++<<endl;//����ֵ 0   ���ؽ����� �Ƿ����� ���̽���
    cout<<myInt<<endl;  //����ֵ 1   ���ؽ����� �Ƿ����� ����ֻ�ܷ���ֵ
}
int main(){
//    test01();
    test02();
    int a = 0;
    cout<<"++a="<<++(++a)<<endl;
    cout<<" a="<<a<<endl;
    cout<<"HelloWorld"<<endl;
    return 0;
}
