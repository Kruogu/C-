//
// Created by tianya on 2024/11/20.
//

#include "iostream"
using namespace std;
#include "map"

//3.9.2map构造和赋值


//构造：
//map<T1,T2> mp;                   //map默认构造函数：
//map(const map &mp);              //拷贝构造函数
//
//赋值：
//map& operator=(const map &mp);   //重载等号操作符

//打印map
void printMap(map<int,int> &m){
    for(map<int,int>::iterator it=m.begin();it!=m.end();it++){
        cout<<"key = "<<(*it).first
            <<" value = "<<it->second<<endl;
    }
    cout<<endl;
}

void test01(){
//    创建map容器
    map<int,int>m;

//    匿名对组插入
//    ·pair中第一个元素为key(键值)，起到索引作用，第二个元素为value(实值)
//    插入自动排序  升序 从小到大
    m.insert(pair<int,int>(1,10));
    m.insert(pair<int,int>(3,30));
    m.insert(pair<int,int>(2,20));
    m.insert(pair<int,int>(4,40));

    printMap(m);

//    拷贝构造
    map<int,int>m2(m);
    printMap(m2);

//    赋值
    map<int,int>m3;
    m3 = m2;
    printMap(m3);
}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
