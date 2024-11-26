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

//3.2.4 vector容量和大小

void test01(){
    vector<int>v1;
    for(int i=0;i<10;i++){
        v1.push_back(i);//0-9
    }
    printVector(v1);

    if(v1.empty()){//为真代表容器为空
        cout<<"v1为空"<<endl;
    } else{
        cout<<"v1不为空"<<endl;
        cout<<"v1的容量为："<<v1.capacity()<<endl;
        cout<<"v1的大小为："<<v1.size()<<endl;
    }
//    重新指定大小
    v1.resize(15);//利用重载版本，可以指定默认填充值，参数2
    printVector(v1);//如果重新指定的比原来长了，默认用0填充新的位置
    cout<<"v1扩容后的容量为："<<v1.capacity()<<endl;
    cout<<"v1扩容后的大小为："<<v1.size()<<endl;

    //重载版本
    v1.resize(20,100);//用100来填充
    printVector(v1);

    //比原来短了
    v1.resize(5);//如果重新指定的比原来短了，超出部分会删除掉
    printVector(v1);

}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
