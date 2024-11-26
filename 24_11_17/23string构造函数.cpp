//
// Created by tianya on 2024/11/17.
//

#include "iostream"
using namespace std;
#include "vector"//迭代器头文件
#include "algorithm"//标准算法头文件

//string构造函数
//string();                       //创建一个空的字符串例如：string str:
//string(const char*s);           //使用字符串 s 初始化
//string(const string& str);      //使用一个 string 对象初始化另一个 string 对象
//string(int n,char c);           //使用个字符c初始化

void test01(){
    string s1;//默认构造  空

    const char *str ="hello world";
//    cout<<"str = "<<str<<endl;
    string s2(str);
    cout<<"s2 = "<<s2<<endl;

    string s3(s2);
    cout<<"s3 = "<<s3<<endl;

    string s4(10,'a');
    cout<<"s4 = "<<s4<<endl;// ''是字符，" "是字符串
}

int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
