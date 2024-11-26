//
// Created by tianya on 2024/11/23.
//

#include "04teacher.h"

//    Ĭ�Ϲ���
Teacher::Teacher(){

}

//    �вι��� ������ѧ�š�����������
Teacher::Teacher(int empId,string name,string pwd){
    //    ��ʼ����ʦ��Ϣ ����
    this->m_EmpId = empId;
    this->m_Name = name;
    this->m_Pwd = pwd;//���ڿ����޸�����
}

//    �˵�����  ��д���麯��
void Teacher::openMenu(){
    cout <<endl<<"��ӭ��ʦ��"<< this->m_Name<<"��¼��"<<endl;
    cout << "\t\t ������������������������������������������������������ \n";
    cout << "\t\t|                           |\n";
    cout << "\t\t|         1.�鿴����ԤԼ      |\n";
    cout << "\t\t|                           |\n";
    cout << "\t\t|         2.���ԤԼ         |\n";
    cout << "\t\t|                           |\n";
    cout << "\t\t|         0.ע����¼         |\n";
    cout << "\t\t|                           |\n";
    cout << "\t\t ������������������������������������������������������ \n";
    cout <<"��������ѡ��";
}


//    �鿴����ԤԼ
void Teacher::showAllOrer(){
    OrderFile of;
    if(of.m_Size == 0){
        cout<<"��ԤԼ��¼"<<endl;
        system("pause");//�����������
        system("cls");//����
        return;
    }

    for (int i = 0; i < of.m_Size; ++i) {
        cout<<i+1<<"��";
        cout<<"ԤԼ���ڣ���"<<of.m_orderData[i]["date"];
        cout<<" ʱ��Σ�"<<(of.m_orderData[i]["interval"]=="1"?"����":"����");
        cout<<" ������"<<of.m_orderData[i]["stuName"];
        cout<<" ѧ�ţ�"<<of.m_orderData[i]["stuId"];
        cout<<" ������ţ�"<<of.m_orderData[i]["roomId"];

        string status = " ״̬��";//1�����  2�ɹ�ԤԼ -1ԤԼʧ�� 0ȡ��ԤԼ
        if(of.m_orderData[i]["status"] == "1"){
            status += "�����";
        } else if(of.m_orderData[i]["status"] == "2"){
            status += "�ɹ�ԤԼ";
        } else if(of.m_orderData[i]["status"] == "-1"){
            status += "ԤԼʧ��,���δͨ��";
        } else if(of.m_orderData[i]["status"] == "0"){
            status += "ԤԼ��ȡ��";
        }
        cout<<status<<endl;
    }
    system("pause");//�����������
    system("cls");//����
}

//    ���ԤԼ
void Teacher::validOrder(){
    OrderFile of;
//    Student *st = new Student;//���в�Ҫ����ʦ����Ҫ�жϣ�����ȡ��������
    if(of.m_Size == 0){
        cout<<"��ԤԼ��¼"<<endl;
        system("pause");//�����������
        system("cls");//����
        return;
    }
    cout<<"����˵�ԤԼ��¼���£�"<<endl;

    vector<int>v;//�������������е��±���
    int index = 1;//����� 0 �Ļ��������ǰ�� ++index Ч��һ��
    for (int i = 0; i < of.m_Size; ++i) {
//        ���ж��������ѧ��
//        if(st->m_Id == atoi(of.m_orderData[i]["stuId"].c_str())){//���в�Ҫ����ʦ����Ҫ�жϣ�����ȡ��������

        //ɸѡ״̬��ֻ�������״̬1�����޸ģ��Ѿ��ɹ�ԤԼ2��ȡ��ԤԼ3������ԤԼʧ��-1�Ķ������޸�
            if(of.m_orderData[i]["status"] == "1" ){

                v.push_back(i);
                cout<<index++<<"��";
                cout<<"ԤԼ���ڣ���"<<of.m_orderData[i]["date"];
                cout<<" ʱ��Σ�"<<(of.m_orderData[i]["interval"]=="1"?"����":"����");
                cout<<" ѧ�ţ�"<<of.m_orderData[i]["stuId"];
                cout<<" ������"<<of.m_orderData[i]["stuName"];
                cout<<" ������ţ�"<<of.m_orderData[i]["roomId"];

                string status = " ״̬��";//1�����  2�ɹ�ԤԼ -1ԤԼʧ�� 0ȡ��ԤԼ
                if(of.m_orderData[i]["status"] == "1"){
                    status += "�����";
                }
//                else if(of.m_orderData[i]["status"] == "2"){     //��������״̬������Ҫ
//                    status += "�ɹ�ԤԼ";
//                }else if(of.m_orderData[i]["status"] == "-1"){
//                    status += "ԤԼʧ��,���δͨ��";
//                } else if(of.m_orderData[i]["status"] == "0"){1
//                    status += "ԤԼ��ȡ��";
//                }
                cout<<status<<endl;
            }
//        }
    }

    //indexû��++��˵�������forѭ��û�н���  Ҳ����û������������ԤԼ��¼�����Ϊ�գ�ֱ���˳�����һ��
    if(index == 1){
        cout<<"���޴���˼�¼��"<<endl;
        system("pause");//�����������
        system("cls");//����
        return;
    }
    cout<<"��������˵�ԤԼ��¼��0������"<<endl;//û��1���ѡ��
    int select = 0;
    int ret = 0;
    while (true){
        cin>>select;    //����ѡ��
        if(select>=0 && select<=v.size()){//3
            if(select == 0){//����
                break;
            } else{//Ҫ��˵ļ�¼
                cout<<"��������˽����"<<endl;
                cout<<"1��ͨ��"<<endl;
                cout<<"2����ͨ��"<<endl;
                cin>>ret;

                while (true){//1�����  2�ɹ�ԤԼ -1ԤԼʧ�� 0ȡ��ԤԼ
                    if(ret==1){
                        of.m_orderData[v[select-1]]["status"] = "2";//ͨ��  2�ɹ�ԤԼ
                        break;
                    }else if(ret==2){
                        of.m_orderData[v[select-1]]["status"] = "-1";//��ͨ��  -1ԤԼʧ��
                        break;
                    }
                    cout<<"�����������������룡"<<endl;
                }

                of.updateOrder();   //�����ļ�
                cout<<"�����ϣ�"<<endl;
                break;
            }
        }
        cout<<"�����������������룡"<<endl;
    }
    system("pause");//�����������
    system("cls");//����
}
