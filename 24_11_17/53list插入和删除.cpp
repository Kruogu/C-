//
// Created by tianya on 2024/11/19.
//
#include "list"

#include "iostream"
using namespace std;

//3.7.5list插入和删除

//push_back(elem);        //在容器尾部劭加入一个元素
//pop_back();             //删除容器中最后一个元素
//push_front(elem);       //在容器开头插入一个元素
//pop_front();           //从容器开头移除第一个元素

//insert(pos,elem);      //在pos位置插elem元素的拷贝，返回新数据的位置。
//insert(pos,n,elem);    //在pos位置插入n个elem数据，无返回值。
//insert(pos,beg,end);   //在pos位置插入[beg,end)区间的数据，无返回值。

//clear();               //移除容器的所有数据
//erase(beg,end);        //删除[beg,end)区间的数据，返回下一个数据的位置。
//erase(pos);            //删除pos位置的数据，返回下一个数据的位置。
//remove(elem);          //删除容器中所有与elem值匹配的元素。

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

//    头插
    L1.push_front(100);
    L1.push_front(200);
    L1.push_front(300);

//    遍历容器
    printList(L1);//300 200 100 10 20 30

//    尾删
    L1.pop_back();
    printList(L1);//300 200 100 10 20

//    头删
    L1.pop_front();
    printList(L1);//200 100 10 20

//    insert插入
    L1.insert(L1.begin(),1000);//相当于头插
    printList(L1);//1000 200 100 10 20

    list<int>::iterator it = L1.begin();
    L1.insert(++it,2000);//在第二个位置插入2000
    printList(L1);//1000 2000 200 100 10 20

//    删除
    it = L1.begin();

    L1.erase(it);//删除头部
    printList(L1);//2000 200 100 10 20

    it = L1.begin();//这行必须再写一次，不写就报错
    L1.erase(++it);//删除第二个位置  不能写it++
    printList(L1);//2000 100 10 20

//    移除
    L1.push_back(10000);
    printList(L1);//2000 100 10 20 10000

    L1.remove(10000);//删掉10000
    printList(L1);//2000 100 10 20

//    多插几个再删除试试
    L1.push_back(10000);
    L1.push_back(10000);
    L1.push_back(10000);
    printList(L1);//2000 100 10 20 10000 10000 10000

    L1.remove(10000);//删掉所有10000
    printList(L1);//2000 100 10 20

//    清空
    L1.clear();
    printList(L1);//2000 100 10 20
}


int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}

