//
// Created by tianya on 2024/11/20.
//
#include "iostream"
using namespace std;
#include "map"

//3.9.6map���� ����

class MyCompare{
public:
    bool operator()(int v1,int v2)const{
//        ����
        return v1>v2;
    }
};

//�����������
//void printMap(map<int,int> &m){
void printMap(map<int,int,MyCompare> &m){
//    ����ͽ���һ��
//    for(map<int,int>::iterator it = m.begin();it!=m.end();it++){
    for(map<int,int,MyCompare>::iterator it = m.begin();it!=m.end();it++){
        cout<<"key = "<<(*it).first
            <<" value = "<<it->second<<endl;
    }
    cout<<endl;
}

void test01(){
//    map<int,int>m1;
    map<int,int,MyCompare>m1;//����֮ǰ�޸��������

//    ��������
    m1.insert(make_pair(1,10));
    m1.insert(make_pair(3,30));
    m1.insert(make_pair(2,200));
    m1.insert(make_pair(3,30));//���в岻��ȥ��count��1
    m1.insert(make_pair(4,20));

    printMap(m1);

}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}

