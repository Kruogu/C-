//
// Created by tianya on 2024/11/20.
//
#include "iostream"
using namespace std;
#include "map"

//3.9.6map���� �Զ���������������

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

//���������
class MyCompare{
public:
//    Person�ں��õ�һ�֣�Person��ǰ�õڶ���
//    bool operator()(int v1,int v2)const{//��һ��С���Ŵ���Ҫ���صķ��ţ��ڶ���С���Ŵ�������б�
////        �����ǽ���  Ĭ��������
//        return v1>v2;
//    }

    bool operator()(const Person &p1,const Person &p2)const{
    //        ����
        return p1.m_Age>p2.m_Age;
    }
};

//��һ���������  ��������keyֵ�Ӵ�С�������򣬴�С����������Ҫ����Ҳ����
////void printMap(map<int,Person> &m){
//void printMap(map<int,Person,MyCompare> &m){
////    ����ͽ���һ��
////    for(map<int,Person>::iterator it = m.begin();it!=m.end();it++){
//    for(map<int,Person,MyCompare>::iterator it = m.begin();it!=m.end();it++){
//        cout<<"key = "<<(*it).first
//            <<"  value������"<<it->second.m_Name
//            <<"  value���䣺"<<it->second.m_Age<<endl;
//    }
//    cout<<endl;
//}

//�ڶ����������  ���ֿ�������
//void printMap(map<Person,int> &m){
void printMap(map<Person,int,MyCompare> &m){
//    ����ͽ���һ��
//    for(map<Person,int>::iterator it = m.begin();it!=m.end();it++){
    for(map<Person,int,MyCompare>::iterator it = m.begin();it!=m.end();it++){
        cout<<"key������"<<(*it).first.m_Name
            <<"  key���䣺"<<it->first.m_Age
            <<"  value = "<<it->second<<endl;
    }
    cout<<endl;
}

void test01(){

//    ��������Զ����������ͣ������ʵ��int���ͣ�value��ʲô���Ͷ���Ӱ��
//    map<int,Person>m1;//��������keyֵ��С�����������򣬵�������valueֵ��������
//    map<int,Person,MyCompare>m1;//��������keyֵ�Ӵ�С�������򣬣���������valueֵ��������

//    �Զ����������� ����ָ���������
//    map<Person,int>m1;//ֱ�ӱ��� ��Ϊû��ָ������������MyCompare���� < �ﵽ��С��������Ч��
    map<Person,int,MyCompare>m1;//����  ����������keyֵ�е�������дӴ�С����

    //    ׼������
    Person p1("����",35);
    Person p2("�ܲ�",45);
    Person p3("��Ȩ",40);
    Person p4("����",25);
    Person p5("�ŷ�",30);
    Person p6("����",35);

//    �������� <int,Person>
    m1.insert(make_pair(p1,1));//insert���� ����ΪMyCompare�е���������ش��ˣ��õڶ��ֹ���ͺ���
    m1.insert(make_pair(p2,2));
    m1.insert(make_pair(p3,3));
    m1.insert(make_pair(p4,4));
    m1.insert(make_pair(p5,5));
    m1.insert(make_pair(p6,6));

//    �������� <int,Person,MyCompare>
//    m1.insert(make_pair(1,p1));
//    m1.insert(make_pair(3,p3));
//    m1.insert(make_pair(2,p2));
//    m1.insert(make_pair(3,p3));//���в岻��ȥ��count��1
//    m1.insert(make_pair(4,p4));
//    m1.insert(make_pair(5,p5));
//    m1.insert(pair<int,Person>(6,p6));

    printMap(m1);

}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}

