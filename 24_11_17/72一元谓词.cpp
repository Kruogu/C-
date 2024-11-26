//
// Created by tianya on 2024/11/20.
//
#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"
//4.2.2一元谓词

//仿函数返回值类型是bool数据类型，称为谓词
//一元谓词

class GreaterFive{
public:
    bool operator()(int val){
        return val>5;
    }
};

void test01(){
    vector<int>v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }

//    查找容器中 有没有大于5的数字
    //三个参数  区间开始，结束  谓词(正常创建对象也可以) GreaterFive()匿名函数对象
//    返回的是迭代器
    vector<int>::iterator it = find_if(v.begin(),v.end(),GreaterFive());
    if(it == v.end()){
        cout<<"未找到"<<endl;
    } else{
        cout<<"找到了大于5的数字为："<<*it<<endl;//找到了大于5的数字为：6
    }
}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
