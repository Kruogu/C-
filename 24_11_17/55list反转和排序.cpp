//
// Created by tianya on 2024/11/19.
//
#include "list"

#include "iostream"
using namespace std;
#include "algorithm"//��׼�㷨ͷ�ļ�

//3.7.7list��ת������

//reverse();   //��ת����    12345      54321
//sort();      //��������


void printList(const list<int> &L){
//    it����++����Ϊ���ع��ˣ���װ��ֱ��ʹ��
    for(list<int>::const_iterator it = L.begin();it!=L.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

void test01(){
//    ����list����
    list<int>L1; //Ĭ�Ϲ���

//    �������  β��
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    L1.push_back(50);


//    ��ת
    cout<<"��תǰ��"<<endl;
    printList(L1);
    L1.reverse();
    cout<<"��ת��"<<endl;
    printList(L1);


}

bool myCompare(int v1,int v2){
    //���� ���õ�һ���� > �ڶ�����
    return v1>v2;//����������ͷ�����
}

//����
void test02(){
    //    ����list����
    list<int>L1; //Ĭ�Ϲ���

//    �������  β��
    L1.push_back(30);
    L1.push_back(10);
    L1.push_back(40);
    L1.push_back(20);
    L1.push_back(50);

//    Ĭ������  ��С����
    cout<<"����ǰ��"<<endl;
    printList(L1);

//    ���в�֧��������ʵ��������������������ñ�׼�㷨��algorithm
//    ��֧��������ʵ��������������ڲ����ṩ��ӦһЩ�㷨
//    sort(L1.begin(),L1.end());//����
    L1.sort();//�ǳ�Ա���� ��С����  ����

    cout<<"���������"<<endl;
    printList(L1);

//    ���ذ汾  ���������������  ������棬�ͽ��򣬷�֮��Ȼ   ���зº�����û��
    L1.sort(myCompare);//�ǳ�Ա���� �Ӵ�С  ����
    cout<<"���������"<<endl;
    printList(L1);
}

int main(){
    test01();
    test02();
    cout<<"HelloWorld"<<endl;
    return 0;
}


