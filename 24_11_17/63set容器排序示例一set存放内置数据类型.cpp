//
// Created by tianya on 2024/22/19.
//
#include "iostream"
using namespace std;
#include "set"
//3.8.8set容器排序

//示例一 set存放 内置 数据类型

class MyCompare{
public:
//    注意，因为C++11新特性的缘故，你们需要在参数列表后添加const
    bool operator()(int v1,int v2)const{//第一个小括号代表要重载的符号，第二个小括号代表参数列表
//        大于是降序  默认是升序
        return v1>v2;
    }
};

void test01(){
    set<int>s1;

    s1.insert(10);
    s1.insert(40);
    s1.insert(20);
    s1.insert(50);
    s1.insert(30);
    s1.emplace(60);//c++11新特性

//    自动排好序了已经，打印检测一下
    for(set<int>:: iterator it=s1.begin();it!=s1.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

//    指定排序规则为从大到小  在插入数据之前就要做好改变,插进去就改不了了
//    利用仿函数
    set<int,MyCompare>s2;//放到模板参数列表中

    s2.insert(10);
    s2.insert(40);
    s2.insert(20);
    s2.insert(50);
    s2.insert(30);

//    查看打印是否排好序
    for(set<int>:: iterator it=s2.begin();it!=s2.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

}

int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
