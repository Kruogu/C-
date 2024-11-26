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

//3.2.8 vectori预留空间
//reserve(int len);     //容器预留len个元素长度，预留位置不初始化，元素不可访问。

void test01(){
    vector<int>v;
//    利用reserve预留空间
    v.reserve(100000);//加上这行 num就是1，否则num=18
    int num = 0;//统计开辟次数
    int *p = NULL;
    for(int i=0;i<100000;i++){//不要遍历
        v.push_back(i);//0-99999

        if(p!= &v[0]){
            p = &v[0];
            num++;
        }
    }
    cout<<"num = "<<num<<endl;//18  代表重复开辟了18次空间，直到找到能存放100000大小的空间

    cout<<"v的容量为："<<v.capacity()<<endl;//v的容量为：131072
    cout<<"v的大小为："<<v.size()<<endl;//v的大小为：100000

}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
