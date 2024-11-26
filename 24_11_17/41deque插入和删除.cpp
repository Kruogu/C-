//
// Created by tianya on 2024/11/18.
//
#include "iostream"
using namespace std;
#include "deque"

//3.3.5 deque�����ɾ��

//���˲��������
//push_back(elem);             //������β�����һ������
//push front(elem);            //������ͷ������һ������
//pop_back();                  //ɾ���������һ������
//pop_front();                 //ɾ��������һ������
//
//ָ��λ�ò�����
//insert(pos,elem);            //��posλ�ò���һ��elemԪ�صĿ��������������ݵ�λ�á�
//insert(pos,n,elem);          //��posλ�ò���n��elem���ݣ��޷���ֵ��
//insert(pos,beg,end);         //��posλ�ò���[beg,end)��������ݣ��޷���ֵ��
//clear();                     //�����������������
//erase(beg,end);              //ɾ��[beg,end)��������ݣ�������һ�����ݵ�λ�á�
//erase(pos);                  //ɾ��posλ�õ����ݣ�������һ�����ݵ�λ�á�

void printDuque(const deque<int> &d){//��const����ֻ��������д
    for(deque<int>::const_iterator it=d.begin();it!=d.end();it++){//��const
        cout<<*it<<" ";
    }
    cout<<endl;
}

//���˲��������
void test01(){
    deque<int>d1;

//    β�巨
    d1.push_back(10);
    printDuque(d1);
    d1.push_back(20);
    printDuque(d1);

//    ͷ�巨
    d1.push_front(100);
    printDuque(d1);
    d1.push_front(200);//200 100 10 20
    printDuque(d1);

//    βɾ��
    d1.pop_back();//200 100 10
    printDuque(d1);

//    ͷɾ��
    d1.pop_front();//100 10
    printDuque(d1);
}

//ָ��λ�ò�����
void test02(){
    deque<int>d1;

    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(100);
    d1.push_front(200);
    //200 100 10 20

    printDuque(d1);

//    insert����
    d1.insert(d1.begin(),1000);
    //1000 200 100 10 20
    printDuque(d1);

    d1.insert(d1.begin(),2,10000);
    //10000 10000 1000 200 100 10 20
    printDuque(d1);

    //����������в���
    deque<int>d2;
    d2.push_back(1);
    d2.push_back(2);
    d2.push_back(3);

    d1.insert(d1.begin(),d2.begin(),d2.end());
    //1 2 3 10000 10000 1000 200 100 10 20
    printDuque(d1);
}

//ɾ��
void test03(){
    deque<int>d1;

    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(100);
    d1.push_front(200);
    //200 100 10 20

    printDuque(d1);
    //ɾ��
    deque<int>::iterator it = d1.begin();
    it++;//1
    d1.erase(it);//200 10 20   ɾ���ǵڶ���Ԫ��
    printDuque(d1);

//    �����䷽ʽɾ��
//    d1.erase(d1.begin(),d1.end());//ȫɾ
    d1.clear();//Ч��ͬ��
    printDuque(d1);
}
int main(){
//    test01();
//    test02();
    test03();
    cout<<"HelloWorld"<<endl;
    return 0;
}
