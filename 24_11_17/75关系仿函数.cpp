//
// Created by tianya on 2024/11/20.
//
#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"//���ڲ���Ҳ��
#include "functional"//�ڽ���������ͷ�ļ� ���ڲ���Ҳ��

//4.3.3��ϵ�º���

//template < class T > bool equal_to <T>         //����
//template < class T > bool not equal to <T>     //������
//template < class T > bool greater <T>          //����
//template < class T > bool greater_equal <T>    //���ڵ���
//template < class T > bool less <T>             //С��
//template < class T > bool less_equal <T>       //С�ڵ���


//�ڽ���������   ��ϵ�º���
//����  greater

class MyCompare{
public:
//    ����
    bool operator()(int va1,int va2){
        return va1>va2;
    }
};

void test01(){
    vector<int>v;

    v.push_back(10);
    v.push_back(30);
    v.push_back(40);
    v.push_back(20);
    v.push_back(50);

    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

//    ����
    sort(v.begin(),v.end());
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

//    ����  ν��  ����  greater<int>()�ڽ���������
    sort(v.begin(),v.end(),greater<int>());//����
//    sort(v.begin(),v.end(),greater());//����
//    sort(v.begin(),v.end(),MyCompare());
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
