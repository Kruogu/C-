//
// Created by tianya on 2024/11/19.
//
#include "iostream"
using namespace std;
#include "queue"

//3.6.2 ����queue���ýӿ�

class Person{
public:
    Person(string name,int age){
        this->m_Name = name;
        this->m_Age = age;
    }
    string m_Name;//����
    int m_Age;//����
};

void test01(){
//    �ص㣺�����Ƚ��ȳ����ݽṹ
//    queue<int>q;
//    ��������
    queue<Person>q;//����������������

//    ׼������
    Person p1("��ɮ",30);
    Person p2("�����",1000);
    Person p3("��˽�",900);
    Person p4("ɳɮ",800);

//    ���
    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);

    cout<<"���еĴ�СΪ��"<<q.size()<<endl;
    
//    ֻҪ���в�Ϊ�գ��Ͳ鿴��ͷ���鿴��β
    while (!q.empty()){//��Ϊ��

//        �鿴��ͷԪ��
        cout<<"��ͷԪ�ء���������"<<q.front().m_Name
            <<"���䣺"<<q.front().m_Age<<endl;

//        �鿴��βԪ��
        cout<<"��βԪ�ء���������"<<q.back().m_Name
            <<"���䣺"<<q.back().m_Age<<endl;

//        ����
        q.pop();
        cout<<endl;
    }
    cout<<"���еĴ�СΪ��"<<q.size()<<endl;

}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
