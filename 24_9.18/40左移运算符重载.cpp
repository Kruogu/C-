//
// Created by tianya on 2024/10/3.
//
#include "iostream"
using namespace std;

//�������������
class Person{
    friend ostream &operator<<(ostream &cout,Person &p);//��Ԫ
public:
    Person(int a,int b){
        m_A = a;
        m_B = b;
    }
//    ���ó�Ա�������� ��������� p.operator<<(p)
//                           p.operator<<(cout) �򻯰汾 p<<cout
//    ͨ���������ó�Ա��������<<���������Ϊ�޷�ʵ��cout�����
//    void operator<<(Person &p){
//    void operator<<(cout){
//
//    }
private://�����˽��ǰ���Ҫ����friend��Ԫ
    int m_A;
    int m_B;
};

//ֻ������ȫ�ֺ����������������
//void operator<<(cout,p)//���� operator<<(cout,p) �� cout << p
//void operator<<(ostream &cout,Person &p)
ostream &operator<<(ostream &cout,Person &p)
{
    cout<<"m_A = "<<p.m_A<<" m_B = "<<p.m_B<<endl;
    return cout;
}

//ostream &operator<<(ostream &out,Person &p)// cout �ĳ� out Ҳ����
//{
//    out<<"m_A = "<<p.m_A<<" m_B = "<<p.m_B<<endl;
//    return out;
//}
void test01(){
//    Person p;
//    p.m_A = 10;
//    p.m_B = 10;

    Person p(10,10);


//    cout<<p.m_A<<endl;//����ֱ�����p
//    cout<<p<<endl;
//    cout<<p;//���� endl �ͱ���
    cout<<p<<endl;

}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
