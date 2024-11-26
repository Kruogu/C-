//
// Created by tianya on 2024/11/24.
//

#include "08orderFile.h"

//    ���캯��
OrderFile::OrderFile() {

    ifstream ifs;
    ifs.open(ORDER_FILE,ios::in);//���ļ�

    string date;        //ԤԼ����
    string interval;    //ʱ���
    string stuId;       //ѧ�����
    string stuName;     //ѧ������
    string roomId;        //�������
    string status;      //ԤԼ״̬

    this->m_Size = 0;   //��¼����

    while (ifs>>date && ifs>>interval && ifs>>stuId && ifs>>stuName && ifs>>roomId  && ifs>>status){
//        ���Դ��ļ��л�ȡ��������  ����
//        {
//            cout<<date<<endl;         //date:2
//            cout<<interval<<endl;     //interval:1
//            cout<<stuId<<endl;        //stuId:1
//            cout<<stuName<<endl;      //stuName:����
//            cout<<roomId<<endl;         //roomId:2
//            cout<<status<<endl;       //status:1
//            cout<<endl;
//        }

//          date��string�ַ��������� �У�date:2
//          Ƕ��Сmap�����ڵ�����ֵ
            string key;
            string value;
            map<string ,string > m;

        //��ȡԤԼ����date
        int pos = date.find(":");//pos=4   d a t e : 2
        if(pos!=-1){//                        0 1 2 3 4 5   size = 6
            key = date.substr(0,pos);//date  0~4    6-4-1 = 1
            value = date.substr(pos+1,date.size()-pos-1);//��ʼλ��  ��ȡ����
    //                value = date.substr(pos+1,date.size());//��ô��Ҳ�У����� size ����
            m.insert(make_pair(key,value));//���� ����
        }
//            cout<<"key = "<<key<<endl;
//            cout<<"value = "<<value<<endl;

        //��ȡʱ���interval
        pos = interval.find(":");
        if(pos!=-1){
            key = interval.substr(0,pos);
            value = interval.substr(pos+1,interval.size()-pos-1);//��ʼλ��  ��ȡ����
            m.insert(make_pair(key,value));//���� ����
        }

        //��ȡѧ�����stuId
        pos = stuId.find(":");
        if(pos!=-1){
            key = stuId.substr(0,pos);
            value = stuId.substr(pos+1,stuId.size()-pos-1);//��ʼλ��  ��ȡ����
            m.insert(make_pair(key,value));//���� ����
        }

        //��ȡѧ������stuName
        pos = stuName.find(":");
        if(pos!=-1){
            key = stuName.substr(0,pos);
            value = stuName.substr(pos+1,stuName.size()-pos-1);//��ʼλ��  ��ȡ����
            m.insert(make_pair(key,value));//���� ����
        }

        //��ȡ�������roomId
        pos = roomId.find(":");
        if(pos!=-1){
            key = roomId.substr(0,pos);
            value = roomId.substr(pos+1,roomId.size()-pos-1);//��ʼλ��  ��ȡ����
            m.insert(make_pair(key,value));//���� ����
        }

        //��ȡԤԼ״̬status
        pos = status.find(":");
        if(pos!=-1){
            key = status.substr(0,pos);
            value = status.substr(pos+1,status.size()-pos-1);//��ʼλ��  ��ȡ����
            m.insert(make_pair(key,value));//���� ����
        }

//        ��Сmap�������뵽���map������
        this->m_orderData.insert(make_pair(this->m_Size,m));
        this->m_Size++;
    }
    ifs.close();//�ر�

//    �������map����  ��������ԤԼ ���ļ��л�ȡ��Ԥ����������Ϣ
//    {
//        for(map<int,map<string ,string>>::iterator it=m_orderData.begin();it!=m_orderData.end();it++){
//            cout<<"key����Ϊ��"<<it->first
//                <<"\tvalue = "<<endl;
//            for(map<string,string>::iterator mit=(*it).second.begin();mit!=(*it).second.end();mit++){
//                cout<<"\tk="<<mit->first<<" "    //date:2  key=
//                    <<"v="<<mit->second<<"";    //value=
//            }
//            cout<<endl;
//        }
//    }
}

//    ����ԤԼ��¼
void OrderFile::updateOrder(){

    if(this->m_Size == 0){
        return; //ԤԼ��¼0����ֱ��return
    }

//    ��д�룬��ɾ����д
    ofstream ofs(ORDER_FILE,ios::out|ios::trunc);

//    ���Ը���������������Ϣ
    for (int i = 0; i < this->m_Size; ++i) {
//        ����Ƕ��map����
        ofs<<"date:"<< this->m_orderData[i]["date"]<<" ";
        ofs<<"interval:"<< this->m_orderData[i]["interval"]<<" ";
        ofs<<"stuId:"<< this->m_orderData[i]["stuId"]<<" ";
        ofs<<"stuName:"<< this->m_orderData[i]["stuName"]<<" ";
        ofs<<"roomId:"<< this->m_orderData[i]["roomId"]<<" ";
        ofs<<"status:"<< this->m_orderData[i]["status"]<<" "<<endl;
    }
    ofs.close();

}

