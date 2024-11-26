//
// Created by tianya on 2024/11/19.
//
#include "list"

#include "iostream"
using namespace std;

//3.7.4list������С����

//size();             //����������Ԫ�صĸ���
//empty();            //�ж������Ƿ�Ϊ��
//resize(num);        //����ָ�������ĳ���Ϊum,�������䳤������Ĭ��ֵ�����λ�á�
//                    //���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
//
//resize(num,elem);   //����ָ�������ĳ���Ϊnum,�������䳤������elemֵ�����λ�á�
//                    //���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����

void printList(const list<int> &L){
//    it����++����Ϊ���ع��ˣ���װ��ֱ��ʹ��
    for(list<int>::const_iterator it = L.begin();it!=L.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

void test01(){
//    ����list����
    list<int>L1; //Ĭ�Ϲ���

//    �������
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);

//    ��������
    printList(L1);

//    �ж������Ƿ�Ϊ��
    if(L1.empty()){
        cout<<"L1Ϊ��"<<endl;
    } else{
        cout<<"L1��Ϊ��"<<endl;
        cout<<"L1��Ԫ�ظ���Ϊ��"<<L1.size()<<endl;
    }

//    ����ָ����С
    L1.resize(10);//0����
    printList(L1);

    L1.resize(15,10000);//15��10000����
    printList(L1);

    L1.resize(2);//�����
    printList(L1);

}


int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}

