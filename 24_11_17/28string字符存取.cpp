//
// Created by tianya on 2024/11/17.
//

#include "iostream"
using namespace std;

//3.1.7 string�ַ���ȡ
//string�е����ַ���ȡ��ʽ������
//char& operator[](int n);    //ͨ��[]��ʽȡ�ַ�
//char& at(int n);            //ͨ��at������ȡ�ַ�

void test01(){
    string str = "hello";
    cout <<"str = "<<str<<endl;

    //1��ͨ��[]��ʽȡ�ַ�
    for(int i=0;i<str.size();i++){
        cout<<str[i]<<" ";
    }
    cout<<endl;

    //2��ͨ��at������ȡ�ַ�
    for(int i=0;i<str.size();i++){
        cout<<str.at(i)<<" ";
    }
    cout<<endl;

    //�޸ĵ����ַ�
    str[0] = 'x';
    cout <<"str = "<<str<<endl;

    str.at(1) = 'c';
    cout <<"str = "<<str<<endl;
}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
