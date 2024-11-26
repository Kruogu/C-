//
// Created by tianya on 2024/11/3.
//

#include "iostream"
using namespace std;
#include <fstream>

//63二进制文件 写文件
//可以操纵内置数据类型 double float 也可以自定义数据类型
class Person{
public:
    char m_Name[64];//姓名  不要用c++的string 可以用字符数组
    int m_Age;//年龄
};

void test01(){
//    1.包含头文件 #include <fstream>
//    2.创建流对象  ofstream ofs;
//    ofstream ofs;
    ofstream ofs("Person.txt", ios::out | ios::binary );//也可以直接写好

//    3.打开文件  ofs.open("文件路径"打开方式); 二进制
//    ofs.open("Person.txt", ios::out | ios::binary );

//    4.写文件
    Person p = {"张三",18};
    ofs.write((const char *)&p,sizeof (Person));//强制转换  p指针

//    5.关闭文件  ofs.close();
    ofs.close();
}

int main(){
    test01();//二进制乱码是正常现象，只要读的时候能读回来就行
    cout<<"HelloWorld"<<endl;
    return 0;
}
