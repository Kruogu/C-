//
// Created by tianya on 2024/11/20.
//
#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"
#include "functional"//�ڽ���������ͷ�ļ�

//5.1.2 78���ñ����㷨transfrom

//��transform(iterator beg1,iterator end1,iterator beg2,_func);
//beg1Դ������ʼ������
//end1 Դ��������������
//beg2Ŀ��������ʼ������
//_func�������ߺ�������

//�º���
class Transform{
public:
    int operator()(int v){//ȡ���� �ٷŻ�ȥ
//        return v;
        return v+1000;
    }
};

//�º���
class MyPrint{
public:
    void operator()(int val){
        cout<<val<<" ";
    }
};
void test01(){
    vector<int>v;

    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }

    vector<int>vTarget;//Ŀ������  Target Ŀ��
    vTarget.resize(v.size());//Ŀ������ ��Ҫ��ǰ���ٿռ�

    transform(v.begin(),v.end(),vTarget.begin(),Transform());

//    �º�������   ������С����  �����������
    for_each(vTarget.begin(),vTarget.end(), MyPrint());
    cout<<endl;
}

int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
