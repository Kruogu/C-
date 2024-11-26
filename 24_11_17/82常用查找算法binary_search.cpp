//
// Created by tianya on 2024/11/20.
//
#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"
#include "functional"//内建函数对象头文件

//5.2.4 常用查找算法binary_search

//·bool binary_search(iterator beg,iterator end,value);
//查找指定的元素，查到返回true否则false

//注意：在无序序列中不可用

//beg开始达代器
//end结束迭代器
//value查找的元素



class Person{
public:
    Person(string name,int age){
        this->m_Name = name;
        this->m_Age = age;
    }
//    重载 == 符号 让底层find知道如何对比person数据类型
    bool operator==(const Person &p){
        if(this->m_Name==p.m_Name && this->m_Age== this->m_Age){
            return true;
        } else{
            return false;
        }
    }
    string m_Name;//姓名
    int m_Age;//年龄
};

class GreaterFive{
public:
    bool operator()(int val){
        return val>5;
    }
};

//谓词
class Greater20{
public:
    bool operator()(Person &p){
        return p.m_Age>20;
    }
};

//查找内置数据类型
void test01(){
    vector<int>v;

//    观察哪些同时 重复和相邻
    for (int i = 0; i < 10; ++i) {
//        int ret = rand()%10;//1 7 4 0 9 4 8 8 2 4
//        v.push_back(ret);//无序序列就找不到了
//        v.push_back(rand()%10);//1 7 4 0 9 4 8 8 2 4
        v.push_back(i);//有序才可以找到
    }

    //遍历
    for(vector<int>::iterator it = v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

//    查找容器中是否有9元素   如果是无序序列，结果未知！
//    注意：容器必须是 有序 的序列     二分查找
   bool ret = binary_search(v.begin(),v.end(),9);
    if(ret){
        cout<<"找到了元素："<<int(ret)<<endl;//找到元素：9
    } else{
        cout<<"未找到元素："<<int(ret)<<endl;
    }

}

//查找自定义数据类型
void test02(){
    vector<Person>v;
//    创建数据
    Person p1("aaa",10);
    Person p2("bbb",20);
    Person p3("ccc",30);
    Person p4("ddd",40);

//    放入到容器中
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    Person pp("bbb",20);

//    找年龄大于20的人
//    find报错，没有重载运算符  两种方法都可以比较
    vector<Person>::iterator it = find_if(v.begin(),v.end(),Greater20());
    if(it==v.end()){
        cout<<"没有找到！"<<endl;
    } else{
        cout<<"找到元素 姓名："<<it->m_Name
            <<" 年龄："<<(*it).m_Age<<endl;
    }
}
int main(){
    test01();
//    test02();
    cout<<"HelloWorld"<<endl;
    return 0;
}
