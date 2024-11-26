//
// Created by tianya on 2024/11/19.
//
#include "list"

#include "iostream"
using namespace std;

//3.7.5list�����ɾ��

//push_back(elem);        //������β��ۿ����һ��Ԫ��
//pop_back();             //ɾ�����������һ��Ԫ��
//push_front(elem);       //��������ͷ����һ��Ԫ��
//pop_front();           //��������ͷ�Ƴ���һ��Ԫ��

//insert(pos,elem);      //��posλ�ò�elemԪ�صĿ��������������ݵ�λ�á�
//insert(pos,n,elem);    //��posλ�ò���n��elem���ݣ��޷���ֵ��
//insert(pos,beg,end);   //��posλ�ò���[beg,end)��������ݣ��޷���ֵ��

//clear();               //�Ƴ���������������
//erase(beg,end);        //ɾ��[beg,end)��������ݣ�������һ�����ݵ�λ�á�
//erase(pos);            //ɾ��posλ�õ����ݣ�������һ�����ݵ�λ�á�
//remove(elem);          //ɾ��������������elemֵƥ���Ԫ�ء�

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

//    �������  β��
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);

//    ͷ��
    L1.push_front(100);
    L1.push_front(200);
    L1.push_front(300);

//    ��������
    printList(L1);//300 200 100 10 20 30

//    βɾ
    L1.pop_back();
    printList(L1);//300 200 100 10 20

//    ͷɾ
    L1.pop_front();
    printList(L1);//200 100 10 20

//    insert����
    L1.insert(L1.begin(),1000);//�൱��ͷ��
    printList(L1);//1000 200 100 10 20

    list<int>::iterator it = L1.begin();
    L1.insert(++it,2000);//�ڵڶ���λ�ò���2000
    printList(L1);//1000 2000 200 100 10 20

//    ɾ��
    it = L1.begin();

    L1.erase(it);//ɾ��ͷ��
    printList(L1);//2000 200 100 10 20

    it = L1.begin();//���б�����дһ�Σ���д�ͱ���
    L1.erase(++it);//ɾ���ڶ���λ��  ����дit++
    printList(L1);//2000 100 10 20

//    �Ƴ�
    L1.push_back(10000);
    printList(L1);//2000 100 10 20 10000

    L1.remove(10000);//ɾ��10000
    printList(L1);//2000 100 10 20

//    ��弸����ɾ������
    L1.push_back(10000);
    L1.push_back(10000);
    L1.push_back(10000);
    printList(L1);//2000 100 10 20 10000 10000 10000

    L1.remove(10000);//ɾ������10000
    printList(L1);//2000 100 10 20

//    ���
    L1.clear();
    printList(L1);//2000 100 10 20
}


int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}

