//
// Created by tianya on 2024/11/20.
//
#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"
#include "functional"//�ڽ���������ͷ�ļ�

//5.2.2 ���ò����㷨find_if

//��find_if(iterator beg,iterator end,_Pred);
//��ֵ����Ԫ�أ��ҵ�����ָ��λ��ѡ�������Ҳ������ؽ���������λ��
//beg��ʼ������
//end����������
//_Pred ��������ν�ʣ�����bool���͵ķº�����

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

class GreaterFive{
public:
    bool operator()(int val){
        return val>5;
    }
};

//ν��
class Greater20{
public:
    bool operator()(Person &p){
        return p.m_Age>20;
    }
};

//����������������
void test01(){
    vector<int>v;

    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }

    //���� ������ �Ƿ��� 5 ���Ԫ��
    vector<int>::iterator it = find_if(v.begin(),v.end(),GreaterFive());

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

//    ���������20����
//    find����û�����������  ���ַ��������ԱȽ�
    vector<Person>::iterator it = find_if(v.begin(),v.end(),Greater20());
    if(it==v.end()){
        cout<<"û���ҵ���"<<endl;
    } else{
        cout<<"�ҵ�Ԫ�� ������"<<it->m_Name
            <<" ���䣺"<<(*it).m_Age<<endl;
    }
}
int main(){
    test01();
    test02();
    cout<<"HelloWorld"<<endl;
    return 0;
}
