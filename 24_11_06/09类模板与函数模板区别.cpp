//
// Created by tianya on 2024/11/8.
//
#include "iostream"
using namespace std;
//1.��ģ��û���Զ������Ƶ���ʹ�÷�ʽ

//1.3.2��ģ���뺯��ģ������
template<class NameType,class AgeType>//�������� ģ��  test01  ����

//template<class NameType,class AgeType=int>//����Ĭ��ָ������ test02  ����
//template<class NameType=string,class AgeType>//�����ᱨ�� test02    ������
//template<class NameType=string,class AgeType>//�����ᱨ�� test02    ������
//template<class NameType=string,class AgeType=int>//����Ĭ��ָ������ test02  ����

//template<class NameType,class AgeType,class IdType=string>//test02  ������������ͣ����һ��ָ��string  ������
//template<class NameType,class AgeType=int,class IdType>//test02  ������������ͣ��м�һ��ָ��int  ������
//template<class NameType,class AgeType,class IdType=int>//test02  ������������ͣ����һ��ָ��int  ������
//template<class NameType,class AgeType=int,class IdType>//test02  ������������ͣ��м�һ��ָ��int  ������
//template<class NameType,class AgeType,class IdType=int>//test02  ������������ͣ����һ��ָ��int  ������
//template<class NameType,class AgeType=int,class IdType=int>//test02  ������������ͣ�������ָ��int ����
//template<class NameType,class AgeType=string,class IdType=string>//test02  ������������ͣ�������ָ��string ����
//template<class NameType=string,class AgeType=string,class IdType=string>//test02  ������������ͣ� ����
//Ĭ��ָ������ֻ��ָ�����棬���ָ��ǰ���ͻ��ᱨ��
class Person{
public:
    Person(NameType name,AgeType age){
//    Person(NameType name,AgeType age,IdType id){
        this->m_Name = name;
        this->m_Age = age;
//        this->m_id = id;
    }

    void showPerson()//��ӡ���һ��
    {
        cout<<"name��"<<this->m_Name<< endl;
        cout<<"age��"<<this->m_Age<< endl;
//        cout<<"id��"<<this->m_id<< endl;
    }
    //����
    NameType m_Name;
    //����
    AgeType m_Age;
    //id
//    IdType m_id;

};

//void test01(){
////    Person p("�����",1000);//���󣬲����Զ������Ƶ�
//    Person<string,int> p("�����",1000);//��ȷ��ֻ������ʾָ������
//    p.showPerson();
//}

//2.��ģ����ģ������б��п�����Ĭ�ϲ���
void test02(){
//    Person<string,int> p("��˽�",999);//����
//    Person<string> p("��˽�",999);//����ڶ���ָ��int  ����
//    Person<string> p("��˽�","����");//���ָ����һ�� string  ������
    Person<string,string> p("��˽�","����");//���������ָ��string  ����
//    Person<int> p("��˽�",999);//�����һ��ָ��string   ������
//    Person<> p("��˽�",999);//��������ֱ�ָ����string��int  ����

//    Person<int> p(11,1,"��");//��� ��� һ��ָ����string  ������
//    Person<string> p("��˽�",1,"��");//��� �м� һ��ָ����int  ������
//    Person<string> p("��˽�","��",1);//��� ��� һ��ָ����int  ������
//    Person<string> p("��˽�",18,1);//��� �м� һ��ָ����int  ������
//    Person<string> p("��˽�",18,1);//��� ��� һ��ָ����int  ������
//    Person<string> p("��˽�",18,1);//��� ������ ��ָ���� int  ����
//    Person<string> p("��˽�","��","��");//��� ������ ��ָ���� string  ����
//    Person<> p("��˽�","��","��");//��� ������ ָ����string  ����

//    �����������Է��֣����ָֻ����һ�����ͣ�����ָ����һ����ģ��������ͣ������������ ��ǰ����Ĭ�ϣ����򱨴�

    p.showPerson();
}

int main(){
//    test01();
    test02();
    cout<<"HelloWorld"<<endl;
    return 0;
}
