//
// Created by tianya on 2024/11/19.
//
#include "iostream"
using namespace std;
#include "map"
//3.9.5map���� ���Һ�ͳ��

//find(key);   //����key�Ƿ���ڣ������ڣ����ظü���Ԫ�صĵ�������
//                             �������ڣ�����map.end();

//count(key);  //ͳ��key��Ԫ�ظ��� (0����1)

void printMap(map<int,int> &m){
    for(map<int,int>::iterator it = m.begin();it!=m.end();it++){
        cout<<"key = "<<(*it).first
            <<" value = "<<it->second<<endl;
    }
    cout<<endl;
}

//����
void test01(){
    map<int,int>m1;

//    ��������
    m1.insert(pair<int,int>(1,10));
    m1.insert(pair<int,int>(3,30));
    m1.insert(pair<int,int>(2,20));

//    ��������
//    map�����ص㣺����Ԫ�ز���ʱ���Զ�������
//    map��������������ظ�ֵ,���˰ײ壬����ʾ
    printMap(m1);//�������������  10 20 30 40

//    ����
    map<int,int>::iterator pos = m1.find(3);//pos  ������λ��
//    map<int,int>::iterator pos = m1.find(300);//pos  δ�ҵ�

    //    �ж��Ƿ�Ϊ��
    if(pos != m1.end()){
        cout<<"�ҵ�Ԫ�� key = "<<(*pos).first
            <<" value = "<<pos->second<<endl;
    } else{
        cout<<"δ�ҵ�Ԫ��"<<endl;
    }
}

//ͳ��
void test02(){
    map<int,int>m1;

//    ��������
    m1.insert(pair<int,int>(1,10));
    m1.insert(pair<int,int>(3,30));
    m1.insert(pair<int,int>(2,20));
    m1.insert(pair<int,int>(3,30));//���в岻��ȥ��count��1

//    ͳ��30�ĸ���
//    map����������ظ�key��coountͳ�ƽ����Ҫô��0  Ҫô��1
//    multimap��countͳ�ƿ��ܴ��� 1
    int num1 = m1.count(3);//�����м�������һ��
    cout<<"num1 = "<<num1<<endl;//num = 1

    int num2 = m1.count(50);//û��
    cout<<"num2 = "<<num2<<endl;//num = 0
}

int main(){
    test01();
    test02();
    cout<<"HelloWorld"<<endl;
    return 0;
}
