//
// Created by tianya on 2024/11/19.
//
#include "list"

#include "iostream"
using namespace std;

//3.7.3list容器的赋值和交换
//assign(beg,end);                    //将[beg,end)区间中的数据拷贝赋值给本身。
//assign(n,elem);                     //将n个elem拷贝赋值给本身。
//list&operator=(const list & lst);   //重载等号操作符
//swap(1st);                          //将lst与本身的元素互换。


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

//    添加数据
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);

//    遍历容器
    printList(L1);

//   赋值操作
    list<int>L2;
    L2 = L1;
    printList(L2);

//    assign赋值
    list<int>L3;
    L3.assign(L2.begin(),L2.end());
    printList(L3);

//    n个elem
    list<int>L4;
    L4.assign(10,100);//10个100
    printList(L4);


}

void test02(){
    //    创建list容器
    list<int>L1; //默认构造

//    添加数据
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);

    //    交换swap
    list<int>L2;
    L2.assign(10,100);//10个100

    cout<<"交换前："<<endl;
    printList(L1);
    printList(L2);

    swap(L2,L1);

    cout<<"交换后："<<endl;
    printList(L1);
    printList(L2);
}

int main(){
//    test01();
    test02();
    cout<<"HelloWorld"<<endl;
    return 0;
}

