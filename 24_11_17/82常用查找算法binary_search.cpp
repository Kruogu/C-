//
// Created by tianya on 2024/11/20.
//
#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"
#include "functional"//�ڽ���������ͷ�ļ�

//5.2.4 ���ò����㷨binary_search

//��bool binary_search(iterator beg,iterator end,value);
//����ָ����Ԫ�أ��鵽����true����false

//ע�⣺�����������в�����

//beg��ʼ�����
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

//    �۲���Щͬʱ �ظ�������
    for (int i = 0; i < 10; ++i) {
//        int ret = rand()%10;//1 7 4 0 9 4 8 8 2 4
//        v.push_back(ret);//�������о��Ҳ�����
//        v.push_back(rand()%10);//1 7 4 0 9 4 8 8 2 4
        v.push_back(i);//����ſ����ҵ�
    }

    //����
    for(vector<int>::iterator it = v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

//    �����������Ƿ���9Ԫ��   ������������У����δ֪��
//    ע�⣺���������� ���� ������     ���ֲ���
   bool ret = binary_search(v.begin(),v.end(),9);
    if(ret){
        cout<<"�ҵ���Ԫ�أ�"<<int(ret)<<endl;//�ҵ�Ԫ�أ�9
    } else{
        cout<<"δ�ҵ�Ԫ�أ�"<<int(ret)<<endl;
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
//    test02();
    cout<<"HelloWorld"<<endl;
    return 0;
}
