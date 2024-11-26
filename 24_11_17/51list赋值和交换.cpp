//
// Created by tianya on 2024/11/19.
//
#include "list"

#include "iostream"
using namespace std;

//3.7.3list�����ĸ�ֵ�ͽ���
//assign(beg,end);                    //��[beg,end)�����е����ݿ�����ֵ������
//assign(n,elem);                     //��n��elem������ֵ������
//list&operator=(const list & lst);   //���صȺŲ�����
//swap(1st);                          //��lst�뱾���Ԫ�ػ�����


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

//   ��ֵ����
    list<int>L2;
    L2 = L1;
    printList(L2);

//    assign��ֵ
    list<int>L3;
    L3.assign(L2.begin(),L2.end());
    printList(L3);

//    n��elem
    list<int>L4;
    L4.assign(10,100);//10��100
    printList(L4);


}

void test02(){
    //    ����list����
    list<int>L1; //Ĭ�Ϲ���

//    �������
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);

    //    ����swap
    list<int>L2;
    L2.assign(10,100);//10��100

    cout<<"����ǰ��"<<endl;
    printList(L1);
    printList(L2);

    swap(L2,L1);

    cout<<"������"<<endl;
    printList(L1);
    printList(L2);
}

int main(){
//    test01();
    test02();
    cout<<"HelloWorld"<<endl;
    return 0;
}

