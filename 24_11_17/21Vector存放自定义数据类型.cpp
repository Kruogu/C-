//
// Created by tianya on 2024/11/17.
//
#include "iostream"
using namespace std;
#include "vector"//������ͷ�ļ�
#include "algorithm"//��׼�㷨ͷ�ļ�

//2.5.2 Vector����Զ�����������
//δ��ʵ��ȫ�ֺ��� �� for_each

class Person{
public:
    //����ʵ��
    Person(string name,int age){
        this->m_Name = name;
        this->m_Age = age;
    }

    void showPerson();
//    void showPerson(){
//        cout<<"������"<< this->m_Name<< endl;
//        cout<<"���䣺"<< this->m_Age<< endl;
//    }
    string m_Name;
    int m_Age;
};

void Person::showPerson(){
    cout<<"������"<< this->m_Name
        <<"���䣺"<< this->m_Age<< endl;
}

void test(){
    Person p1("aaa",10);
    p1.showPerson();
}

void test01(){
    vector<Person>v;

    Person p1("aaa",10);
    Person p2("bbb",20);
    Person p3("ccc",30);
    Person p4("ddd",40);
    Person p5("eee",50);

//    �������в�������  β�巨
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

//    ���������е�����
    for(vector<Person>::iterator it=v.begin();it!=v.end();it++){
//        cout<<"������"<< (*it).m_Name
//            <<" ���䣺"<< (*it).m_Age<< endl;//it������ָ��
        cout<<"������"<< it->m_Name
            <<" ���䣺"<< it->m_Age<< endl;
    }
//    for_each(v.begin(),v.end(),Person::showPerson);
//    for_each(v.begin(),v.end(),showPerson);
}

//����Զ������͵�ָ��
void test02(){
    vector<Person*>v;//����ָ��

    Person p1("aaa",10);
    Person p2("bbb",20);
    Person p3("ccc",30);
    Person p4("ddd",40);
    Person p5("eee",50);

//    �������в�������  β�巨
    v.push_back(&p1);//ȡֵ��
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);

    //    ���������е�����
    for(vector<Person *>::iterator it=v.begin();it!=v.end();it++){
        cout<<"2������"<< (*it)->m_Name
            <<" 2���䣺"<< (*it)->m_Age<< endl;//ָ���ָ��
    }
}
int main(){
//    test01();
    test02();
//    test();
    cout<<"HelloWorld"<<endl;
    return 0;
}
