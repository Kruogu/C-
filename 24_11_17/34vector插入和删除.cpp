//
// Created by tianya on 2024/11/18.
//
#include "iostream"
using namespace std;
#include "vector"//迭代器头文件

void printVector(vector<int> &v){//容器做参数
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

//3.2.5 vector插入和删除

//push_back(ele);                                       //尾部插入元素ele
//pop_back();                                           //删除最后一个元素
//insert(const iterator pos,ele);                       //迭代器指向位置pos插入元素ele
//insert(const_iterator pos,int count,ele);             //迭代器指向位置pos插入count个元素ele
//erase(const_iterator pos);                            //删除迭代器指向的元素
//erase(const_iterator start,const_iterator end);       //删除迭代器从start到end之间的元素
//clear();                                              //删除容器中所有元素

void test01(){
    vector<int>v1;
    //尾插法
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);
    printVector(v1);

    //尾删法
    v1.pop_back();//50没了
    printVector(v1);

    //插入  第一个参数是迭代器
    v1.insert(v1.begin(),100);//头部插入100
    printVector(v1);

    v1.insert(v1.begin(),2,1000);//头部插入两个1000
    printVector(v1);

    v1.insert(v1.begin()+1,33);//第二个位置插入22
    printVector(v1);

    //删除
    v1.erase(v1.begin());//删除第一个
    printVector(v1);

    //相当于清空了
//    v1.erase(v1.begin(),v1.end());//从头到尾全删
    v1.clear();//清空函数，上一行写法也可以，二选一
    printVector(v1);


}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
