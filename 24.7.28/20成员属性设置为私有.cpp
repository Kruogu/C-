//
// Created by tianya on 2024/7/29.
//
#include "iostream"
using namespace std;

//��Ա��������Ϊ˽��
//1.�����Լ����ƶ�дȨ��
//2.����д���Լ��������Ч��

//����
class Person{
public:
        //��������
        void setName(string name){
            m_Name = name;
        }
//        ��ȡ����
        string getName(){
            return m_Name;
        }
//        ��������  (0~150)
        void setAge(int age){
            if(age>=0&&age<=150)
                m_Age = age;
            else
                cout<<"��������"<<age<<"���󣬸�ֵʧ�ܣ�"<<endl;
                return;
        }
//        ��ȡ����  ֻ��
        int getAge(){
            return m_Age;
        }
//        ����ż��  ֻд
        void setIdol(string idol){
            m_Idol = idol;
        }
//    ��ȡż��  û������Ͷ�������
        string getIdol(){
            return m_Idol;
        }
private:
    string  m_Name; //���� �ɶ���д

    int m_Age=18;  //����  ֻ�� Ҳ����д�����������0��150֮�䣩

    string m_Idol; //ż��  ֻд
};
int main(){
    Person p;
    //��������
//    p.m_Name = "����";  //��������ֱ�ӻ�ȡ

    p.setName("����");
//    ��ȡ����
    cout<<"������"<<p.getName()<<endl;


    //��������
    p.setAge(160);
//    p.m_Age = 20;
//    ��ȡ����  û����  ֻ��
    cout<<"���䣺"<<p.getAge()<<endl;

//    ż������
    p.setIdol("С��");
//    ��ȡż��
    cout<<"ż��"<<p.getIdol()<< endl;//ֻд״̬�����ʲ���


    cout<<"Hello World111"<<endl;
    return 0;
}
