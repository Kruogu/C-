//
// Created by tianya on 2024/11/23.
//
#include "iostream"
using namespace std;
#include "fstream"      //�ļ���
#include "02Identity.cpp"  //��ݻ���
#include "03student.cpp"
#include "04teacher.cpp"
#include "05manager.cpp"
#include "06globalfile.h"//ȫ���ļ�
//����ԤԼϵͳ


//ȫ�ֺ���
//8.1ѧ����¼��ע��
void StudentMenu(Identity * &student){
    while (true){
        //����ѧ���ֲ˵�
        student->openMenu();

//        ������ָ�� ǿתΪ ����ָ�룬���������������ӿ�
        Student *stu =(Student*)student;

        int select = 0;

//        �����û�ѡ��
        cin>>select;
        if(select == 1){//����ԤԼ
//            cout<<"����ԤԼ"<<endl;
            stu->applyOrder();
        } else if(select == 2){//�鿴����ԤԼ
//            cout<<"�鿴����ԤԼ"<<endl;
            stu->showMyOerder();
        } else if(select == 3){//�鿴����ԤԼ
//            cout<<"�鿴����ԤԼ"<<endl;
            stu->showAllOrer();
        } else if(select == 4){//ȡ��ԤԼ
//            cout<<"ȡ��ԤԼ"<<endl;
            stu->cancelOrder();
        } else{//ѡ���� ���� Ĭ��ע����¼
//            ע��
            delete student;//���ٵ���������
            cout<<"ע���ɹ���"<<endl;
            system("pause");//�����������
            system("cls");//����
            return;
        }
    }
}

//ȫ�ֺ���
//7.1.2��ʦ�Ӳ˵�����
void TeacherMenu(Identity * &teacherr){
    while (true){
        //���ý�ʦ�ֲ˵�
        teacherr->openMenu();

//        ������ָ�� ǿתΪ ����ָ�룬���������������ӿ�
        Teacher *tea =(Teacher*)teacherr;

        int select = 0;

//        �����û�ѡ��
        cin>>select;
        if(select == 1){//�鿴����ԤԼ
//            cout<<"�鿴����ԤԼ"<<endl;
            tea->showAllOrer();
        } else if(select == 2){//���ԤԼ
//            cout<<"���ԤԼ"<<endl;
            tea->validOrder();
        } else{//ѡ���� ���� Ĭ��ע����¼
//            ע��
            delete teacherr;//���ٵ���������
            cout<<"ע���ɹ���"<<endl;
            system("pause");//�����������
            system("cls");//����
            return;
        }
    }
}

//ȫ�ֺ���
//7.1.2����Ա�Ӳ˵�����
void mangerMenu(Identity * &manager){
    while (true){
//        ���ù���Ա�Ӳ˵�  ����ָ�봴�����������ù�ͬ�ӿ�  ��д���麯��
        manager->openMenu();

//        ������ָ�� ǿתΪ ����ָ�룬���������������ӿ�
            Manager* man = (Manager*) manager;

            int select = 0;

//        �����û�ѡ��
        cin>>select;
        if(select == 1){//����˺�
//            cout<<"����˺�"<<endl;
            man->addPerson();
        } else if(select == 2){//�鿴�˺�
//            cout<<"�鿴�˺�"<<endl;
            man->showPerson();
        } else if(select == 3){//�鿴������Ϣ
//            cout<<"�鿴����"<<endl;
            man->showComputer();
        } else if(select == 4){//���ԤԼ
//            cout<<"���ԤԼ"<<endl;
            man->cleanFile();
        } else{//ѡ���� ���� Ĭ��ע����¼
//            ע��
            delete manager;//���ٵ���������
            cout<<"ע���ɹ���"<<endl;
            system("pause");//�����������
            system("cls");//����
            return;
        }
    }
}

//ȫ�ֺ���
//6.2��¼������װ ����1  �����ļ���   ����2  �����������
void LoginIn(string fileName,int type){

//    ����ָ��ָ���������
    Identity *person = NULL;

//    ���ļ�
    ifstream ifs;
    ifs.open(fileName,ios::in);//������ʲô�ļ����Ͷ�ʲô�ļ�

//    �ж��ļ��Ƿ����
    if(!ifs.is_open()){
        cout<<"�ļ������ڣ�"<<endl;
        ifs.close();
        return;
    }

//    ׼�������û���Ϣ
    int id = 0;
    string name;
    string pwd;

//    �ж����
    if(type == 1)//ѧ�����
    {
        cout<<"����������ѧ��"<<endl;
        cin>>id;
    }else if(type == 2)//��ʦ���
    {
        cout<<"����������ְ�����"<<endl;
        cin>>id;
    }

    cout<<"�������û�����"<<endl;
    cin>>name;

    cout<<"���������룺"<<endl;
    cin>>pwd;

    if(type==1){
        //ѧ�������֤
        int fId;        //���ļ��ж�ȡ��id��
        string fName;   //���ļ��л�ȡ������
        string fPwd;    //���ļ��л�ȡ����
//        ��ʱ���ܶ�ȡ���֣�������ֻ�ܶ�ȡ zhangsan ������ᵼ�����룬��д�ְ���޸ĺ�������Ҳ����
//        �ڼ���txt�У�ANS1�������GB2312���룬�ĳ�ANSI�ͺã��ü��±��򿪣����Ϊ����ʽѡ��ANSI��������
        while (ifs>>fId && ifs>>fName && ifs>>fPwd){//�����ո��Զ�����һ��
//            ���Զ�ȡ�ļ�������Ϣ
//            {
//                cout<<fId<<endl;
//                cout<<fName<<endl;
//                cout<<fPwd<<endl;
//                cout<<endl;
//            }

//            ���û��������Ϣ���Ա�
            if(id==fId && name==fName && pwd==fPwd){
                cout<<"ѧ����֤��¼�ɹ���"<<endl;
                system("pause");//�����������
                system("cls");//����

                //����person�������˰��죬ԭ�� pwd �� string���͵ģ�
                // ��Student�����вι�������д����int���ĳ�string�ͺ���
                person = new Student(id,name,pwd);
//                ����ѧ����ݵ��Ӳ˵�
                StudentMenu(person);

                return;
            }
        }
    }
    else if(type==2){
        //��ʦ�����֤
        int fId;        //���ļ��ж�ȡ��id��
        string fName;   //���ļ��л�ȡ������
        string fPwd;    //���ļ��л�ȡ����
        while (ifs>>fId && ifs>>fName && ifs>>fPwd){//�����ո��Զ�����һ��

//            ���û��������Ϣ���Ա�
            if(id==fId && name==fName && pwd==fPwd){
                cout<<"��ʦ��֤��¼�ɹ���"<<endl;
                system("pause");//�����������
                system("cls");//����

                person = new Teacher(id,name,pwd);
//                �����ʦ��ݵ��Ӳ˵�
                TeacherMenu(person);
                return;
            }
        }
    }
    else if(type==3){
        //����Ա�����֤
        string fName;   //���ļ��л�ȡ������
        string fPwd;    //���ļ��л�ȡ����
        while (ifs>>fName && ifs>>fPwd) {//�����ո��Զ�����һ��

//            ���û��������Ϣ���Ա�
            if(name==fName && pwd==fPwd) {
                cout << "����Ա��֤��¼�ɹ���" << endl;
                //��¼�ɹ��󣬰�������������Ա����
                system("pause");//�����������
                system("cls");//����

//                ��������Ա����
                person = new Manager(name, pwd);//����Ա�� 1 ����û��ID
//                �������Ա��ݵ��Ӳ˵�
                mangerMenu(person);

                return;
            }
        }
    }

    cout<<"��֤��¼ʧ�ܣ�"<<endl;
    system("pause");//�����������
    system("cls");//����
}
int main(){

    int select = 0;
    while (true){
        cout << "===================== ��ӭ��������ԤԼϵͳ ====================="<<endl;
        cout <<endl<<"�������������"<<endl;
        cout << "\t\t ������������������������������������������������������ \n";
        cout << "\t\t|                           |\n";
        cout << "\t\t|         1.ѧ������         |\n";
        cout << "\t\t|                           |\n";
        cout << "\t\t|         2.��   ʦ          |\n";
        cout << "\t\t|                           |\n";
        cout << "\t\t|         3.�� �� Ա         |\n";
        cout << "\t\t|                           |\n";
        cout << "\t\t|         0.��   ��          |\n";
        cout << "\t\t|                           |\n";
        cout << "\t\t ������������������������������������������������������ \n";
        cout <<"��������ѡ��";

        cin>>select;    //�����û�ѡ��

        switch(select)//�����û�ѡ�� ʵ�ֲ�ͬ�ӿ�
        {
            case 1:     //ѧ�����
                LoginIn(STUDENT_FILE,1);
                break;
            case 2:     //��ʦ���
                LoginIn(TEACHER_FILE,2);
                break;
            case 3:     //����Ա���
                LoginIn(ADMIN_FILE,3);
                break;
            case 0:     //�˳�ϵͳ
                cout <<"��ӭ��һ��ʹ��"<<endl;
                system("pause");
                return 0;
                break;
            default:
                cout <<"��������������ѡ��"<<endl;
                system("pause");
                system("cls");
                break;
        }

    }

    cout<<"HelloWorld"<<endl;
    return 0;
}

