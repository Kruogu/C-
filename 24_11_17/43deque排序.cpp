//
// Created by tianya on 2024/11/18.
//
#include "iostream"
using namespace std;
#include "deque"
#include "algorithm"//��׼�㷨ͷ�ļ�

//3.3.7 deque����

//sort(iterator beg,iterator end)   //��beg��end������Ԫ�ؽ�������

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
    printDuque(d);

    //����  Ĭ���������  ��С��������
    //����֧��������ʵĵ�����������������������sort�㷨ֱ�Ӷ����������
    //vector����Ҳ��������sort��������
    sort(d.begin(), d.end());//10 20 30 100 200 300
    cout<<"���������"<<endl;
//    std::sort(d.begin(), d.end());//ͬ��д��һ��
    printDuque(d);

//    sort(d.end(), d.begin());//���� ������ֱ�ӱ���  ������
    sort(d.rbegin(),d.rend());//��������  ����ɹ�  �Ӵ�С
    cout<<"���������"<<endl;
    printDuque(d);


}
int main(){

    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
