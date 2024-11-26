//
// Created by tianya on 2024/11/20.
//
#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"
//4.2.3二元谓词

//仿函数返回值类型是bool数据类型，称为谓词

class MyCompare{
public:
//    降序
    bool operator()(int va1,int va2){
        return va1>va2;
    }
};

void test01(){
    vector<int>v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(20);
    v.push_back(30);
    v.push_back(50);

    sort(v.begin(),v.end());

//    默认升序 打印
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    //使用函数对象改变算法策略，变为排序规则为从大到小，降序
    sort(v.begin(),v.end(),MyCompare());

    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;


}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
