//
// Created by tianya on 2024/11/17.
//
#include "iostream"
using namespace std;

//3.1.4 string�ַ���ƴ��

//string& operator+=(const char*str);            //����+=������
//string& operator+=(const char c);              //����+=������
//string& operator+=(const string& str);         //����+=������

//string& append(const char *s);                 //���ַ���s���ӵ���ǰ�ַ�����β
//string& append(const char *s,int n);           //���ַ���s��ǰ���ַ����ӵ���ǰ�ַ�����β
//string& append(const string  &s);              //ͬoperator+=(const string& str)
//string& append(const string &s,int pos,int n); //�ַ���s�д�pos��ʼ��n���ַ����ӵ��ַ�����β


void test01(){
    string str1 = "��";
    str1 += "������Ϸ";
    cout<<"str1 = "<<str1<<endl;

    str1 += ":";
    cout<<"str1 = "<<str1<<endl;

    string str2 = "LOL DNF";
    str1 += str2;
    cout<<"str1 = "<<str1<<endl;


//    append
    string str3 = "I";
    str3.append(" love ");//I love
    cout<<"str3 = "<<str3<<endl;

    str3.append("game abcde",4);//I love game
    cout<<"str3 = "<<str3<<endl;

    //ȫ������
//    str3.append(str2);//I love gameLOL DNF
    //ֻ��ȡǰ�����ַ�  LOL
    str3.append(str2,0,3);//I love gameLOL
    //��ȡ  �ӵ�4��λ�ÿ�ʼ����3��  DNF  ����2���ĸ�λ�ÿ�ʼ��ȡ������3��ȡ�ַ�����
//    str3.append(str2,4,3);//I love gameDNF
    cout<<"str3 = "<<str3<<endl;


}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}



