//
// Created by tianya on 2024/11/18.
//
#include "iostream"
using namespace std;
#include "deque"

//3.3.3 deque赋值操作

//deque& roperator=(const deque &deq);   //重载等号操作符
//assign(beg,end);                       //将[beg,end)区间中的数据拷贝赋值给本身。
//assign(n,elem);                        //将n个elem拷贝赋值给本身。


void printDuque(const deque<int> &d){//加const代表只读，不能写
    for(deque<int>::const_iterator it=d.begin();it!=d.end();it++){//加const
        cout<<*it<<" ";
    }
    cout<<endl;
}

void test01(){
    deque<int>d1;
    for(int i=0;i<10;i++){
        d1.push_back(i);//0-9
    }
    printDuque(d1);

//    operator=赋值
    deque<int>d2;
    d2 = d1;
    printDuque(d2);

//    assign赋值
    deque<int>d3;
    d3.assign(d1.begin(),d1.end());
    printDuque(d3);

    deque<int>d4;
    d4.assign(10,100);
    printDuque(d4);

//    //区间方式拷贝
//    deque<int>d2(d1.begin(),d1.end());//拷贝d1
//    printDuque2(d2);
//
//    //n个elem的方式
//    deque<int>d3(10,100);//10个100
//    printDuque2(d3);
//
////    拷贝构造
//    deque<int>d4(d3);//d3直接给d4
//    printDuque2(d4);

}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
