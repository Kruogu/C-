//
// Created by tianya on 2024/11/17.
//
#include "iostream"
using namespace std;

//3.1.5 string字符串查找和替换

//函数原型：
//int find(const string& str,int pos = 0)const;      //查找str第一次出现位置，从pos开始查找
//int find(const char*s,int pos = 0)const;          //查找s第一次出现位置，从pos开始查找
//int find(const char*s,int pos,int n)const;      //从pos位置查找s的前n个字符第一次位置
//int find(const char c,int pos = 0)const;          //查找字符c第一次出现位置

//int rfind(const string& str,int pos = npos)const;  //查找str最后一次位置，从pos开始查找
//int rfind(const char*s,int pos = npos)const;      //查找s最后一次出现位置，从pos开始查找
//int rfind(const char*s,int pos,int n)const;       //从pos查找s的前n个字符最后一次位置
//int rfind(const char c,int pos = 0)const;         //查找字符c最后一次出现位置

//string& replace(int pos,int n,const string& str); //替换从pos开始n个字符为字符串str
//string& replace(int pos,int n,const char*s);     //替换从pos开始的n个字符为字符串s

//1、查找
void test01(){
//    string str1 = "abcdefg";
    string str1 = "abcdefgde";
//    str1.find("de");
    int pos = str1.find("de");
    cout<<"pos = "<<pos<<endl;//3  代表从第4个位置出现

//    int pos = str1.find("df");
//    cout<<"pos = "<<pos<<endl;//-1  没有找到返回 -1

    if(pos == -1){
        cout<<"未找到字符串"<<endl;
    } else{
        cout<<"找到字符串,pos = "<<pos<<endl;
    }


//    rfind 和 find 区别
//    rfind,从右往左查找    find从左往右查找
//    r=rear表示从字符串后面开始查找,也就是查找最后一次出现的位置
    pos = str1.rfind("de");
    cout<<"pos = "<<pos<<endl;//3  和上面一样
}

//2、替换
void test02() {
    //替换从pos开始n个字符为字符串str
    string str1 = "abcdefg";
    cout<<"str1 = "<<str1<<endl;//abcdefg
    str1.replace(1,3,"11111");//从第2个位置开始 替换3个字符 为 11111
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
