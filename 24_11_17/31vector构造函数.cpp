//
// Created by tianya on 2024/11/17.
//

#include "iostream"
using namespace std;
#include "vector"//迭代器头文件
#include "algorithm"//标准算法头文件


//3.2.2 vector构造函数

//vector<T> v;                  //采用模板实现类实现，默认构造函数
//vector(v.begin(),v.end());    //将v[begin(0,end))区间中的元素拷贝给本身。
//vector(n,elem);               //构造函数将n个elem拷贝给本身。
//vector(const vector &vec);    //拷贝构造函数。

void printVector(vector<int> &v){//容器做参数
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test01(){
    vector<int>v1;//默认构造  无参构造

    for(int i=0;i<10;i++){
        v1.push_back(i);
    }
    printVector(v1);

//    通过区间方式进行构造
    vector<int>v2(v1.begin(),v1.end());
    printVector(v2);

//    n个elem构造
    vector<int>v3(10,100);//10个100
    printVector(v3);

//    拷贝构造函数
    vector<int>v4(v3);
    printVector(v4);
}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
