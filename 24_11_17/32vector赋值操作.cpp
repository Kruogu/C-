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

//3.2.3 vector赋值操作

void test01(){
    vector<int>v1;
    for(int i=0;i<10;i++){
        v1.push_back(i);//0-9
    }
    printVector(v1);

    //赋值
    vector<int>v2;
    v2 = v1;
    printVector(v2);

    //assign  赋值
    vector<int>v3;
    v3.assign(v1.begin(),v1.end());
    printVector(v3);

    //n个elem方式赋值
    vector<int>v4;
    v4.assign(10,100);
    printVector(v4);
}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
