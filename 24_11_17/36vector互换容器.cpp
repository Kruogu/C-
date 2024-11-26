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

//3.2.7 vector互换容器
//swap(vec);     //将vec与本身的元素互换

//1、基本使用
void test01(){
    vector<int>v1;
    for(int i=0;i<10;i++){
        v1.push_back(i);//0-9
    }
    cout<<"交换前："<<endl;
    printVector(v1);

    vector<int>v2;
    for(int i=10;i>0;i--){
        v2.push_back(i);//0-9
    }
    printVector(v2);

    cout<<"交换后："<<endl;
    v1.swap(v2);
    printVector(v1);
    printVector(v2);
}
//2、实际用途
//巧用swap可以收缩内存空间
void test02(){
    vector<int>v;
    for(int i=0;i<100000;i++){//不要遍历
        v.push_back(i);//0-9
    }
    cout<<"v的容量为："<<v.capacity()<<endl;//v的容量为：131072
    cout<<"v的大小为："<<v.size()<<endl;//v的大小为：100000

    v.resize(3);//重新指定大小
    cout<<"v的容量为："<<v.capacity()<<endl;//v的容量为：131072
    cout<<"v的大小为："<<v.size()<<endl;//v的大小为：3

    //巧用swap收缩内存   也可以用shrink_to_it直接缩到3  这个暂时没学
    vector<int>(v).swap(v);
    cout<<"v的容量为："<<v.capacity()<<endl;//v的容量为：3
    cout<<"v的大小为："<<v.size()<<endl;//v的大小为：3
}
int main(){
    test01();
    test02();
    cout<<"HelloWorld"<<endl;
    return 0;
}
