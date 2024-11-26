//
// Created by tianya on 2024/11/20.
//
#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"//本期不加也行
#include "functional"//内建函数对象头文件 本期不加也行

//4.3.4逻辑仿函数

//template < class T > bool logical_and <T>         //逻辑与
//template < class T > bool logical_or <T>          //逻辑或
//template < class T > bool logical_not <T>         //逻辑非


//内建函数对象   逻辑仿函数
//逻辑非  logical_not

void test01(){
    vector<bool>v;

    v.push_back(true);
    v.push_back(false);
    v.push_back(true);
    v.push_back(false);


    for(vector<bool>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    //利用逻辑非 将容器v搬运到容器v2中，并执行 取反 操作
    vector<bool>v2;
    v2.resize(v.size());//4 必须提前开辟空间
    //原容器起点，终点迭代器     目标容器 起点    仿函数
    transform(v.begin(),v.end(),v2.begin(),logical_not<bool>());//与和或不能用这个transfrom
    for(vector<bool>::iterator it=v2.begin();it!=v2.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
