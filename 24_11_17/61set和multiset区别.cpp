//
// Created by tianya on 2024/11/19.
//
#include "iostream"
using namespace std;
#include "set"
//3.8.6set容器 和 multiset容器 区别

//        set不可以插入重复数据，而multiseti可以
//        set插入数据的同时会返回插入结果，表示插入是否成功
//        multiset不会检测数据，因此可以插入重复数据


void test01(){
    set<int>s1;

//    插入数据 只有insert方式
//    s1.insert(30);//重复没用
//    s1.insert(30);//通过查看insert源码可以发现源码中有pair，第二个位置是bool数据类型，检测是否成功

//    通过pair查看是否插入成功   重复数据就会导致插入失败
    pair<set<int>::iterator,bool> ret = s1.insert(10);//第二种

//    如果为真就成功，否则失败
    if(ret.second){//检测ret中第二个boool数据，第一个是int数据
        cout<<"第一次插入成功"<<endl;
    } else{
        cout<<"第一次插入失败"<<endl;
    }

    ret = s1.insert(10);
    if(ret.second){//检测ret中第二个boool数据，第一个是int数据
        cout<<"第二次插入成功"<<endl;
    } else{
        cout<<"第二次插入失败"<<endl;
    }


    multiset<int>ms;
//    允许插入重复值   和set不一样   可以多来几个试试
    ms.insert(10);//这里的insert源码会跳到迭代器，和set不一样
    ms.insert(10);
    ms.insert(10);
    ms.insert(10);

    for(multiset<int>:: iterator it=ms.begin();it!=ms.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
