//
// Created by tianya on 2024/11/1.
//
#include "iostream"
using namespace std;
//�������ʹ�������
class Animal{
public:
    Animal(){
        cout<<" Animal�Ĺ��캯������"<<endl;
    }

//    �������������Խ������ָ���ͷ��������ʱ���ɾ�������
//    ~Animal(){ // Ϊ�˱����ڴ�й¶������ĳ��������ͻ����ͷ������е�����
    virtual ~Animal(){
        cout<<" Animal����������������"<<endl;
    }

//    ��������  ��Ҫ����Ҳ��Ҫʵ��   �������������ֻ���� һ��
//    ���˴�������֮�������Ҳ���ڳ����࣬�޷�ʵ��������
//    virtual ~Animal() = 0;//����Ϊ�գ�Ҳ��Ҫ������д�����ڲ�ʵ��

//    ���麯��
    virtual void speak() = 0;
};

//Animal::~Animal() {
//    cout<<" Animal�Ĵ���������������"<<endl;
//}

class Cat:public Animal{
public:
    Cat(string name){
        cout<<"Cat�Ĺ��캯������"<<endl;
        m_Name = new string(name);
    }
    virtual void speak() {
        cout<<*m_Name<<"Сè��˵��"<<endl;
    }
    ~Cat(){//�ͷ��ڴ�
        if(m_Name != NULL){
            cout<<"Cat��������������"<<endl;
            delete m_Name;
            m_Name = NULL;
        }
    }
    string * m_Name;
};

void test01(){
    Animal *animal = new Cat("Tom");
    animal->speak();
//    ����ָ��������ʱ�򲻻��������������������������������ж������ԣ������ڴ�й©
    delete animal;
}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
