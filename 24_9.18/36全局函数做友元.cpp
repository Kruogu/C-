//
// Created by tianya on 2024/9/18.
//
#include "iostream"
#include "string"
using namespace std;

//��������  ������
class Building{
//    goodGayȫ�ֺ�����Building�����ѣ����Է���Building��˽�г�Ա
    friend void goodGay(Building &building);
public:
    Building(){
        m_SittingRoom = "����";
        m_BedRoom = "����";
    }
public:
    string m_SittingRoom;//����
private:
    string m_BedRoom;//����
};

//ȫ�ֺ���
void goodGay(Building &building){
//    ���ʹ���
    cout<<"�û���ȫ�ֺ��� ���ڷ��ʣ�"<<building.m_SittingRoom<<endl;
//    ����˽��
    cout<<"�û���ȫ�ֺ��� ���ڷ��ʣ�"<<building.m_BedRoom<<endl;
}

void test01(){
    Building building;
    goodGay(building);
}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
