//
// Created by tianya on 2024/11/18.
//
#include "iostream"
using namespace std;
#include "deque"

//3.3.4 deque大小操作

//deque.empty();              //判断容器是否为空
//deque.size();               //返回容器中元素的个数
//deque.resize(num);          //重新指定容器的长度为um,若容器变长，则以默认值填充新位置。
//                            //如果容器变短，则末尾超出容器长度的元素被删除。
//
//deque.resize(num,elem);     //重新指定容器的长度为num,若容器变长，则以elem值填充新位置。
//                            //如果容器变短，则末尾超出容器长度的元素被删除。




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

    if(d1.empty()){
        cout<<"d1为空"<<endl;
    } else{
        cout<<"d1不为空"<<endl;
        cout<<"d1的大小为："<<d1.size()<<endl;
        //deque容器没有容量概念
//        cout<<"d1的容量为："<<d1.<<endl;
    }

//    重新指定大小
    d1.resize(15);
    printDuque(d1);

    d1.resize(20,1);//用1填充
    printDuque(d1);

    d1.resize(5);//短了  5个
    printDuque(d1);

}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
