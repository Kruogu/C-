//
// Created by tianya on 2024/11/18.
//
#include "iostream"
using namespace std;
#include "deque"

//3.3.4 deque��С����

//deque.empty();              //�ж������Ƿ�Ϊ��
//deque.size();               //����������Ԫ�صĸ���
//deque.resize(num);          //����ָ�������ĳ���Ϊum,�������䳤������Ĭ��ֵ�����λ�á�
//                            //���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
//
//deque.resize(num,elem);     //����ָ�������ĳ���Ϊnum,�������䳤������elemֵ�����λ�á�
//                            //���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����




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

    if(d1.empty()){
        cout<<"d1Ϊ��"<<endl;
    } else{
        cout<<"d1��Ϊ��"<<endl;
        cout<<"d1�Ĵ�СΪ��"<<d1.size()<<endl;
        //deque����û����������
//        cout<<"d1������Ϊ��"<<d1.<<endl;
    }

//    ����ָ����С
    d1.resize(15);
    printDuque(d1);

    d1.resize(20,1);//��1���
    printDuque(d1);

    d1.resize(5);//����  5��
    printDuque(d1);

}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
