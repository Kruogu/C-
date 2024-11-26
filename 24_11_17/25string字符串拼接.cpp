//
// Created by tianya on 2024/11/17.
//
#include "iostream"
using namespace std;

//3.1.4 string字符串拼接

//string& operator+=(const char*str);            //重载+=操作符
//string& operator+=(const char c);              //重载+=操作符
//string& operator+=(const string& str);         //重载+=操作符

//string& append(const char *s);                 //把字符串s连接到当前字符串结尾
//string& append(const char *s,int n);           //把字符串s的前个字符连接到当前字符串结尾
//string& append(const string  &s);              //同operator+=(const string& str)
//string& append(const string &s,int pos,int n); //字符串s中从pos开始的n个字符连接到字符串结尾


void test01(){
    string str1 = "我";
    str1 += "爱玩游戏";
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

    //全部附加
//    str3.append(str2);//I love gameLOL DNF
    //只截取前三个字符  LOL
    str3.append(str2,0,3);//I love gameLOL
    //截取  从第4个位置开始，截3个  DNF  参数2从哪个位置开始截取，参数3截取字符个数
//    str3.append(str2,4,3);//I love gameDNF
    cout<<"str3 = "<<str3<<endl;


}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}



