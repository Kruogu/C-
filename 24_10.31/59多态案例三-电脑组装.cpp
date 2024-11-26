//
// Created by tianya on 2024/11/2.
//
#include "iostream"
using namespace std;
//��̬������-������װ


//�����ÿ���������
class CPU{//����CPU��
public:
//    ������㺯��
    virtual void calculate() = 0;
};
class VideoCard{//������  �Կ�
public:
//    ������ʾ����
    virtual void display() = 0;//��ʾ
};
class Memory{//������  �ڴ�
public:
//    ����洢����
    virtual void storage() = 0;//�洢
};

//������
class Computer{
public:
    Computer(CPU *cpu,VideoCard *vc,Memory *mem){
        m_cpu = cpu;
        m_vc = vc;
        m_mem = mem;
    }

    //�ṩ�����ĺ���
    void work(){
        //����ÿ����������Ľӿ�
        m_cpu->calculate();
        m_vc->display();
        m_mem->storage();
    }

    //�ṩ��������
    ~Computer(){
        //�ͷ�CPU���
        if(m_cpu!=NULL){
            delete m_cpu;
            m_cpu = NULL;
        }
        //�ͷ��Կ����
        if(m_vc!=NULL){
            delete m_vc;
            m_vc = NULL;
        }
        //�ͷ��ڴ������
        if(m_mem!=NULL){
            delete m_mem;
            m_mem = NULL;
        }
    }

//    ���캯���д����������ָ��
private:
    CPU *m_cpu;//CPU�����ָ��
    VideoCard *m_vc;//�Կ������ָ��
    Memory *m_mem;//�ڴ������ָ��
};

//������������ Inter
class InterCpu:public CPU{
public:
    void calculate(){
        cout<<"Inter��cpu��ʼ������"<<endl;
    }
};
class InterVideoCard:public VideoCard{
public:
    void display(){
        cout<<"Inter���Կ���ʼ��ʾ��"<<endl;
    }
};
class InterMemory:public Memory{
public:
    void storage(){
        cout<<"Inter���ڴ濪ʼ�洢��"<<endl;
    }
};

//Lenovo ����  Ҳ��Ҫ�ṩ�������
class LenovoCpu:public CPU{
public:
    void calculate(){
        cout<<"Lenovo��cpu��ʼ������"<<endl;
    }
};
class LenovoVideoCard:public VideoCard{
public:
    void display(){
        cout<<"Lenovo���Կ���ʼ��ʾ��"<<endl;
    }
};
class LenovoMemory:public Memory{
public:
    void storage(){
        cout<<"Lenovo���ڴ�����ʼ�洢��"<<endl;
    }
};


//���� ��ʼ��װ��̨��ͬ�ĵ���
void test01(){
//    ��һ̨���Ե����
    CPU *interCpu = new InterCpu;
    VideoCard *interCard = new InterVideoCard;
    Memory * interMem = new InterMemory;

    cout<<"��һ̨���Կ�ʼ����"<<endl;
//    ������һ̨����
    Computer * computer1 = new Computer(interCpu,interCard,interMem);
    computer1->work();
    delete computer1;//�ͷ�

    cout<<"����������������������������"<<endl;
    cout<<"�ڶ�̨���Կ�ʼ����"<<endl;
//    �ڶ�̨���Ե���װ
//    �����ڶ�̨����
    Computer * computer2 = new Computer(new LenovoCpu,new LenovoVideoCard,new LenovoMemory);
    computer2->work();
    delete computer2;//�ͷ�

//    ����̨���Ե���װ
//    CPU *interCpu = new InterCpu;
//    VideoCard *lenovoCard = new LenovoVideoCard;
//    Memory * interMem = new InterMemory;

//    ��������̨����
//    Computer *computer3 = new Computer(interCpu,lenovoCard,interMem);
//    computer3->work();
//    delete computer3;//�ͷ�

    cout<<"����������������������������"<<endl;
    cout<<"����̨���Կ�ʼ����"<<endl;
//    ����̨���Ե���װ
//    ��������̨����
    Computer * computer3 = new Computer(new InterCpu,new LenovoVideoCard,new InterMemory);
    computer3->work();
    delete computer3;//�ͷ�
}

int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
