//
// Created by tianya on 2024/10/25.
//

#include "iostream"
using namespace std;

//�̳��й��������˳��

class Base{
public:
    Base(){
        cout<<"Base�Ĺ��캯��"<<endl;
    }
    ~Base(){
        cout<<"Base����������"<<endl;
    }
};

class Son:public Base{
public:
    Son(){
        cout<<"Son�Ĺ��캯��"<<endl;
    }
    ~Son(){
        cout<<"Son����������"<<endl;
    }
};

void test01(){
//    Base b;//���� ��������

    Son s;//����  ��������  ���и������ж��ӣ��׷����ͺڷ���
    //�̳��еĹ��������˳�����£�
    //�ȹ��츸�࣬�ٹ������࣬������˳���빹���˳���෴
//    �ܽ᣺�̳����ȵ��ø��๹�캯�����ٵ������๹�캯��������˳���빹���෴
}

int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
