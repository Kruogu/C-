//
// Created by tianya on 2024/11/19.
//
#include "iostream"
using namespace std;
#include "map"
//3.9.3map��С�ͽ���

//mize();        //����������Ԫ�ص���Ŀ
//empty();       //�ж������Ƿ�Ϊ��
//mwap(mt);      //����������������


void printMap(map<int,int> &m){
    for(map<int,int>::iterator it = m.begin();it!=m.end();it++){
        cout<<"key = "<<(*it).first
            <<" value = "<<it->second<<endl;
    }
    cout<<endl;
}

void test01(){
    map<int,int>m;

//    ��������
    m.insert(pair<int,int>(1,10));
    m.insert(pair<int,int>(3,30));
    m.insert(pair<int,int>(2,20));
    m.insert(pair<int,int>(4,40));

//    ��������
//    map�����ص㣺����Ԫ�ز���ʱ���Զ�������
//    map��������������ظ�ֵ,���˰ײ壬����ʾ
    printMap(m);//�������������  10 20 30 40

//    �ж��Ƿ�Ϊ��
    if(m.empty()){
        cout<<"mΪ��"<<endl;
    } else{
        cout<<"m��Ϊ��"<<endl;
        cout<<"m��Ԫ�ظ���Ϊ��"<<m.size()<<endl;
    }


}

//����
void test02(){

    map<int,int>m;
//    ��������
    m.insert(pair<int,int>(1,10));
    m.insert(pair<int,int>(3,30));
    m.insert(pair<int,int>(2,20));
    m.insert(pair<int,int>(4,40));


    map<int,int>m2;
//    ��������
    m2.insert(pair<int,int>(5,100));
    m2.insert(pair<int,int>(7,200));
    m2.insert(pair<int,int>(8,400));
    m2.insert(pair<int,int>(6,300));

    cout<<"\n����ǰ��"<<endl;
    printMap(m);
    printMap(m2);

    m.swap(m2);//����

    cout<<"������"<<endl;
    printMap(m);
    printMap(m2);
}

int main(){
    test01();
    test02();
    cout<<"HelloWorld"<<endl;
    return 0;
}
