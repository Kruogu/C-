//
// Created by tianya on 2024/11/19.
//
#include "iostream"
using namespace std;
#include "set"
//3.8.4set���� �����ɾ��

//insert(elem);        //�������в���Ԫ�ء�
//clear();             //�������Ԫ��
//erase(pos);          //ɾ��pos��������ָ��Ԫ�أ�������һ��Ԫ�صĵ�������
//erase(beg,end);      //ɾ������[beg,end)������Ԫ�أ�������һ��Ԫ�صĵ�������
//erase(elem);         //ɾ��������ֵΪelem��Ԫ�ء�



void printSet(set<int> &s){
    for(set<int>::iterator it = s.begin();it!=s.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}


void test01(){
    set<int>s1;

//    �������� ֻ��insert��ʽ
    s1.insert(10);
    s1.insert(40);
    s1.insert(30);
    s1.insert(20);
    s1.insert(30);

//    ��������
//    set�����ص㣺����Ԫ�ز���ʱ���Զ�������
//    set��������������ظ�ֵ,���˰ײ壬����ʾ
    printSet(s1);//�������������  10 20 30 40

//    ɾ��
    s1.erase(s1.begin());//ɾ��ͷ 10
    printSet(s1);//20 30 40

//    ɾ�����ذ汾
    s1.erase(30);
    printSet(s1);//20 40

//    ���
//    s1.erase(s1.begin(),s1.end());
    s1.clear();
    printSet(s1);//��
}

int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
