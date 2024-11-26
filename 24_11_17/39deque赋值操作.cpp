//
// Created by tianya on 2024/11/18.
//
#include "iostream"
using namespace std;
#include "deque"

//3.3.3 deque��ֵ����

//deque& roperator=(const deque &deq);   //���صȺŲ�����
//assign(beg,end);                       //��[beg,end)�����е����ݿ�����ֵ������
//assign(n,elem);                        //��n��elem������ֵ������


void printDuque(const deque<int> &d){//��const����ֻ��������д
    for(deque<int>::const_iterator it=d.begin();it!=d.end();it++){//��const
        cout<<*it<<" ";
    }
    cout<<endl;
}

void test01(){
    deque<int>d1;
    for(int i=0;i<10;i++){
        d1.push_back(i);//0-9
    }
    printDuque(d1);

//    operator=��ֵ
    deque<int>d2;
    d2 = d1;
    printDuque(d2);

//    assign��ֵ
    deque<int>d3;
    d3.assign(d1.begin(),d1.end());
    printDuque(d3);

    deque<int>d4;
    d4.assign(10,100);
    printDuque(d4);

//    //���䷽ʽ����
//    deque<int>d2(d1.begin(),d1.end());//����d1
//    printDuque2(d2);
//
//    //n��elem�ķ�ʽ
//    deque<int>d3(10,100);//10��100
//    printDuque2(d3);
//
////    ��������
//    deque<int>d4(d3);//d3ֱ�Ӹ�d4
//    printDuque2(d4);

}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
