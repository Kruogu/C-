//
// Created by tianya on 2024/11/3.
//
#include "iostream"
using namespace std;
//#include"workerManager.h"
#include "02workerManager.cpp"// Clion������ͷ�ļ�ò����Ҫ .cpp ����
#include "03worker.h"
//#include "04employee.h"
#include "04employee.cpp"
#include "05manager.cpp"
#include "06boss.cpp"// .h�Ͳ�������

/*
    �޸Ĺ���ֻ�޸ĵ�ֵ
 */
void test(){
    //    ���Դ���
//    Worker * worker = NULL;
//    Employee ep;
//    ep.m_Id = 1;
//    ep.m_Name = "����";
//    ep.m_DeptId = 1;
//    ep.showInfo();

//    �����಻��ʵ������ֻ�ܴ���ָ��
    Worker * worker = NULL;

    worker = new Employee(1,"����",1);
    worker->showInfo();
    delete worker;

    worker = new Manager(2,"����",2);
    worker->showInfo();
    delete worker;

    worker = new Boss(3,"����",3);
    worker->showInfo();
    delete worker;
}

//ְ������ϵͳ
int main(){
//    test01();
//    test();

//    ʵ�������߶���
    WorkerManager wm;//����һ��������Ķ���
    int choice = 0;//ѡ��

    while (true){
//    ���� չʾ�˵� ��Ա����   ��ʾ
        wm.Show_Menu();
        cout<<"����������ѡ��"<<endl;
        cin>>choice;//�����û���ѡ��

        switch (choice) {
            case 0://�˳�ϵͳ
                wm.Exitsystem();
                break;
            case 1://���ְ��
                wm.Add_Emp();
                break;
            case 2://��ʾְ��
                wm.Show_Emp();
                break;
            case 3://ɾ��ְ��
                wm.Del_Emp();
                break;
//            {
//                //����  ���� 1 2 4��ʾְ�����ڣ��������ǲ�����
//                int ret = wm.IsExist(2);
//                if(ret!=-1){
//                    cout<<"ְ������"<<endl;
//                }else{
//                    cout<<"ְ��������"<<endl;
//                }
//                break;
//            }
            case 4://�޸�ְ��
                wm.Mod_Emp();
                break;
            case 5://����ְ��
                wm.Find_Emp();
                break;
            case 6://����ְ��
                wm.Sort_Emp();
                break;
            case 7://����ļ�
                wm.Clean_File();
                break;
            default:
                system("cls");//ˢ����Ļ,����
                break;
        }
    }

    cout<<"HelloWorld"<<endl;
    return 0;
}
