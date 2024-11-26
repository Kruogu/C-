//
// Created by tianya on 2024/10/26.
//


#include "iostream"
using namespace std;

//�̳��е�ͬ����̬��Ա����ʽ
class Base{
public:
    static int m_A;//���������������ʼ��
    static void func(){
        cout<<"Base - static void func()����"<<endl;
    }
    static void func(int a){//���ذ汾
        cout<<"Base - static void func(int a)����"<<endl;
    }
};
int Base::m_A = 100;

class Son:public Base{
public:
    static int m_A;
    static void func(){
        cout<<"Son - static void func()����"<<endl;
    }
};
int Son::m_A = 200;

//ͬ����̬��Ա����

void test01(){
//    1.ͨ���������
    cout<<"ͨ��������ʣ�"<<endl;
    Son s;
    cout<<"Son �� m_A = "<<s.m_A<<endl;//�ȷ�������  200
    cout<<"Base �� m_A = "<<s.Base::m_A<<endl;//���ʸ��� 100

//    2.ͨ����������
    cout<<"ͨ���������ʣ�"<<endl;
    cout<<"Son �� m_A = "<<Son::m_A<<endl;//200  ֱ�ӷ�������
    cout<<"Base �� m_A = "<<Base::m_A<<endl;//100  ֱ�ӷ��ʸ���
//    ��һ��::����ͨ��������ʽ����    �ڶ���::������ʸ�����������
    cout<<"Base �� m_A = "<<Son::Base::m_A<<endl;//ͨ��������ʸ��࣬����Ҳ��

}

//ͬ����̬��Ա����
void test02(){
//    1.ͨ���������
    cout<<"ͨ��������ʣ�"<<endl;
    Son s;
    s.func();//���ڵ��õ������� Son
    s.Base::func();//����

//    2.ͨ����������
    cout<<"ͨ���������ʣ�"<<endl;
    Son::func();
    Base::func();
    Son::Base::func();

//    ���ذ汾
//    ������ֺ͸���ͬ����̬��Ա������Ҳ�����ظ���������ͬ����Ա����
//    �������ʸ����б�����ͬ����Ա����Ҫ��������
//    Son::func(100);//ֱ�ӵ��ò���,���౻������
    Son::Base::func(3);
}
int main(){
//    test01();
    test02();
    cout<<"HelloWorld"<<endl;
    return 0;
}
