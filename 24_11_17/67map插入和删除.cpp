//
// Created by tianya on 2024/11/19.
//
#include "iostream"
using namespace std;
#include "map"
//3.9.4map���� �����ɾ��

//insert(elem);        //�������в���Ԫ�ء�
//clear();             //�������Ԫ��
//erase(pos);          //ɾ��pos��������ָ��Ԫ�أ�������һ��Ԫ�صĵ�������
//erase(beg,end);      //ɾ������[beg,end)������Ԫ�أ�������һ��Ԫ�صĵ�������
//erase(key);          //ɾ��������ֵΪkey��Ԫ�ء�

void printMap(map<int,int> &s){
    for(map<int,int>::iterator it = s.begin();it!=s.end();it++){
        cout<<"key = "<<(*it).first
            <<" value = "<<it->second<<endl;
    }
    cout<<endl;
}

void test01(){
    map<int,int>m1;
    
//    ��һ�� ��������
    m1.insert(pair<int,int>(1,10));
    m1.insert(pair<int,int>(3,30));
    m1.insert(pair<int,int>(2,20));

//    ��������
//    map�����ص㣺����Ԫ�ز���ʱ���Զ�������
//    map��������������ظ�ֵ,���˰ײ壬����ʾ
    printMap(m1);//�������������  10 20 30

//    �ڶ��ֲ���  ��ʦϲ������
    m1.insert(make_pair(4,40));
    printMap(m1);//�������������  10 20 30 40

//    �����ֲ���  map�������µ�ֵ����
    m1.insert(map<int,int>::value_type (5,50));
    printMap(m1);//�������������  10 20 30 40 50

//    ������  []��������룬��;��������key���ʵ�value
    m1[6] = 60;
    printMap(m1);//�������������  10 20 30 40 50 60

    cout<<m1[7]<< endl;//û��7 �����0�����Զ�������һ��value������������ʹ��[]��ʽ����
    cout<<"����m1[6]��"<<m1[6]<< endl;//����
    printMap(m1);//�������������  10 20 30 40 50 60 0

//    ɾ��
    cout<<"ɾ����"<< endl;
    m1.erase(m1.begin());//ɾ��ͷ 10
    printMap(m1);//20 30 40 50 60 0

//    ɾ�����ذ汾
    m1.erase(3);//����keyɾ������valueû��ϵ
    printMap(m1);//20 40 50 60 0

//    ���
//    m1.erase(m1.begin(),m1.end());
    m1.clear();
    printMap(m1);//��
}

int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
