//
// Created by tianya on 2024/22/19.
//
#include "iostream"
using namespace std;
#include "set"
//3.8.8set��������

//ʾ��һ set��� ���� ��������

class MyCompare{
public:
//    ע�⣬��ΪC++11�����Ե�Ե�ʣ�������Ҫ�ڲ����б�����const
    bool operator()(int v1,int v2)const{//��һ��С���Ŵ���Ҫ���صķ��ţ��ڶ���С���Ŵ�������б�
//        �����ǽ���  Ĭ��������
        return v1>v2;
    }
};

void test01(){
    set<int>s1;

    s1.insert(10);
    s1.insert(40);
    s1.insert(20);
    s1.insert(50);
    s1.insert(30);
    s1.emplace(60);//c++11������

//    �Զ��ź������Ѿ�����ӡ���һ��
    for(set<int>:: iterator it=s1.begin();it!=s1.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

//    ָ���������Ϊ�Ӵ�С  �ڲ�������֮ǰ��Ҫ���øı�,���ȥ�͸Ĳ�����
//    ���÷º���
    set<int,MyCompare>s2;//�ŵ�ģ������б���

    s2.insert(10);
    s2.insert(40);
    s2.insert(20);
    s2.insert(50);
    s2.insert(30);

//    �鿴��ӡ�Ƿ��ź���
    for(set<int>:: iterator it=s2.begin();it!=s2.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

}

int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
