//
// Created by tianya on 2024/11/20.
//
#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"//���ڲ���Ҳ��
#include "functional"//�ڽ���������ͷ�ļ� ���ڲ���Ҳ��

//4.3.4�߼��º���

//template < class T > bool logical_and <T>         //�߼���
//template < class T > bool logical_or <T>          //�߼���
//template < class T > bool logical_not <T>         //�߼���


//�ڽ���������   �߼��º���
//�߼���  logical_not

void test01(){
    vector<bool>v;

    v.push_back(true);
    v.push_back(false);
    v.push_back(true);
    v.push_back(false);


    for(vector<bool>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    //�����߼��� ������v���˵�����v2�У���ִ�� ȡ�� ����
    vector<bool>v2;
    v2.resize(v.size());//4 ������ǰ���ٿռ�
    //ԭ������㣬�յ������     Ŀ������ ���    �º���
    transform(v.begin(),v.end(),v2.begin(),logical_not<bool>());//��ͻ��������transfrom
    for(vector<bool>::iterator it=v2.begin();it!=v2.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
