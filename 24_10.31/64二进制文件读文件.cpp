//
// Created by tianya on 2024/11/3.
//
#include "iostream"
using namespace std;
#include <fstream>

class Person{
public:
    char m_Name[64];//����
    int m_Age;//����
};
//64�������ļ� ���ļ�
void test01(){
//    1.����ͷ�ļ� #include <fstream>
//    2.����������  ifstream ifs;
//    ofstream ofs;

//    3.���ļ�  �ж��ļ��Ƿ�򿪳ɹ�  ������
    ifstream ifs("Person.txt", ios::in | ios::binary );//Ҳ����ֱ��д��

    if(!ifs.is_open()){//Ϊ��
        cout<<"�ļ���ʧ��"<<endl;
        return;//��������
    } else{
        cout<<"�ļ��򿪳ɹ�"<<endl;
    }

//    4.���ļ�
    Person p;
    ifs.read((char *)&p,sizeof (Person));//ǿ��ת��char  pָ��

    cout<<"������"<<p.m_Name<<" ���䣺"<<p.m_Age<<endl;//���

//    5.�ر��ļ�
    ifs.close();
}

int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
