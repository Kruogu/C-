//
// Created by tianya on 2024/11/3.
//

#include "iostream"
using namespace std;
#include <fstream>

//63�������ļ� д�ļ�
//���Բ��������������� double float Ҳ�����Զ�����������
class Person{
public:
    char m_Name[64];//����  ��Ҫ��c++��string �������ַ�����
    int m_Age;//����
};

void test01(){
//    1.����ͷ�ļ� #include <fstream>
//    2.����������  ofstream ofs;
//    ofstream ofs;
    ofstream ofs("Person.txt", ios::out | ios::binary );//Ҳ����ֱ��д��

//    3.���ļ�  ofs.open("�ļ�·��"�򿪷�ʽ); ������
//    ofs.open("Person.txt", ios::out | ios::binary );

//    4.д�ļ�
    Person p = {"����",18};
    ofs.write((const char *)&p,sizeof (Person));//ǿ��ת��  pָ��

//    5.�ر��ļ�  ofs.close();
    ofs.close();
}

int main(){
    test01();//��������������������ֻҪ����ʱ���ܶ���������
    cout<<"HelloWorld"<<endl;
    return 0;
}
