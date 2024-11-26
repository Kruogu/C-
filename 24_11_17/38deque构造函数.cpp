//
// Created by tianya on 2024/11/18.
//
#include "iostream"
using namespace std;
#include "deque"

//3.3.2 deque���캯��

//deque<T> deqT;             //Ĭ�Ϲ�����ʽ
//deque(beg,end);            //���캯����[beg,end)�����е�Ԫ�ؿ���������
//deque(n,elem);             //���캯����n��elem����������
//deque(const deque &deq);   //�������캯��

void printDuque1(deque<int> &d){//����������  ����д������
    for(deque<int>::iterator it=d.begin();it!=d.end();it++){
        *it = 100;//���� д ����
        cout<<*it<<" ";
    }
    cout<<endl;
}
void printDuque2(const deque<int> &d){//��const����ֻ��������д
    for(deque<int>::const_iterator it=d.begin();it!=d.end();it++){//��const
//        *it = 100;//����   �����е����ݲ������޸���  ֻ���Ͳ���д��
        cout<<*it<<" ";
    }
    cout<<endl;
}

void test01(){
    deque<int>d1;
    for(int i=0;i<10;i++){//��Ҫ����
        d1.push_back(i);//0-9
    }
    printDuque2(d1);
//    printDuque1(d1);

    //���䷽ʽ����
    deque<int>d2(d1.begin(),d1.end());//����d1
    printDuque2(d2);

    //n��elem�ķ�ʽ
    deque<int>d3(10,100);//10��100
    printDuque2(d3);

//    ��������
    deque<int>d4(d3);//d3ֱ�Ӹ�d4
    printDuque2(d4);

}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
