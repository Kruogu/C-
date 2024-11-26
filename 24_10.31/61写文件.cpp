//
// Created by tianya on 2024/11/2.
//
#include "iostream"
using namespace std;
#include<fstream>//头文件的包含

//文本文件 写文件
//写完程序后运行，然后点击 标签栏 右键当前项目名-打开于-资源管理器

void test01(){
//    1、包含头文件 fstream
//    2、创建流对象
    ofstream ofs;

//    3、指定打开方式
//    ofs.open("test.txt",ios::out);
//    ofs.open("E:\\0Work\\0workspace\\test.txt",ios::out);//这样可以
    ofs.open("E:\0Work\0workspace\test1.txt",ios::out);//这样不行

//    4、写内容
    ofs<<"姓名：张三"<<endl;
    ofs<<"性别：男"<<endl;
    ofs<<"年龄：18"<<endl;

//    5、关闭文件
    ofs.close();
}
int main(){
    test01();
    cout<<"HelloWorld1"<<endl;
    return 0;
}
