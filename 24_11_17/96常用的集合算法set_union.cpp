//
// Created by tianya on 2024/11/21.
//

#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"
//5.6.2 常用的集合算法set_union

//功能描述：
//    ·求两个集合的并集
//
//函数原型：
//    ·set_union(iterator beg1,iterator end1,iterator beg2,iterator end2,iterator dest);
    //求两个集合的并集
    //注意：两个集合必须是有序序列
    //beg1容器1开始迭代器
    //end1容器1结束迭代器I
    //beg2容器2开始迭代器
    //end2容器2结束迭代器
    //dest目标容器开始迭代器


//仿函数打印
class MyPrint{
public:
    void operator()(int val){
        cout<<val<<" ";
    }
};

void test01(){
    vector<int>v1;
    vector<int>v2;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);//0~9
        v2.push_back(i+5);//5~14
    }
    cout<<"v1："<<endl;
    for_each(v1.begin(),v1.end(), MyPrint());//仿函数
    cout<<endl;
    cout<<"v2："<<endl;
    for_each(v2.begin(),v2.end(), MyPrint());//仿函数
    cout<<endl;

    vector<int>vTarget;//目标容器
//    最特殊情况两个容器没有交集，并集就是两个容器size相加
    vTarget.resize(v1.size()+v2.size());//提前开辟空间

//    获取并集  itEnd是 it的最后一个位置       返回目标容器的最后一个元素的迭代器地址
    vector<int>::iterator itEnd = set_union(v1.begin(),v1.end(),v2.begin(),v2.end(),vTarget.begin());

    cout<<"并集："<<endl;
    for_each(vTarget.begin(),itEnd, MyPrint());//仿函数  必须用itEnd接收
//    for_each(vTarget.begin(),vTarget.end(), MyPrint());//仿函数 不能用这个，多出来5个空间
    cout<<endl;




}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
