//
// Created by tianya on 2024/11/20.
//
#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"
#include "functional"//�ڽ���������ͷ�ļ�

//5.2.3 ���ò����㷨adjacent_find

//adjacent_find(iterator beg,iterator end);
//���������ظ�Ԫ�أ���������Ԫ�صĵ�һ��λ�õĵ�����
//beg��ʼ������
//end����������

//����������������
void test01(){
    vector<int>v;

//    �۲���Щͬʱ �ظ�������
    for (int i = 0; i < 8; ++i) {
        int ret = rand()%5;//1 2 4 0 4 4 3 3
        v.push_back(ret);
    }

    //����
    for(vector<int>::iterator it = v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

//    ���������ظ�Ԫ��  ��������������ظ�Ԫ���أ�
//    ���ص�һ�������ظ�Ԫ�صĵ�����
    vector<int>::iterator pos = adjacent_find(v.begin(),v.end());
    if(pos==v.end()){
        cout<<"δ�ҵ������ظ�Ԫ��"<<endl;
    } else{
        cout<<"�ҵ������ظ�Ԫ�أ�"<<*pos<<endl;//�ҵ�Ԫ�أ�4
    }
}

int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
