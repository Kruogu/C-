//
// Created by tianya on 2024/11/18.
//
#include "iostream"
using namespace std;
#include "deque"
#include "algorithm"//标准算法头文件

//3.3.7 deque排序

//sort(iterator beg,iterator end)   //对beg和end区间内元素进行排序

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
    printDuque(d);

    //排序  默认排序规则  从小到大，升序
    //对于支持随机访问的迭代器的容器，都可以利用sort算法直接对其进行排序
    //vector容器也可以利用sort进行排序
    sort(d.begin(), d.end());//10 20 30 100 200 300
    cout<<"升序排序后："<<endl;
//    std::sort(d.begin(), d.end());//同上写法一样
    printDuque(d);

//    sort(d.end(), d.begin());//降序 反过来直接报错  不可以
    sort(d.rbegin(),d.rend());//正常运行  降序成功  从大到小
    cout<<"降序排序后："<<endl;
    printDuque(d);


}
int main(){

    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
