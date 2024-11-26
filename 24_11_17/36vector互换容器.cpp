//
// Created by tianya on 2024/11/18.
//
#include "iostream"
using namespace std;
#include "vector"//������ͷ�ļ�

void printVector(vector<int> &v){//����������
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

//3.2.7 vector��������
//swap(vec);     //��vec�뱾���Ԫ�ػ���

//1������ʹ��
void test01(){
    vector<int>v1;
    for(int i=0;i<10;i++){
        v1.push_back(i);//0-9
    }
    cout<<"����ǰ��"<<endl;
    printVector(v1);

    vector<int>v2;
    for(int i=10;i>0;i--){
        v2.push_back(i);//0-9
    }
    printVector(v2);

    cout<<"������"<<endl;
    v1.swap(v2);
    printVector(v1);
    printVector(v2);
}
//2��ʵ����;
//����swap���������ڴ�ռ�
void test02(){
    vector<int>v;
    for(int i=0;i<100000;i++){//��Ҫ����
        v.push_back(i);//0-9
    }
    cout<<"v������Ϊ��"<<v.capacity()<<endl;//v������Ϊ��131072
    cout<<"v�Ĵ�СΪ��"<<v.size()<<endl;//v�Ĵ�СΪ��100000

    v.resize(3);//����ָ����С
    cout<<"v������Ϊ��"<<v.capacity()<<endl;//v������Ϊ��131072
    cout<<"v�Ĵ�СΪ��"<<v.size()<<endl;//v�Ĵ�СΪ��3

    //����swap�����ڴ�   Ҳ������shrink_to_itֱ������3  �����ʱûѧ
    vector<int>(v).swap(v);
    cout<<"v������Ϊ��"<<v.capacity()<<endl;//v������Ϊ��3
    cout<<"v�Ĵ�СΪ��"<<v.size()<<endl;//v�Ĵ�СΪ��3
}
int main(){
    test01();
    test02();
    cout<<"HelloWorld"<<endl;
    return 0;
}
