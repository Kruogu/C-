//
// Created by tianya on 2024/11/20.
//
#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"//���ڲ���Ҳ��
#include "functional"//�ڽ���������ͷ�ļ� ���ڲ���Ҳ��

//5.1.1 ���ñ����㷨 for_each

//��for_each(iterator beg,iterator end,_func);
//�����㷨 ��������Ԫ��
//beg��ʼ������
//end����������
//_func�������ߺ�������

//��ͨ����
void print01(int val){
    cout<<val<<" ";
}

//�º���
class print02{
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

//    ��ͨ��������
    for_each(v.begin(),v.end(), print01);
    cout<<endl;

//    �º�������   ������С����  �����������
    for_each(v.begin(),v.end(), print02());
    cout<<endl;
}

int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
