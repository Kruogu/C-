//
// Created by tianya on 2024/10/31.
//



#include "iostream"
using namespace std;

//��̬

//������
class Animal{
public:
//    void speak(){
    virtual void speak(){ //�麯��
        cout<<"������˵��"<<endl;
    }
};

// ������ è��
class Cat:public Animal{
public:
    //��д  ��������ֵ����  ������  �����б�  ��ȫ��ͬ  �����ز�һ��
//    void speak(){
    virtual void speak(){//��������virtual�ǿ�д�ɲ�д�ģ�����
        cout<<"Сè��˵��"<<endl;
    }
};

// ������ ����
class Dog:public Animal{
public:
    void speak(){
        cout<<"С����˵��"<<endl;
    }
};

//ִ��˵���ĺ���
//��ַ���  �ڱ���׶ξ�ȷ��������ַ
//�����ִ����è˵��������������ĵ�ַ�Ͳ�����ǰ�󶨣���Ҫ�����н׶ν��а󶨣���ַ���

//��̬��̬��������
// 1���м̳й�ϵ
// 2��������д������麯��

//��̬��̬ʹ��
// �����ָ��������� ָ�� �������
void doSpeak(Animal &animal){  //Animal &animal = cat;
    animal.speak();//�ĳ���̳�֮�󣬾��Ƕ�̬����������è����è�������ǹ�
}

void test01(){
    Cat cat;//����һֻè
//    cat.speak(); // ����Ҳ��  Сè��˵��
    doSpeak(cat);//��è����ȥ  ������˵��  �������ý����������
//                  ������̳�֮��  Сè��˵��
    Dog dog;
    doSpeak(dog);//С����˵��

}

int main(){
//    doSpeak();
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
