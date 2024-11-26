//
// Created by tianya on 2024/11/18.
//
#include "iostream"
using namespace std;
#include "deque"

//3.3.2 deque构造函数

//deque<T> deqT;             //默认构造形式
//deque(beg,end);            //构造函数将[beg,end)区间中的元素拷贝给本身。
//deque(n,elem);             //构造函数将n个elem拷贝给本身。
//deque(const deque &deq);   //拷贝构造函数

void printDuque1(deque<int> &d){//容器做参数  读和写都可以
    for(deque<int>::iterator it=d.begin();it!=d.end();it++){
        *it = 100;//可以 写 操作
        cout<<*it<<" ";
    }
    cout<<endl;
}
void printDuque2(const deque<int> &d){//加const代表只读，不能写
    for(deque<int>::const_iterator it=d.begin();it!=d.end();it++){//加const
//        *it = 100;//报错   容器中的数据不可以修改了  只读就不能写了
        cout<<*it<<" ";
    }
    cout<<endl;
}

void test01(){
    deque<int>d1;
    for(int i=0;i<10;i++){//不要遍历
        d1.push_back(i);//0-9
    }
    printDuque2(d1);
//    printDuque1(d1);

    //区间方式拷贝
    deque<int>d2(d1.begin(),d1.end());//拷贝d1
    printDuque2(d2);

    //n个elem的方式
    deque<int>d3(10,100);//10个100
    printDuque2(d3);

//    拷贝构造
    deque<int>d4(d3);//d3直接给d4
    printDuque2(d4);

}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
