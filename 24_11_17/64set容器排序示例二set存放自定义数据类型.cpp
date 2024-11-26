//
// Created by tianya on 2024/22/19.
//
#include "iostream"
using namespace std;
#include "set"
//3.8.8set��������

//ʾ��һ set��� �Զ��� ��������

class Person{
public:
    //����ʵ��
    Person(string name,int age){
        this->m_Name = name;
        this->m_Age = age;
    }
//private:
    string m_Name;
    int m_Age;
};

class comparePerson{
public:
//    ע�⣬��ΪC++11�����Ե�Ե�ʣ�������Ҫ�ڲ����б�����const
    bool operator()(const Person &p1,const Person &p2)const{//��һ��С���Ŵ���Ҫ���صķ��ţ��ڶ���С���Ŵ�������б�
//        �����ǽ���  Ĭ��������
        return p1.m_Age>p2.m_Age;
    }
};

void test01(){
//    �Զ����������� ����ָ���������
//    set<Person>s1;//��ֱ�ӱ���
    set<Person,comparePerson>s1;//�º���ָ������

    //    ׼������
    Person p1("����",35);
    Person p2("�ܲ�",45);
    Person p3("��Ȩ",40);
    Person p4("����",25);
    Person p5("�ŷ�",35);
    Person p6("����",35);
//    s1.emplace("����",35);//c++11�����ԣ�Ŀǰ������

    s1.insert(p1);
    s1.insert(p2);
    s1.insert(p3);
    s1.insert(p4);
    s1.insert(p5);
    s1.insert(p6);


//    �Զ��ź������Ѿ�����ӡ���һ��  �ظ������Զ�Ĩ��
    for(set<Person,comparePerson>:: iterator it=s1.begin();it!=s1.end();it++){//comparePerson���Լ���
//    for(set<Person>:: iterator it=s1.begin();it!=s1.end();it++){
        cout<<"������"<<it->m_Name<<" "
//        cout<<"������"<<(*it).m_Name<<" "
            <<" ���䣺"<<(*it).m_Age<<endl;
    }
    cout<<endl;

}

int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
