//
// Created by tianya on 2024/11/17.
//
#include "iostream"
using namespace std;

//3.1.5 string�ַ������Һ��滻

//����ԭ�ͣ�
//int find(const string& str,int pos = 0)const;      //����str��һ�γ���λ�ã���pos��ʼ����
//int find(const char*s,int pos = 0)const;          //����s��һ�γ���λ�ã���pos��ʼ����
//int find(const char*s,int pos,int n)const;      //��posλ�ò���s��ǰn���ַ���һ��λ��
//int find(const char c,int pos = 0)const;          //�����ַ�c��һ�γ���λ��

//int rfind(const string& str,int pos = npos)const;  //����str���һ��λ�ã���pos��ʼ����
//int rfind(const char*s,int pos = npos)const;      //����s���һ�γ���λ�ã���pos��ʼ����
//int rfind(const char*s,int pos,int n)const;       //��pos����s��ǰn���ַ����һ��λ��
//int rfind(const char c,int pos = 0)const;         //�����ַ�c���һ�γ���λ��

//string& replace(int pos,int n,const string& str); //�滻��pos��ʼn���ַ�Ϊ�ַ���str
//string& replace(int pos,int n,const char*s);     //�滻��pos��ʼ��n���ַ�Ϊ�ַ���s

//1������
void test01(){
//    string str1 = "abcdefg";
    string str1 = "abcdefgde";
//    str1.find("de");
    int pos = str1.find("de");
    cout<<"pos = "<<pos<<endl;//3  ����ӵ�4��λ�ó���

//    int pos = str1.find("df");
//    cout<<"pos = "<<pos<<endl;//-1  û���ҵ����� -1

    if(pos == -1){
        cout<<"δ�ҵ��ַ���"<<endl;
    } else{
        cout<<"�ҵ��ַ���,pos = "<<pos<<endl;
    }


//    rfind �� find ����
//    rfind,�����������    find�������Ҳ���
//    r=rear��ʾ���ַ������濪ʼ����,Ҳ���ǲ������һ�γ��ֵ�λ��
    pos = str1.rfind("de");
    cout<<"pos = "<<pos<<endl;//3  ������һ��
}

//2���滻
void test02() {
    //�滻��pos��ʼn���ַ�Ϊ�ַ���str
    string str1 = "abcdefg";
    cout<<"str1 = "<<str1<<endl;//abcdefg
    str1.replace(1,3,"11111");//�ӵ�2��λ�ÿ�ʼ �滻3���ַ� Ϊ 11111
    cout<<"str1 = "<<str1<<endl;//a11111efg

    string str2 = "abcdefg";
    string str3 = "hahaha";
    str2.replace(2,3,str3);
    cout<<"str2 = "<<str2<<endl;//abhahahafg
}

int main(){
    test01();
    test02();
    cout<<"HelloWorld"<<endl;
    return 0;
}
