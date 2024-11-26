//
// Created by tianya on 2024/11/17.
//

#include "iostream"
using namespace std;

//3.1.6 string:字符串比较
//int compare(const string &s)const;   //与字符串s比较
//int compare(const char *s)const;      //与字符串s比较

void test01()
{
    string str1 = "hello";
//    string str1 = "xello";//前大后小
//    string str2 = "hello";//相等
//    string str2 = "xello";//前小后大
    string str2 = "ielln";//第一个大，最后一个小，ASCII值一样，总体还是小
    if(str1.compare(str2) == 0){//不能比较中文
        cout<<"str1 等于 str2"<<endl;
    }else if(str1.compare(str2) > 0){
        cout<<"str1 大于 str2"<<endl;
    }else{
        cout<<"str1 小于 str2"<<endl;
    }
}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
