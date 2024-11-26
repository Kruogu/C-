//
// Created by tianya on 2024/11/1.
//
#include "iostream"
using namespace std;

//��̬����һ - ��������

//�ֱ�������ͨ��д���Ͷ�̬����ʵ�ּ�����
//��ͨд��
class Calculator{
public:
    int getResult(string oper){//��ȡ������
        if(oper == "+"){
            return m_Num1+m_Num2;
        }
        else if(oper == "-"){
            return m_Num1-m_Num2;
        }
        else if(oper == "*"){
            return m_Num1*m_Num2;
        }
        //�������չ�µĹ��ܣ������޸�Դ��  ����
        //����ʵ������ �ᳫ ����ԭ��
        //����ԭ�򣺶���չ���п��ţ����޸Ľ��йر�

    }
    int m_Num1;//������1
    int m_Num2;//������2
};


//���ö�̬ʵ�ּ�����
//��̬�ô���
//    1.��֯�ṹ����
//    2.�ɶ���ǿ
//    3.����ǰ�ںͺ�����չ�Լ�ά���Ը�
//ʵ�ּ����������� ����
class AbstractCalculator{
public:
    virtual int getResult(){ //д���麯��
        return 0;
    }
    int m_Num1;
    int m_Num2;
};

//�ӷ���������
class AddCalcultor:public AbstractCalculator{
public:
//    int getResult(string oper){//��ȡ������
//        if(oper == "+"){
//            return m_Num1+m_Num2;
//        }
//    }
    int getResult(){//��ȡ������
            return m_Num1+m_Num2;
        cout<<m_Num1<<"+"<<m_Num1<<"="<<m_Num1+m_Num2<<endl;
    }
};

//������������  subtraction
class SubCalcultor:public AbstractCalculator{
public:
    int getResult(){//��ȡ������
        return m_Num1-m_Num2;
        cout<<m_Num1<<"-"<<m_Num1<<"="<<m_Num1-m_Num2<<endl;
    }
};
//�˷���������  multiplication
class MulCalcultor:public AbstractCalculator{
public:
    int getResult(){//��ȡ������
        return m_Num1*m_Num2;
        cout<<m_Num1<<"*"<<m_Num1<<"="<<m_Num1*m_Num2<<endl;
    }
};
void test01(){
    //��������������
    Calculator c;
    c.m_Num1 = 10;
    c.m_Num2 = 10;
    cout<<c.m_Num1<<"+"<<c.m_Num2<<"="<<c.getResult("+")<<endl;
    cout<<c.m_Num1<<"-"<<c.m_Num2<<"="<<c.getResult("-")<<endl;
    cout<<c.m_Num1<<"*"<<c.m_Num2<<"="<<c.getResult("*")<<endl;
}

void dogetResult(AbstractCalculator & abstractCalculator){
    abstractCalculator.getResult();
}
void test02(){
//    ��̬ʹ������
//      ����ָ���������ָ���������

//    �ӷ�����
    AbstractCalculator *abc = new AddCalcultor;//��������
    abc->m_Num1 = 20;
    abc->m_Num2 = 20;
    cout<<abc->m_Num1<<"+"<<abc->m_Num1<<"="<<abc->getResult()<<endl;
//    �����ǵ�����
    delete abc;

//    ��������
    abc = new SubCalcultor;
    abc->m_Num1 = 20;
    abc->m_Num2 = 20;
    cout<<abc->m_Num1<<"-"<<abc->m_Num1<<"="<<abc->getResult()<<endl;
    delete abc;

    //    �˷�����
    abc = new MulCalcultor;
    abc->m_Num1 = 20;
    abc->m_Num2 = 20;
    cout<<abc->m_Num1<<"*"<<abc->m_Num1<<"="<<abc->getResult()<<endl;
    delete abc;
}

//    ����
void test03(){
    AddCalcultor a;
    a.m_Num1 = 30;
    a.m_Num2 = 30;
    dogetResult(a);

    SubCalcultor s;
    s.m_Num1 = 30;
    s.m_Num2 = 30;
    dogetResult(s);

    MulCalcultor m;
    m.m_Num1 = 30;
    m.m_Num2 = 30;
    dogetResult(m);
}
int main(){
//    test01();//����д��
//    test02();//ָ��  ��̬
    test03();//����  ��̬
    cout<<"HelloWorld"<<endl;
    return 0;
}
