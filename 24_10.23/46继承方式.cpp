//
// Created by tianya on 2024/10/23.
//
#include "iostream"
using namespace std;

//�̳з�ʽ

//�����̳�
class Base1{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};

class Son1:public Base1{  // ��һ������
public:
    void func(){
        m_A = 10;//û����˵����������  �����еĹ���Ȩ�޳�Ա,����������Ȼ�ǹ���Ȩ��
        m_B = 20;//�����еı���Ȩ�޳�Ա����������Ȼ�Ǳ���Ȩ��
//        m_C = 10;//����  �����е�˽��Ȩ�޳�Ա��������ʲ���
    }
};

void test01(){
    Son1 s1;
    s1.m_A = 100;//����Ȩ��  ���ں�����  �����Է���
//    s1.m_B = 100;//����Ȩ��  ���ڿ��Է��ʣ�������ʲ���
}


//�����̳�
class Base2{
    public:
        int m_A;
    protected:
        int m_B;
    private:
        int m_C;
};

class Son2: protected Base2{//�����̳�
public:
    void func(){
        m_A = 100;//�����й�����Ա���������б�Ϊ����Ȩ��
        m_B = 100;//�����б�����Ա���������б�Ϊ����Ȩ��
//        m_C = 100;//����  ������˽�г�Ա��������ʲ���
    }
};

void test02(){
    Son2 s1;
//    s1.m_A = 1000;//������Son2��m_A��Ϊ����Ȩ�ޣ����������ʲ���
//    s1.m_B = 1000;//������Son2��m_B��Ϊ����Ȩ�ޣ����������ʲ���
}


//�����̳�
class Base3{
    public:
        int m_A;
    protected:
        int m_B;
    private:
        int m_C;
};

class Son3:private Base3{
public:
    void func(){
        m_A = 100;//�����й�����Ա  �������б�Ϊ˽�г�Ա
        m_B = 100;//�����б�����Ա  �������б�Ϊ˽�г�Ա
//        m_C = 100;//������˽�г�Ա��������ʲ���
    }
};
class GrandSon3:public Son3{//������
public:
    void func(){
        m_A = 1000;//����Son3��m_A��Ϊ˽�У������Ƕ��ӣ�Ҳ�Ƿ��ʲ���
        m_B = 1000;
    }
};
void test03(){
    Son3 s1;
//    s1.m_A = 1000;//˽�����Է��ʲ���
//    s1.m_B = 1000;//��Son3�У���Ϊ˽�г�Ա��������ʲ���
}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
