//
// Created by tianya on 2024/11/1.
//
#include "iostream"
using namespace std;
//��̬������-������Ʒ
//  ������Ʒ�Ĵ�������Ϊ����ˮ������-���뱭��-���븨��
//  ���ö�̬����ʵ�ֱ��������ṩ����������Ʒ���࣬�ṩ�����������ȺͲ�Ҷ

//coffee ����   tea  ��
class AbstractDrinking{ //������Ʒ
public:
//    virtual void zs() = 0;//1����ˮ  boil
    virtual void cp() = 0;//2�����ݿ���  ��Ҷ  brew
//    virtual void db() = 0;//3�����뱭��  pour In Cup
    virtual void jf() = 0;//4�����Ǻ�ţ��  ������  Put Something ��һЩ

//    ������Ʒ
    void makeDrink(){
        cp();
        jf();
    }
};

//��������
class Coffee:public AbstractDrinking{
    void cp(){
        cout<<"1����ˮ"<<endl;
        cout<<"2�����ݿ���"<<endl;

    }
    void jf(){
        cout<<"3�����뱭��"<<endl;
        cout<<"2�����Ǻ�ţ��"<<endl;
    }
};

//������
class Tea:public AbstractDrinking{
    void cp(){
        cout<<"1����ˮ"<<endl;
        cout<<"2�����ݲ�Ҷ"<<endl;

    }
    void jf(){
        cout<<"3�����뱭��"<<endl;
        cout<<"2��������"<<endl;
    }
};

//��������
void doWork1(AbstractDrinking &abs){
    abs.makeDrink();
//    delete abs;
}
//����һ��д��
void doWork2(AbstractDrinking * abs){
    abs->makeDrink();
    delete abs;//�ͷſռ�
}

//��ָ̬��
void test01(){
    AbstractDrinking *AbstractDrinking = new Coffee;
    AbstractDrinking->cp();
    AbstractDrinking->jf();
    delete AbstractDrinking;

    cout<<"��������������������"<<endl;

    AbstractDrinking = new Tea;
    AbstractDrinking->makeDrink();//��д��
    delete AbstractDrinking;
}

//��̬����
void test02(){
    Coffee c;//����
    doWork1(c);

    cout<<"��������������������"<<endl;

//    Tea t;//��  Ҳ���Բ�д
    doWork2(new Tea);//����δ֪ԭ��  ������ֱ��new  ��ʵҲ��ָ��д��
//              ���ҵ�����ԭ��doWork2������ָ��д�����ò���ֱ�Ӵ�������
}
int main(){
//    test01();
    test02();
    cout<<"HelloWorld"<<endl;
    return 0;
}
