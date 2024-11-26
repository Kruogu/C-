//
// Created by tianya on 2024/11/1.
//
//��53����

//��vs����
//E:
//cd E:\0Work\0workspace\24_10.31
//dir
//cl /d1 reportSingleClassLayoutSheep���� 54tab��
//cl /d1 reportSingleClassLayoutSheepAnimal 54��̬��ԭ������.cpp


#include "iostream"
using namespace std;

//��̬��ԭ������

//    vfptr - �麯������ָ��  ָ���
//        v   - virtual
//        f   - function
//        ptr - pointer

//    vftable - �麯���� ���ڼ�¼�麯���ĵ�ַ
//        v     - virtual
//        f     - function
//        table - table
//        &Animal::speak

//��������д������麯��
//        �����е��麯����  �ڲ�  ���滻��  �����������ַ
//        &Cat::speak   ����һ���̳У���speak������ȫ���Ǹ����speak����
//        �������ָ���������ָ���������ʱ�򣬷�����̬
//            Animal & animal = cat:
//            animal.speak()

//��̬�Ķ���
//��������ڲ������˽ṹ�ĸı䣬����һ���麯����ָ�룬ָ���麯����
//�麯�����ڲ�д���麯���ĺ�����ڵ�ַ����������д���麯����ʱ��
//��������麯�����к����滻�����滻������ĺ���
//�����ø�������ָ������Ķ���ʱ�������ù���speak�ӿ�ʱ��
// �ͻ�����������Һ���ȷֵ����ڵ�ַ��è����è�������ǹ�

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
    void speak(){
//    virtual void speak(){//��������virtual�ǿ�д�ɲ�д�ģ�����
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

void test02(){
    //����virtual������ʾ1
    //���Ͼ�����ʾ8  ��ѧ��Ƶ��ʾ 4  �Ǹ�ָ��
    cout<<"sizeof Animal = "<<sizeof(Animal)<<endl;
}

int main(){
//    test01();
    test02();
    cout<<"HelloWorld"<<endl;
    return 0;
}
