//
// Created by tianya on 2024/11/2.
//
#include "iostream"
using namespace std;
#include<fstream>//ͷ�ļ��İ���

//�ı��ļ� д�ļ�
//д���������У�Ȼ���� ��ǩ�� �Ҽ���ǰ��Ŀ��-����-��Դ������

void test01(){
//    1������ͷ�ļ� fstream
//    2������������
    ofstream ofs;

//    3��ָ���򿪷�ʽ
//    ofs.open("test.txt",ios::out);
//    ofs.open("E:\\0Work\\0workspace\\test.txt",ios::out);//��������
    ofs.open("E:\0Work\0workspace\test1.txt",ios::out);//��������

//    4��д����
    ofs<<"����������"<<endl;
    ofs<<"�Ա���"<<endl;
    ofs<<"���䣺18"<<endl;

//    5���ر��ļ�
    ofs.close();
}
int main(){
    test01();
    cout<<"HelloWorld1"<<endl;
    return 0;
}
