//
// Created by tianya on 2024/9/18.
//
#include "iostream"
#include "string"
using namespace std;

//������Ԫ
class Building;//�������

class GoodGay{
public:

    GoodGay();
    void visit();//�ιۺ��� ����Building�е�����
    Building * building;
};

class Building{
//    GoodGay���Ǳ���ĺ����ѣ����Է��ʱ�����˽�еĳ�Ա
    friend class GoodGay;//����classҲ������������
public:
    Building();
public:
    string m_SittingRoom;//����
private:
    string m_BedRoom;//����
};

//����д��Ա����
Building::Building(){
    m_SittingRoom = "����";
    m_BedRoom = "����";
}
GoodGay::GoodGay() {
//    �������������
    building = new Building;//����������һ������
}
void GoodGay::visit() {
    cout<<"�û��������ڷ��ʣ�"<<building->m_SittingRoom<<endl;
    cout<<"�û��������ڷ��ʣ�"<<building->m_BedRoom<<endl;
}

void test01(){
    GoodGay gg;
    gg.visit();
}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
