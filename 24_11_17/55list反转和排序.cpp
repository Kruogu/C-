//
// Created by tianya on 2024/11/19.
//
#include "list"

#include "iostream"
using namespace std;
#include "algorithm"//标准算法头文件

//3.7.7list反转和排序

//reverse();   //反转链表    12345      54321
//sort();      //链表排序


void printList(const list<int> &L){
//    it可以++是因为重载过了，封装好直接使用
    for(list<int>::const_iterator it = L.begin();it!=L.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

void test01(){
//    创建list容器
    list<int>L1; //默认构造

//    添加数据  尾插
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    L1.push_back(50);


//    反转
    cout<<"反转前："<<endl;
    printList(L1);
    L1.reverse();
    cout<<"反转后："<<endl;
    printList(L1);


}

bool myCompare(int v1,int v2){
    //降序 就让第一个数 > 第二个数
    return v1>v2;//如果成立，就返回真
}

//排序
void test02(){
    //    创建list容器
    list<int>L1; //默认构造

//    添加数据  尾插
    L1.push_back(30);
    L1.push_back(10);
    L1.push_back(40);
    L1.push_back(20);
    L1.push_back(50);

//    默认排序  从小到大
    cout<<"排序前："<<endl;
    printList(L1);

//    所有不支持随机访问迭代器的容器，不可以用标准算法库algorithm
//    不支持随机访问迭代器的容器，内部会提供对应一些算法
//    sort(L1.begin(),L1.end());//报错
    L1.sort();//是成员函数 从小到大  升序

    cout<<"升序排序后："<<endl;
    printList(L1);

//    重载版本  布尔函数名放里边  如果是真，就降序，反之亦然   还有仿函数暂没讲
    L1.sort(myCompare);//是成员函数 从大到小  降序
    cout<<"降序排序后："<<endl;
    printList(L1);
}

int main(){
    test01();
    test02();
    cout<<"HelloWorld"<<endl;
    return 0;
}


