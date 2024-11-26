//
// Created by tianya on 2024/11/21.
//
#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"//标准算法头文件
#include "functional"//greater
#include "ctime"

//5.3.2 常用排序算法 random_shuffle
//这个算法在c++17中没有移除，改名叫shuffle

//·random_shuffle(iterator beg,iterator end);
//指定范围内的元素随机调整次序
//beg开始迭代器
//end结束迭代器

void myPrint(int val){
    cout<<val<<" ";
}
void test01(){
    vector<int>v;

    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    cout<<"洗牌前："<<endl;
    for_each(v.begin(),v.end(), myPrint);
    cout<<endl;

    cout<<"洗牌后："<<endl;
    //利用random_shuffle 洗牌算法  打乱顺序
//    shuffle(v.begin(),v.end());
    random_shuffle(v.begin(),v.end());

//    打印输出 升序 两种
    for_each(v.begin(),v.end(), myPrint);
    cout<<endl;

//    for(vector<int>::iterator it = v.begin();it!=v.end();it++){
//        cout<<*it<<" ";
//    }
//    cout<<endl;

//    降序
    sort(v.begin(),v.end(),greater<int>());//直接改变容器内顺序
    for_each(v.begin(),v.end(), myPrint);
    cout<<endl;

    sort(v.begin(),v.end());
    for_each(v.rbegin(),v.rend(), myPrint);//倒序打印，容器内没变
    cout<<endl;
}
int main(){
//    srand(time(0));//随机数种子
    srand((unsigned int)time(NULL));
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
