//
// Created by tianya on 2024/11/20.
//
#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"
//4.2.3��Ԫν��

//�º�������ֵ������bool�������ͣ���Ϊν��

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
    v.push_back(40);
    v.push_back(20);
    v.push_back(30);
    v.push_back(50);

    sort(v.begin(),v.end());

//    Ĭ������ ��ӡ
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    //ʹ�ú�������ı��㷨���ԣ���Ϊ�������Ϊ�Ӵ�С������
    sort(v.begin(),v.end(),MyCompare());

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
