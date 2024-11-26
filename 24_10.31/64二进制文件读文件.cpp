//
// Created by tianya on 2024/11/3.
//
#include "iostream"
using namespace std;
#include <fstream>

class Person{
public:
    char m_Name[64];//姓名
    int m_Age;//年龄
};
//64二进制文件 读文件
void test01(){
//    1.包含头文件 #include <fstream>
//    2.创建流对象  ifstream ifs;
//    ofstream ofs;

//    3.打开文件  判断文件是否打开成功  二进制
    ifstream ifs("Person.txt", ios::in | ios::binary );//也可以直接写好

    if(!ifs.is_open()){//为假
        cout<<"文件打开失败"<<endl;
        return;//结束程序
    } else{
        cout<<"文件打开成功"<<endl;
    }

//    4.读文件
    Person p;
    ifs.read((char *)&p,sizeof (Person));//强制转换char  p指针

    cout<<"姓名："<<p.m_Name<<" 年龄："<<p.m_Age<<endl;//输出

//    5.关闭文件
    ifs.close();
}

int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
