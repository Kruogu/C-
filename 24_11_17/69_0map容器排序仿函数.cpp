//
// Created by tianya on 2024/11/20.
//
#include "iostream"
using namespace std;
#include "map"

//3.9.6map容器 排序

class MyCompare{
public:
    bool operator()(int v1,int v2)const{
//        降序
        return v1>v2;
    }
};

//两种输出规则
//void printMap(map<int,int> &m){
void printMap(map<int,int,MyCompare> &m){
//    升序和降序不一样
//    for(map<int,int>::iterator it = m.begin();it!=m.end();it++){
    for(map<int,int,MyCompare>::iterator it = m.begin();it!=m.end();it++){
        cout<<"key = "<<(*it).first
            <<" value = "<<it->second<<endl;
    }
    cout<<endl;
}

void test01(){
//    map<int,int>m1;
    map<int,int,MyCompare>m1;//插入之前修改排序规则

//    插入数据
    m1.insert(make_pair(1,10));
    m1.insert(make_pair(3,30));
    m1.insert(make_pair(2,200));
    m1.insert(make_pair(3,30));//本行插不进去，count是1
    m1.insert(make_pair(4,20));

    printMap(m1);

}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}

