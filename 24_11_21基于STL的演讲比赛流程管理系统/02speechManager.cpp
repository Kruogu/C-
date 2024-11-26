//
// Created by tianya on 2024/11/21.
//

#include "02speechManager.h"
//���캯��  �����ǵ��ó�Ա����
SpeechManager::SpeechManager(){
    //��ʼ������
    this->initspeech();

//    ����ѡ��
    this->createSpeaker();

//    ���������¼
    this->loadRecord();
}

//4.2�˵�����ʵ��
void SpeechManager::show_Menu(){
    cout << "*****************************************" << endl;
    cout << "************* ��ӭ�μ��ݽ����� *************" << endl;
    cout << "************** 1.��ʼ�ݽ����� *************" << endl;
    cout << "************** 2.�鿴�����¼ *************" << endl;
    cout << "************ * 3.��ձ�����¼ *************" << endl;
    cout << "************** 0.�˳��������� *************" << endl;
    cout << "*****************************************" << endl;
    cout << endl;
}

//5.2ʵ���˳�����
void SpeechManager::exitsystem(){
    cout <<"��ӭ�´�ʹ��" << endl;
    system("pause");
    exit(0);
}

//    6.3.2��ʼ������
void SpeechManager::initspeech(){
//    ������֤Ϊ��
    this->v1.clear();
    this->v2.clear();
    this->vVictory.clear();
    this->m_Speaker.clear();

//    ��ʼ����������
    this->m_Index = 1;

//    ��ʼ����¼����  ����¼������Ҳ���
    this->m_Record.clear();
}

//    6.3.3����ѡ��  ��ʼ������12��ѡ��
void SpeechManager::createSpeaker(){
    string nameSeed = "ABCDEFGHIJKL";
    for (int i = 0; i < nameSeed.size ();i++){
        string name = "ѡ��";
        name += nameSeed[i];

//        ��������ѡ��
        Speaker sp;
        sp.m_Name = name;
//        �����ÿ�
        for (int j = 0; j < 2; ++j) {
            sp.m_Score[j] = 0;
        }

        //12��ѡ�ֱ��   ����ѡ�ֱ��  ���ҷ��뵽v1������
        this->v1.push_back(i+10001);

        //ѡ�ֱ�� �Լ���Ӧ��ѡ�� ��ŵ�map������
        this->m_Speaker.insert(make_pair(i+10001,sp));
    }
}

//    6.3.4��ʼ������Ա�������
//��ʼ����-�������̿���   �����������̵Ŀ��ƺ���
void SpeechManager::startspeech(){
    //��һ�ֱ���
    //1����ǩ
    this->speechDraw();

    //2������
    this->speechContest();

    //3����ʾ�������
    this->showScore();


    //�ڶ��ֱ���
    this->m_Index++;
    //1����ǩ
    this->speechDraw();
    //2������
    speechContest();
    //3����ʾ���ս��
    this->showScore();


    //4���������
    this->saveRecord();

//    ���ñ�������ȡ��¼���൱��������һ�ι��캯����ʼ��
//    ��ʼ������
    this->initspeech();
//    ����ѡ��
    this->createSpeaker();
//    ���������¼
    this->loadRecord();

    cout<<"���������ϣ�"<<endl;

    system("pause");//�����������
    system("cls");//����1
}

//    6.3.5��ǩ
void SpeechManager::speechDraw(){
    cout<<"��<<"<< this->m_Index<<">>�ֱ���ѡ�����ڳ�ǩ"<<endl;
    cout<<"����������������������������������������������"<<endl;
    cout<<"��ǩ���ݽ�˳�����£�"<<endl;

    if(this->m_Index == 1){
        //��һ�ֱ���  random_shuffleϴ���㷨
        random_shuffle(v1.begin(),v1.end());
        for(vector<int>::iterator it=v1.begin();it!=v1.end();it++){
            cout<<*it<<" ";
        }
        cout<<endl;
    } else{
        //�ڶ��ֱ���
        random_shuffle(v2.begin(),v2.end());
        for(vector<int>::iterator it=v2.begin();it!=v2.end();it++){
            cout<<*it<<" ";
        }
        cout<<endl;
    }
    cout<<"����������������������������������������������"<<endl;
    system("pause");
}


//    6.3.6��ʼ����
void SpeechManager::speechContest(){
    cout<<"��������������������"<< this->m_Index<<"�ֱ�����ʽ��ʼ����������������"<<endl;

    //׼����ʱ���� ���С��ɼ�  ��ʱ   multimap���ظ�
    multimap<double,int,greater<double>> groupScore;

    int num = 0;//��¼С����Ա���� 6

    vector<int>v_Src;//����ѡ������
    if(this->m_Index == 1){
        v_Src = v1;
    } else{
        v_Src = v2;
    }

//    ��������ѡ�ֽ��б���
    for(vector<int>::iterator it=v_Src.begin();it!=v_Src.end();it++){
        num++;
        //��ί���
        deque<double>d;
        for (int i = 0; i < 10; ++i) {
            double score = (rand()%401+600)/10.f;//600~1000  ��10 Ϊ60~100

//        ���Դ�ӡ12���˵����гɼ���ÿ������10����ί���
//            cout<<score<<" ";
//            cout<<score<<"\t";//��̫����

            d.push_back(score);
        }
//        cout<<endl;

//        ����
        sort(d.begin(),d.end(),greater<double>());//douoble���͵���������

        d.pop_front();//ȥ����߷�
        d.pop_back();//ȥ����ͷ�

//        ���ܷ�
        double sum = accumulate(d.begin(),d.end(),0.0f);

//        ��ƽ����  doubleǿתС������
        double avg = sum/(double)d.size();

//        ���Դ�ӡƽ����
//        cout<<"��ţ�"<<*it
//            <<"������"<<this->m_Speaker[*it].m_Name
//            <<"��ȡƽ���֣�"<<avg<<endl;

//        ��ƽ���ַ��뵽map���� ����  *it��ѡ�ֱ��
        this->m_Speaker[*it].m_Score[this->m_Index-1] = avg;


//        ��������ݷ��뵽��ʱС��������
        groupScore.insert(make_pair(avg,*it));//keyֵavg��ƽ���֣�valueֵ*it��ѡ�ֱ��

//        ÿ6��ȡ��ǰ����
        if(num%6 == 0){
            cout<<"��"<<num/6<<"С��������Σ�"<<endl;
            for(multimap<double,int,greater<double>>::iterator it=groupScore.begin();it!=groupScore.end();it++){
                cout<<"��ţ�"<<it->second
                    <<"������"<< this->m_Speaker[it->second].m_Name
                    <<"�ɼ���"<< this->m_Speaker[it->second].m_Score[m_Index-1]<<endl;
                //��ѡ��multimap������valueֵ(second)��,ȡ���ɼ�m_Score��[m_Index-1]���������±��һ
            }

//            ȡ��ǰ����
            int count = 0;
            for(multimap<double,int,greater<double>>::iterator it=groupScore.begin();it!=groupScore.end() && count<3;it++,count++){
                if(this->m_Index == 1){//����ǵ�һ��
                    v2.push_back((*it).second);
                } else{
                    vVictory.push_back((*it).second);//����ǵڶ��֣��Ǿ�ȡ����ѡ��vVictory
                }
            }
//            ��һ�������֮��С�������ɼ���գ�����ջᵼ�����ʣ�����Ա
            groupScore.clear();
            cout<<endl;
        }

    }
    cout<<"��������������������������"<< this->m_Index<<"�ֱ�����ϣ�������������������������"<<endl;
//    cout<<endl;
    system("pause");
}

//    6.3.7��ʾ��������  �������
void SpeechManager::showScore(){
    cout<<"��������������������"<< this->m_Index<<"�ֽ���ѡ����Ϣ���¡���������������"<<endl;

    vector<int>v;
    if(this->m_Index == 1){
        v = v2;
    } else{
        v = vVictory;
    }
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<"ѡ�ֱ�ţ�"<<*it
            <<"������"<< this->m_Speaker[*it].m_Name
            <<"�ɼ���"<< this->m_Speaker[*it].m_Score[m_Index-1]<<endl;
    }
    cout<<endl;

    system("pause");//�����������
    system("cls");//����
    show_Menu();//��ʾ���˵� �������һ�Σ�������

}

//    6.4�������   �����¼
void SpeechManager::saveRecord(){
//    �����ļ�
    ofstream ofs;
//    ��׷�ӵķ�д�ļ�
//    ofs.open("speech.csv",ios::out|ios::app);
    ofs.open(FILENAME,ios::out|ios::app);

//    ��ÿ��ѡ�ֵ����� д�뵽�ļ���
    for(vector<int>::iterator it=vVictory.begin();it!=vVictory.end();it++){
//        *it ѡ�ֱ��   csv�ļ���Ҫ�� , ���� �ָ�ʶ��
        ofs<<*it<<","<< this->m_Speaker[*it].m_Score[1]<<",";
    }
    ofs<<endl;

//    �ر��ļ�
    ofs.close();
    cout <<"��¼�Ѿ�����"<<endl;

//    �����ļ���Ϊ�յ�״̬
    this->fileIsEmpty = false;
}

//    7.1��ȡ��¼����
void SpeechManager::loadRecord(){
    ifstream ifs("speech.csv",ios::in);//���ļ�
    if(!ifs.is_open()){
        this->fileIsEmpty = true;
//        cout<<"�ļ�������"<<endl;//���Դ���
        ifs.close();
        return;
    }

//    �ļ�������
    char ch;
    ifs>>ch;//�۲��ܲ��ܶ�����
    if(ifs.eof()){
//        cout<<"�ļ�Ϊ��"<<endl;//���Դ���
        this->fileIsEmpty = true;
        ifs.close();
        return;
    }

//    �ļ���Ϊ��
    this->fileIsEmpty = false;

    ifs.putback(ch);//�������ȡ�ĵ����ַ����Ż���

    string data;//�õ�һ���ַ�������
    int index = 0;//Ĭ�������ǵ�0����Ϣ

    while (ifs>>data){
        //���Դ���  ���õ��ַ�����Ȼ����н���
//        cout<<data<< endl;
//        10002,86.675,10009,81.3,10007,78.55,

        vector<string>v;//���6���ַ����ַ���
        //zhangsan@sina.com   zhangsan
        int pos = -1;;//�鵽","λ�õı���
        int start = 0;//��ʼλ��Ϊ0

        while (true){
            pos = data.find(",",start);
            if(pos == -1){
                //û���ҵ������
                break;
            }
            string temp = data.substr(start,pos-start);
//            cout<<temp<<endl;//�������
            v.push_back(temp);//ֱ�ӷ�������

            start = pos+1;//��ʼλ�ñ���
        }

//        ÿ������׷�ӵ�������
        this->m_Record.insert(make_pair(index,v));
        index++;//��һ��
    }
    ifs.close();

//    ��������ھ���Ϣ  ���showRecord()
//    for(map<int,vector<string>>::iterator it=this->m_Record.begin();it!=this->m_Record.end();it++){
//        cout<<"��"<<it->first+1<<"�� "
//            <<"�ھ���ţ�"<<it->second[0]
//            <<" ������"<<it->second[1]<<endl;
//    }
}

//    7.2�鿴��¼����  ��ʾ�����¼
void SpeechManager::showRecord(){
    //���ж��ļ��Ƿ����
    if(this->fileIsEmpty){
        cout<<"�ļ�Ϊ�ջ��ļ������ڣ�"<<endl;
    } else{
//    ��������������ķ�ʽдҲ����
        for (int i = 0; i < this->m_Record.size(); ++i) {
            cout<<"��"<<i+1<<"�� "
                <<"�ھ���ţ�"<< this->m_Record[i][0]//��i�죬��0��
                <<"�÷֣�"<<this->m_Record[i][1]

                <<"\t�Ǿ���ţ�"<< this->m_Record[i][2]//��i�죬��2��
                <<"�÷֣�"<<this->m_Record[i][3]

                <<"\t������ţ�"<< this->m_Record[i][4]//��i�죬��4��
                <<"�÷֣�"<<this->m_Record[i][5]<<endl;
        }
    }
    system("pause");//�����������
    system("cls");//����
}

//    8.1��ռ�¼����ʵ��
void SpeechManager::clearRecord(){

    cout<<"�Ƿ�ȷ������ļ���"<<endl;
    cout<<"1����"<<endl;
    cout<<"2����"<<endl;

    int select = 0;//ѡ��

    cin>>select;
    if(select == 1){
//        ȷ�����speech.csv
//        ofstream ofs("speech.csv",ios::trunc);
        ofstream ofs(FILENAME,ios::trunc);
        ofs.close();

//      ��ʼ������
        this->initspeech();
//      ����ѡ��
        this->createSpeaker();
//      ���������¼
        this->loadRecord();

        cout<<"��ճɹ���"<<endl;

        //    �����ļ���Ϊ�յ�״̬
        this->fileIsEmpty = true;
    }

    system("pause");//�����������
    system("cls");//����
}


//    ��������
SpeechManager::~SpeechManager(){

}