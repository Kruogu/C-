//
// Created by tianya on 2024/11/19.
//
#include "list"

#include "iostream"
using namespace std;

//3.7.4list容器大小操作

//size();             //返回容器中元素的个数
//empty();            //判断容器是否为空
//resize(num);        //重新指定容器的长度为um,若容器变长，则以默认值填充新位置。
//                    //如果容器变短，则末尾超出容器长度的元素被删除。
//
//resize(num,elem);   //重新指定容器的长度为num,若容器变长，则以elem值填充新位置。
//                    //如果容器变短，则末尾超出容器长度的元素被删除。

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

//    判断容器是否为空
    if(L1.empty()){
        cout<<"L1为空"<<endl;
    } else{
        cout<<"L1不为空"<<endl;
        cout<<"L1的元素个数为："<<L1.size()<<endl;
    }

//    重新指定大小
    L1.resize(10);//0补齐
    printList(L1);

    L1.resize(15,10000);//15个10000补齐
    printList(L1);

    L1.resize(2);//变短了
    printList(L1);

}


int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}

