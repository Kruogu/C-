//
// Created by tianya on 2024/11/21.
//

//#include "����STL���ݽ��������̹���ϵͳ.h"
#include "iostream"
using namespace std;
#include "ctime"
#include "02speechManager.cpp"

//���Դ���12��ѡ��
void test01(SpeechManager &sm){
    for(map<int,Speaker>::iterator it=sm.m_Speaker.begin();it!=sm.m_Speaker.end();it++){
        cout << "ѡ�ֱ�ţ�"<< it->first
             <<"������"<<it->second.m_Name
             <<"�ɼ���"<<it->second.m_Score[0]<<endl;
    }
}
int main(){
//    ���������
    srand((unsigned int)time(NULL));

//    �������������
    SpeechManager sm;
//    test01(sm);//����sm��������� ���Դ���12��ѡ��

    int choice=0;//�����洢�û���ѡ��

    while(true) {
        sm.show_Menu();
        cout <<"����������ѡ��: "<< endl;
        cin >> choice;//�����û���ѡ��
        switch (choice) {
            case 1://��ʼ����
                sm.startspeech();
                break;
            case 2://�鿴��¼
//                sm.loadRecord();
                sm.showRecord();
                break;
            case 3://��ռ�¼
                sm.clearRecord();
                break;
            case 0://�˳�ϵͳ
                sm.exitsystem();
                break;
            default:
                system("cls");//����
                break;
        }
    }

    system("pause");
//    cout<<"HelloWorld"<<endl;
    return 0;
}
