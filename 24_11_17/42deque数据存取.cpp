//
// Created by tianya on 2024/11/18.
//
#include "iostream"
using namespace std;
#include "deque"

//3.3.6 deque���ݴ�ȡ

//at(int idx);        //��������idx��ָ������
//operator[];         //��������idx��ָ������
//front();            //���������е�һ������Ԫ��
//back();             //�������������һ������Ԫ��

void printDuque(const deque<int> &d){//��const����ֻ��������д
    for(deque<int>::const_iterator it=d.begin();it!=d.end();it++){//��const
        cout<<*it<<" ";
    }
    cout<<endl;
}

void test01(){
    deque<int>d;

    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_front(100);
    d.push_front(200);
    d.push_front(300);
    //300 200 100 10 20 30

//    printDuque(d);

//    ͨ��[]��ʽ����Ԫ��
    for(int i=0;i<d.size();i++){//��const
        cout<<d[i]<<" ";
    }
    cout<<endl;

//    ͨ��at��ʽ����Ԫ��
    for(int i=0;i<d.size();i++){//��const
        cout<<d.at(i)<<" ";
    }
    cout<<endl;

//    ��ȡ��һ��Ԫ��
    cout<<"��һ��Ԫ��Ϊ��"<<d.front()<<endl;
//    ��ȡ���һ��Ԫ��
    cout<<"���һ��Ԫ��Ϊ��"<<d.back()<<endl;

}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
