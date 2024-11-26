//
// Created by tianya on 2024/11/20.
//
#include "iostream"
using namespace std;

#include "vector"
#include "map"

#define CEHUA  0
#define MEISHU 1
#define YANFA  2

//3.10����-Ա������

//3.10.1��������
//    ����˾������Ƹ��10��Ա��(ABCDEFGHIJ)��10��Ա�����빫˾֮����Ҫָ��Ա�����Ǹ����Ź���
//    ��Ա����Ϣ�У�����  ������ɣ����ŷ�Ϊ���߻����������з�
//    �������10��Ա�����䲿�ź͹���
//    ��ͨ��multimap:������Ϣ�Ĳ���key(���ű��)value(Ա��)
//    ���ֲ�����ʾԱ����Ϣ


//3.10.2ʵ�ֲ���
//    1.����10��Ա�����ŵ�vector��
//    2.����vector������ȡ��ÿ��Ա���������������
//    3.����󣬽�Ա�����ű����Ϊkey,����Ա����Ϊvalue,���뵽multimap������
//    4.�ֲ�����ʾԱ����Ϣ

//Ա����
class Worker{
public:
//    ����д���캯��
//    Worker(string name){
//        this->m_Name = name;
//    }
    string m_Name;//����
    int m_Salary;//����

};

//��ӡ��Ϣ

//1������Ա��
void createWorker(vector<Worker> &v){
    string nameSeed = "ABCDEFGHIJ";
    for(int i=0;i<10;i++){
        Worker worker;
        worker.m_Name = "Ա��";
        worker.m_Name += nameSeed[i];

//        ����
//        worker.m_Salary = rand()%60+41;//60~100
        worker.m_Salary = rand()%10000+10000;//10000~19999

//        ��Ա�����뵽������
        v.push_back(worker);
    }

//    Worker w2("B");//������ôд
//    Worker w3("C");
}

//2��Ա������
void setGroup(vector<Worker> &v,multimap<int,Worker> &m){
    for(vector<Worker>::iterator it=v.begin();it!=v.end();it++){
        //����������ű��
        int deptID = rand()%3;//0 1 2

//        ��Ա�����뵽������
//        key���ű�ţ�value����Ա��  *it
        m.insert(make_pair(deptID,*it));
//        cout<<"������"<<it->m_Name
//            <<" ���ʣ�"<<(*it).m_Salary<<endl;
    }
}

//3��������ʾԱ��  �Լ�д��
void showWorkerByGourp1(multimap<int,Worker> &m){
    static int flag = 0;
    cout<<"������ʾԱ����"<<endl;
    for(multimap<int,Worker>::iterator it=m.begin();it!=m.end();it++){
        string deptName;
        int index;
        switch (it->first) {
            case 0:
                deptName="�߻�";
                index = 0;
                break;
            case 1:
                deptName="����";
                index = 1;
                break;
            case 2:
                index = 2;
                deptName="�з�";
                break;
            default:
                break;
        }
        if(flag!=index){
            flag = index;
            cout<<endl;
        }

        cout<<"���ţ�"<<deptName
            <<" ������"<<it->second.m_Name
            <<" ���ʣ�"<<(*it).second.m_Salary<<endl;
    }
}

//3��������ʾԱ��  ��ʦ��
void showWorkerByGourp2(multimap<int,Worker> &m){
    // 0 A B C 1 D E 2 F G...
    cout<<"�߻����ţ�"<<endl;
    multimap<int,Worker>::iterator pos = m.find(CEHUA);
    int count = m.count(CEHUA);//ͳ�Ʋ�������
    int index = 0;//����ֵ
    for(;pos!=m.end() && index<count;pos++,index++){
        cout<<"���ţ�"
            <<" ������"<<pos->second.m_Name
            <<" ���ʣ�"<<(*pos).second.m_Salary<<endl;
    }

    cout<<"��������������������"<<endl;
    cout<<"�������ţ�"<<endl;
    pos = m.find(MEISHU);
    count = m.count(MEISHU);//ͳ�Ʋ�������
    index = 0;//����ֵ
    for(;pos!=m.end() && index<count;pos++,index++){
        cout<<"���ţ�"
            <<" ������"<<pos->second.m_Name
            <<" ���ʣ�"<<(*pos).second.m_Salary<<endl;
    }

    cout<<"��������������������"<<endl;
    cout<<"�з����ţ�"<<endl;
    pos = m.find(YANFA);
    count = m.count(YANFA);//ͳ�Ʋ�������
    index = 0;//����ֵ
    for(;pos!=m.end() && index<count;pos++,index++){
        cout<<"���ţ�"
            <<" ������"<<pos->second.m_Name
            <<" ���ʣ�"<<(*pos).second.m_Salary<<endl;
    }
}


void test01(){
//    srand(time(0));//���������
    srand((unsigned int) time(NULL));//���������

//    1������Ա��
    vector<Worker>vWorker;
    createWorker(vWorker);

//    ����
    for(vector<Worker>::iterator it=vWorker.begin();it!=vWorker.end();it++){
        cout<<"������"<<it->m_Name
            <<" ���ʣ�"<<(*it).m_Salary<<endl;
    }
    cout<<endl;

//    2��Ա������
    multimap<int,Worker>mWorker;//keyֵ  ���ű��   valueֵ ����Ա��
    setGroup(vWorker,mWorker);

//    3��������ʾԱ��
    showWorkerByGourp1(mWorker);//�Դ�
//    showWorkerByGourp2(mWorker);//��ʦ
}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
