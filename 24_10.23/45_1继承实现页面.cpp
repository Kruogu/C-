//
// Created by tianya on 2024/10/23.
//
#include "iostream"
using namespace std;

//�̳�ʵ��ҳ��
//����ҳ����
class BasePage{
public:
    void header(){//����ͷ��
        cout<<"��ҳ�������Ρ���¼��ע��...(����ͷ��)"<<endl;
    }
    void footer(){//�����ײ�
        cout<<"�������ġ�����������վ�ڵ�ͼ...(�����ײ�)"<<endl;
    }
    void left(){//����б�
        cout<<"Java��Python��C++...(���������б�)"<<endl;
    }
};

//�̳еĺô��������ظ�����
//�﷨�� class ���ࣺ�̳з�ʽ  ����
//����  Ҳ��Ϊ  ������
//����  Ҳ��Ϊ  ����

//Javaҳ��
class Java:public BasePage{//�̳����Ϲ���ҳ��
public:
    void content(){
        cout<<"Javaѧ����Ƶ"<<endl;
    }
};

//Pythonҳ��
class Python:public BasePage{//�̳����Ϲ���ҳ��
public:
    void content(){
        cout<<"Pythonѧ����Ƶ"<<endl;
    }
};

//C++ҳ��
class CPP:public BasePage{//�̳����Ϲ���ҳ��
public:
    void content(){
        cout<<"C++ѧ����Ƶ"<<endl;
    }
};

void test01(){
    cout<<"Java������Ƶҳ�����£�"<<endl;
    Java ja;
    ja.header();
    ja.footer();
    ja.left();
    ja.content();

    cout<<"����������������������������������������"<<endl;//�ָ���
    cout<<"Python������Ƶҳ�����£�"<<endl;
    Python py;
    py.header();
    py.footer();
    py.left();
    py.content();

    cout<<"����������������������������������������"<<endl;//�ָ���
    cout<<"C++������Ƶҳ�����£�"<<endl;
    CPP cpp;
    cpp.header();
    cpp.footer();
    cpp.left();
    cpp.content();
}

int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
