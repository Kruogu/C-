//
// Created by tianya on 2024/11/20.
//
#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"
#include "functional"//�ڽ���������ͷ�ļ�

//5.2.1���ò����㷨find

//�� find(iterator beg, iterator end, value);
//��ֵ����Ԫ�أ��ҵ�����ָ��λ�õ��������Ҳ������ؽ���������λ��
//beg��ʼ������
//end����������
//value���ҵ�Ԫ��

class Person{
public:
    Person(string name,int age){
        this->m_Name = name;
        this->m_Age = age;
    }
//    ���� == ���� �õײ�find֪����ζԱ�person��������
    bool operator==(const Person &p){
        if(this->m_Name==p.m_Name && this->m_Age== this->m_Age){
            return true;
        } else{
            return false;
        }

    }
    string m_Name;//����
    int m_Age;//����
};

//����������������

void test01(){
    vector<int>v;

    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }

    //���� ������ �Ƿ��� 5 ���Ԫ��
    vector<int>::iterator it = find(v.begin(),v.end(),5);
//    vector<int>::iterator it = find(v.begin(),v.end(),50);
    if(it==v.end()){
        cout<<"û���ҵ���"<<endl;
    } else{
        cout<<"�ҵ���"<<*it<<endl;
    }
}

//�����Զ�����������
void test02(){
    vector<Person>v;
//    ��������
    Person p1("aaa",10);
    Person p2("bbb",20);
    Person p3("ccc",30);
    Person p4("ddd",40);

//    ���뵽������
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    Person pp("bbb",20);

//    find����û�����������  ���ַ��������ԱȽ�
//    vector<Person>::iterator it = find(v.begin(),v.end(),p2);
    vector<Person>::iterator it = find(v.begin(),v.end(),pp);

    if(it==v.end()){
        cout<<"û���ҵ���"<<endl;
    } else{
        cout<<"�ҵ�Ԫ�� ������"<<it->m_Name
            <<"���䣺"<<(*it).m_Age<<endl;
    }
}
int main(){
    test01();
    test02();
    cout<<"HelloWorld"<<endl;
    return 0;
}
