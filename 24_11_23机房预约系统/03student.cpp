//
// Created by tianya on 2024/11/23.
//

#include "03student.h"

//    Ĭ�Ϲ���
Student::Student(){

}

//    �вι��� ������ѧ�š�����������
Student::Student(int id,string name,string pwd){
    //    ��ʼ��ѧ����Ϣ ����
    this->m_Id = id;
    this->m_Name = name;
    this->m_Pwd = pwd;//���ڿ����޸�����

//    ��ʼ��������Ϣ
    ifstream  ifs;
    ifs.open(COMPUTER_FILE,ios::in);

    ComputerRoom com;
    while (ifs>>com.m_ComId && ifs>>com.m_MaxNum){
//        ����ȡ����Ϣ���뵽������
        vCom.push_back(com);
    }
    ifs.close();
}

//    �˵�����  ��д���麯��
void Student::openMenu(){
    cout <<endl<<"��ӭѧ����"<< this->m_Name<<"��¼��"<<endl;
    cout << "\t\t ������������������������������������������������������ \n";
    cout << "\t\t|                           |\n";
    cout << "\t\t|         1.����ԤԼ         |\n";
    cout << "\t\t|                           |\n";
    cout << "\t\t|         2.�鿴����ԤԼ      |\n";
    cout << "\t\t|                           |\n";
    cout << "\t\t|         3.�鿴����ԤԼ      |\n";
    cout << "\t\t|                           |\n";
    cout << "\t\t|         4.ȡ��ԤԼ         |\n";
    cout << "\t\t|                           |\n";
    cout << "\t\t|         0.ע����¼         |\n";
    cout << "\t\t|                           |\n";
    cout << "\t\t ������������������������������������������������������ \n";
    cout <<"��������ѡ��";
}

//    ����ԤԼ
void Student::applyOrder(){
    cout <<"��������ʱ��Ϊ��һ�����壡"<<endl;
    cout <<"����������ԤԼ��ʱ�䣺"<<endl;
    cout <<"1����һ"<<endl;
    cout <<"2���ܶ�"<<endl;
    cout <<"3������"<<endl;
    cout <<"4������"<<endl;
    cout <<"5������"<<endl;

    int date = 0;       //����
    int interval = 0;   //ʱ���
    int room = 0;       //�������

    while (true){
        cin>>date;
        if(date>=1 && date<=5){
            break;
        }
        cout<<"�����������������룡"<<endl;
    }


    cout <<"����������ԤԼ��ʱ��Σ�"<<endl;
    cout <<"1������"<<endl;
    cout <<"2������"<<endl;
    while (true){
        cin>>interval;
        if(interval>=1 && interval<=2){
            break;
        }
        cout<<"�����������������룡"<<endl;
    }

    cout <<"��ѡ�������"<<endl;
    for (int i = 0; i < vCom.size(); ++i) {//size = 3
        cout <<vCom[i].m_ComId<<"�Ż���������Ϊ"<<vCom[i].m_MaxNum<<endl;// 1 50  2  100  3  150
    }
    while (true){
        cin>>room;
        if(room>=1 && room<=3){
            break;
        }
        cout<<"�����������������룡"<<endl;
    }

    ofstream ofs;
    ofs.open(ORDER_FILE,ios::app);

    ofs<<"date:"<<date<<" ";            //ԤԼ����
    ofs<<"interval:"<<interval<<" ";    //ʱ����
    ofs<<"stuId:"<< this->m_Id<<" ";    //ѧ��Id
    ofs<<"stuName:"<< this->m_Name<<" ";//ѧ������
    ofs<<"roomId:"<<room<<" ";            //ԤԼ����
    ofs<<"status:"<<1<<endl;            //ԤԼ״̬

    ofs.close();

    system("pause");//�����������
    system("cls");//����
}

//    �鿴����ԤԼ
void Student::showMyOerder(){
    OrderFile of;   //����ʵ�������󣬿�����
//    OrderFile *of = new OrderFile;//������
//    OrderFile(); //������

    if(of.m_Size == 0){
        cout<<"��ԤԼ��¼��"<<endl;
        system("pause");//�����������
        system("cls");//����
        return;
    }

    for (int i = 0; i < of.m_Size; ++i) {
//        this->m_Id��int����
//        of.m_orderData[i]["stuId"]��str���ͣ��޷��ԱȲ���
//        �����һ�� .c_str()ת���� c���Է����ַ��� const char*
//        ������� atoi�ķ�ʽ(const char*)ǿ��ת���� int ����
//        ���� == ��������һ�¾Ϳ��Խ��� �����ж�
        if(this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str())){//�ҵ�����ԤԼ
            cout<<"ԤԼ���ڣ���"<<of.m_orderData[i]["date"];
            cout<<" ʱ��Σ�"<<(of.m_orderData[i]["interval"]=="1"?"����":"����");
            cout<<" ������ţ�"<<of.m_orderData[i]["roomId"];

            string status = " ״̬";//1�����  2�ɹ�ԤԼ -1ԤԼʧ�� 0ȡ��ԤԼ
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
    }
    system("pause");//�����������
    system("cls");//����
}

//    �鿴����ԤԼ
void Student::showAllOrer(){
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

//    ȡ��ԤԼ
void Student::cancelOrder(){
    OrderFile of;
    if(of.m_Size == 0){
        cout<<"��ԤԼ��¼"<<endl;
        system("pause");//�����������
        system("cls");//����
        return;
    }
    cout<<"����л�ԤԼ�ɹ��ļ�¼����ȡ����������ȡ���ļ�¼"<<endl;

    vector<int>v;//�������������е��±���
    int index = 1;
    for (int i = 0; i < of.m_Size; ++i) {
//        ���ж��������ѧ��
        if(this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str())){
//            ��ɸѡ״̬     ����л�ԤԼ�ɹ��ſ���
            if(of.m_orderData[i]["status"] == "1" ||of.m_orderData[i]["status"] == "2"){
                v.push_back(i);
                cout<<index++<<"��";
                cout<<"ԤԼ���ڣ���"<<of.m_orderData[i]["date"];
                cout<<" ʱ��Σ�"<<(of.m_orderData[i]["interval"]=="1"?"����":"����");
                cout<<" ������ţ�"<<of.m_orderData[i]["roomId"];

                string status = " ״̬��";//1�����  2�ɹ�ԤԼ -1ԤԼʧ�� 0ȡ��ԤԼ
                if(of.m_orderData[i]["status"] == "1"){
                    status += "�����";
                } else if(of.m_orderData[i]["status"] == "2"){
                    status += "�ɹ�ԤԼ";
                }
//                else if(of.m_orderData[i]["status"] == "-1"){
//                    status += "ԤԼʧ��,���δͨ��";
//                } else if(of.m_orderData[i]["status"] == "0"){1
//                    status += "ԤԼ��ȡ��";
//                }
                cout<<status<<endl;
            }
        }
    }

    //indexû��++��˵�������forѭ��û�н���  Ҳ����û������������ԤԼ��¼�����Ϊ�գ�ֱ���˳�����һ��
    if(index == 1){
        cout<<"���޴�ȡ����¼��"<<endl;
        system("pause");//�����������
        system("cls");//����
        return;
    }

    cout<<"������Ҫȡ���ļ�¼��0������"<<endl;//û��1���ѡ��
    int select = 0;
    while (true){
        cin>>select;    //����ѡ��
        if(select>=0 && select<=v.size()){//3
            if(select == 0){//����
                break;
            } else{//Ҫȡ���ļ�¼
                of.m_orderData[v[select-1]]["status"] = "0";//�ĳ� 0 ȡ����¼
                of.updateOrder();   //�����ļ�
                cout<<"��ȡ��ԤԼ��"<<endl;
                break;
            }
        }
        cout<<"�����������������룡"<<endl;
    }
    system("pause");//�����������
    system("cls");//����
}
