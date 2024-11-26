//
// Created by tianya on 2024/11/3.
//

#include "iostream"
using namespace std;
#include "fstream"

//文本文件 读文件
void test01(){
//    1、包含头文件 fstream
//    2、创建流对象
    ifstream ifs;

//    3、打开文件并且判断是否打开成功
//    ifs.open("test.txt",ios::in);
    ifs.open("Person.txt",ios::in);//只有第一种和第二种可以正常读出来，第三第四种乱码
//    ifs.open("E:\\0Work\\0workspace\\test.txt",ios::out);//这样可以
//    ifs.open("E:\0Work\0workspace\test1.txt",ios::out);//这样不行

    if(ifs.is_open()==1){//不加 1 也行 ，自动为真，前面加！就是假
        cout<<"文件打开成功"<<endl;
    } else{
        cout<<"文件打开失败"<<endl;
        return;//结束程序
    }

//    4、读数据  指定打开方式
//    第一种
//    char buf[1024] = {0};//字符数组  文件中的数据全部放进来
//    while (ifs>>buf){//右移运算符  ifs输入进buf中
//        cout<<buf<<endl;
//    }

//    第二种
    char buf[1024] = {0};
    while (ifs.getline(buf,sizeof(buf))){// getline 获取一行   buf代表头地址  sizeof代表1024
        cout<<buf<<endl;
    }

//    第三种
//    string buf;//字符串
//    //把文件的输出流对象 ifs 放到  buf中
//    while (getline(ifs,buf)){//这里的getline是全局函数
//        cout<<buf<<endl;
//    }

//    第四种  不太推荐用  效率低
//    char c;//文件中的字符一个一个读取出来  放到c里
//    //EOF end of file   文件尾部标志
//    while ((c=ifs.get())!=EOF) {//如果没有读到文件尾EOF，就一直读下去
//        cout<<c;//不能加 endl
//    }
//    5、关闭文件
    ifs.close();
}

int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
