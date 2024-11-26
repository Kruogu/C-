//
// Created by tianya on 2024/11/21.
//
#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"//��׼�㷨ͷ�ļ�
#include "functional"//greater
#include "ctime"

//5.3.2 ���������㷨 random_shuffle
//����㷨��c++17��û���Ƴ���������shuffle

//��random_shuffle(iterator beg,iterator end);
//ָ����Χ�ڵ�Ԫ�������������
//beg��ʼ������
//end����������

void myPrint(int val){
    cout<<val<<" ";
}
void test01(){
    vector<int>v;

    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    cout<<"ϴ��ǰ��"<<endl;
    for_each(v.begin(),v.end(), myPrint);
    cout<<endl;

    cout<<"ϴ�ƺ�"<<endl;
    //����random_shuffle ϴ���㷨  ����˳��
//    shuffle(v.begin(),v.end());
    random_shuffle(v.begin(),v.end());

//    ��ӡ��� ���� ����
    for_each(v.begin(),v.end(), myPrint);
    cout<<endl;

//    for(vector<int>::iterator it = v.begin();it!=v.end();it++){
//        cout<<*it<<" ";
//    }
//    cout<<endl;

//    ����
    sort(v.begin(),v.end(),greater<int>());//ֱ�Ӹı�������˳��
    for_each(v.begin(),v.end(), myPrint);
    cout<<endl;

    sort(v.begin(),v.end());
    for_each(v.rbegin(),v.rend(), myPrint);//�����ӡ��������û��
    cout<<endl;
}
int main(){
//    srand(time(0));//���������
    srand((unsigned int)time(NULL));
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
