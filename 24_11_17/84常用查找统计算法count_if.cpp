//
// Created by tianya on 2024/11/21.
//
//

#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"
//5.2.6���ò���  ͳ���㷨 count_if

//�� count_if(iterator beg, iterator end,_Pred);
//������ͳ��Ԫ�س��ִ���
//beg��ʼ������
//end���������
//_Pred ν��



//1��ͳ��������������
//ν��
class Greater20{
public:
    bool operator()(int val){
        return val>20;
    }
};
void test01(){
    vector<int>v;

    v.push_back(10);
    v.push_back(40);
    v.push_back(30);
    v.push_back(40);
    v.push_back(20);
    v.push_back(40);

//    �����ж��ٴ���20����
    int num = count_if(v.begin(),v.end(),Greater20());
    cout<<"����20��Ԫ�ظ���Ϊ��"<<num<<endl;//����20��Ԫ�ظ���Ϊ��4

//    ��lambda���ʽʵ�ֿ��ܸ���
}


//2��ͳ���Զ�����������
class Person{
public:
    //����ʵ��
    Person(string name,int age){
        this->m_Name = name;
        this->m_Age = age;
    }
//    ����ʵ�ֺͶ������Ƚ�
    bool operator()(const Person &p){
        return p.m_Age> this->m_Age;
    }
    string m_Name;
    int m_Age;
};

//ν��
class AgeGreater20{
public:
    //����ʵ�ֺ��������Ƚϣ���κ�Person�������Ƚϣ������ط���Person����ʵ��
    bool operator()(const Person &p){
        return p.m_Age>25;
    }
};

void test02(){
    vector<Person>v;

    //    ׼������
    Person p1("����",35);
    Person p2("�ܲ�",45);
    Person p3("����",25);
    Person p4("�ŷ�",30);
    Person p5("����",35);

//    ����Ա���뵽������
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    Person p("�����",30);

    int num1 = count_if(v.begin(),v.end(),p);
    cout<<"����������������Ա����Ϊ��"<<num1<<endl;

    int num2 = count_if(v.begin(),v.end(),AgeGreater20());
    cout<<"��25���������Ա����Ϊ��"<<num2<<endl;

}
int main(){
    test01();
    test02();
    cout<<"HelloWorld"<<endl;
    return 0;
}
