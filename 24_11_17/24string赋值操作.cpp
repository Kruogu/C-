//
// Created by tianya on 2024/11/17.
//

#include "iostream"
using namespace std;
#include "vector"//������ͷ�ļ�
#include "algorithm"//��׼�㷨ͷ�ļ�

//3.1.3 string��ֵ����
//string& operator=(const chars);          //char�����ַ��� ��ֵ����ǰ���ַ���
//string& operator=(const string &s);      //���ַ���s������ǰ���ַ���
//string& operator=(char c);               //�ַ���ֵ����ǰ���ַ���
//
//string& assign(const char *s);          //���ַ���s������ǰ���ַ���
//string& assign(const char *s,int n);    //���ַ���s��ǰ���ַ�������ǰ���ַ���
//string& assign(const string &s);        //���ַ���s������ǰ�ַ���
//string& assign(int n,char c);           //�ø��ַ�c������ǰ�ַ���


void test01(){
//string& operator=(const chars);          //char�����ַ��� ��ֵ����ǰ���ַ���
    string str1;
    str1 = "hello world";
    cout<<"str1 = "<<str1<<endl;

//string& operator=(const string &s);      //���ַ���s������ǰ���ַ���
    string str2;
    str2 = str1;
    cout<<"str2 = "<<str2<<endl;

//string& operator=(char c);               //�ַ���ֵ����ǰ���ַ���
    string str3;
    str3 = 'a';
    cout<<"str3 = "<<str3<<endl;



//string& assign(const char *s);          //���ַ���s������ǰ���ַ���
    string str4;
    str4.assign("hello C++");
    cout<<"str4 = "<<str4<<endl;

//string& assign(const char *s,int n);    //���ַ���s��ǰ���ַ�������ǰ���ַ���
    string str5;
    str5.assign("hello C++",5);//hello
//    str5.assign(str4,5);//  C++
    cout<<"str5 = "<<str5<<endl;

//string& assign(const string &s);        //���ַ���s������ǰ�ַ���
    string str6;
    str6.assign(str5);
    cout<<"str6 = "<<str6<<endl;

//string& assign(int n,char c);           //�ø��ַ�c������ǰ�ַ���
    string str7;
    str7.assign(6,'*');
    cout<<"str7 = "<<str7<<endl;


}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
