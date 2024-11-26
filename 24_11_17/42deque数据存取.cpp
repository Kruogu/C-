//
// Created by tianya on 2024/11/18.
//
#include "iostream"
using namespace std;
#include "deque"

//3.3.6 deque数据存取

//at(int idx);        //返回索引idx所指的数据
//operator[];         //返回索引idx所指的数据
//front();            //返回容器中第一个数据元素
//back();             //返回容器中最后一个数据元素

void printDuque(const deque<int> &d){//加const代表只读，不能写
    for(deque<int>::const_iterator it=d.begin();it!=d.end();it++){//加const
        cout<<*it<<" ";
    }
    cout<<endl;
}

void test01(){
    deque<int>d;

    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_front(100);
    d.push_front(200);
    d.push_front(300);
    //300 200 100 10 20 30

//    printDuque(d);

//    通过[]方式访问元素
    for(int i=0;i<d.size();i++){//加const
        cout<<d[i]<<" ";
    }
    cout<<endl;

//    通过at方式访问元素
    for(int i=0;i<d.size();i++){//加const
        cout<<d.at(i)<<" ";
    }
    cout<<endl;

//    获取第一个元素
    cout<<"第一个元素为："<<d.front()<<endl;
//    获取最后一个元素
    cout<<"最后一个元素为："<<d.back()<<endl;

}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
