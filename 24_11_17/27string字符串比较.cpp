//
// Created by tianya on 2024/11/17.
//

#include "iostream"
using namespace std;

//3.1.6 string:�ַ����Ƚ�
//int compare(const string &s)const;   //���ַ���s�Ƚ�
//int compare(const char *s)const;      //���ַ���s�Ƚ�

void test01()
{
    string str1 = "hello";
//    string str1 = "xello";//ǰ���С
//    string str2 = "hello";//���
//    string str2 = "xello";//ǰС���
    string str2 = "ielln";//��һ�������һ��С��ASCIIֵһ�������廹��С
    if(str1.compare(str2) == 0){//���ܱȽ�����
        cout<<"str1 ���� str2"<<endl;
    }else if(str1.compare(str2) > 0){
        cout<<"str1 ���� str2"<<endl;
    }else{
        cout<<"str1 С�� str2"<<endl;
    }
}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
