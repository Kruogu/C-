//
// Created by tianya on 2024/11/20.
//

#include "iostream"
using namespace std;
#include "map"

//3.9.2map����͸�ֵ


//���죺
//map<T1,T2> mp;                   //mapĬ�Ϲ��캯����
//map(const map &mp);              //�������캯��
//
//��ֵ��
//map& operator=(const map &mp);   //���صȺŲ�����

//��ӡmap
void printMap(map<int,int> &m){
    for(map<int,int>::iterator it=m.begin();it!=m.end();it++){
        cout<<"key = "<<(*it).first
            <<" value = "<<it->second<<endl;
    }
    cout<<endl;
}

void test01(){
//    ����map����
    map<int,int>m;

//    �����������
//    ��pair�е�һ��Ԫ��Ϊkey(��ֵ)�����������ã��ڶ���Ԫ��Ϊvalue(ʵֵ)
//    �����Զ�����  ���� ��С����
    m.insert(pair<int,int>(1,10));
    m.insert(pair<int,int>(3,30));
    m.insert(pair<int,int>(2,20));
    m.insert(pair<int,int>(4,40));

    printMap(m);

//    ��������
    map<int,int>m2(m);
    printMap(m2);

//    ��ֵ
    map<int,int>m3;
    m3 = m2;
    printMap(m3);
}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
