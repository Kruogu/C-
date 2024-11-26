//
// Created by tianya on 2024/11/20.
//
#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"//本期不加也行
#include "functional"//内建函数对象头文件 本期不加也行

//4.3.3关系仿函数

//template < class T > bool equal_to <T>         //等于
//template < class T > bool not equal to <T>     //不等于
//template < class T > bool greater <T>          //大于
//template < class T > bool greater_equal <T>    //大于等于
//template < class T > bool less <T>             //小于
//template < class T > bool less_equal <T>       //小于等于


//内建函数对象   关系仿函数
//大于  greater

class MyCompare{
public:
//    降序
    bool operator()(int va1,int va2){
        return va1>va2;
    }
};

void test01(){
    vector<int>v;

    v.push_back(10);
    v.push_back(30);
    v.push_back(40);
    v.push_back(20);
    v.push_back(50);

    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

//    升序
    sort(v.begin(),v.end());
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

//    降序  谓词  或者  greater<int>()内建函数对象
    sort(v.begin(),v.end(),greater<int>());//内置
//    sort(v.begin(),v.end(),greater());//内置
//    sort(v.begin(),v.end(),MyCompare());
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
