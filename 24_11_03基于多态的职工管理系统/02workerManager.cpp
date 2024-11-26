//
// Created by tianya on 2024/11/3.
//

#include "02workerManager.h"


//��workerManager.cpp�н����������������ʵ�ֲ�ȫ
WorkerManager::WorkerManager(){
//    7.2�����ְ������ʵ��  ��ʼ������  ע�͵����������ļ��ж���
//    this->m_EmpNum = 0;//ְ������ʼΪ 0
//    this->m_EmpArray = NULL;

//    9.1�ļ�δ����  ��������� ��ʼ������
    ifstream ifs;//���ļ�
    ifs.open(FILENAME,ios::in);

//    �ļ����������
    if(!ifs.is_open()){
        cout<<"�ļ�������"<<endl;//�������
//        ��ʼ������
        this->m_EmpNum = 0;//��ʼ������
        this->m_EmpArray = NULL;//��ʼ������
        this->m_FileIsEmpty = true;//��ʼ���ļ�Ϊ�ձ�־
        ifs.close();//�ر��ļ�
        return;
    }

//  9.2�ļ�����������Ϊ��   �ļ����ڣ�����û�м�¼
//  ���Ծ��ǰ��ļ��е�����ɾ���ɾ�
    char ch;
    ifs>>ch;//�ļ�������  �� �ַ�
    if(ifs.eof()){//�ļ�Ϊ�գ����������
        cout<<"�ļ�Ϊ�գ�"<<endl;//�������
        this->m_EmpNum = 0;//��ʼ������
        this->m_EmpArray = NULL;//��ʼ������
        this->m_FileIsEmpty = true;//��ʼ���ļ�Ϊ�ձ�־
        ifs.close();//�ر��ļ�
        return;
    }

//    9.3�ļ����� �� ����ְ������
    int num = this->get_EmpNum();
    cout<<"ְ������Ϊ��"<<num<<endl;
    this->m_EmpNum = num;//��Ա���Ը�������

//    9.3.2��ʼ������ ����
    //���ٿռ�
    this->m_EmpArray = new Worker * [this->m_EmpNum];
//    ���ļ��е����ݣ��浽������
    this->init_Emp();
//    if(num){// ��ɾ����ְ����  ������ʾ������©  ��Ҫ�������Ż�
        this->m_FileIsEmpty = false;//��ʼ���ļ�Ϊ���־������
//    }

    //���Դ��� ����ע�͵�
//    for(int i=0;i< this->m_EmpNum;i++){
//        cout<<"ְ����ţ�"<< this->m_EmpArray[i]->m_Id
//        <<" ������"<< this->m_EmpArray[i]->m_Name
//        <<" ���ű�ţ�"<< this->m_EmpArray[i]->m_DeptId<<endl;//��ʾ����
////        <<" ���ű�ţ�"<< this->m_EmpArray[i]->getDeptName()<<endl;//ֱ����ʾ����
//    }

}

void test01(){
    cout<<"������111"<<endl;
}

//4.2�˵�����ʵ��   ʵ����ʾ
void WorkerManager::Show_Menu() {
    cout<<"**************************"<<endl;
    cout<<"***  ��ӭʹ��ְ������ϵͳ  ***"<<endl;
    cout<<"*****  0.�˳��������  *****"<<endl;
    cout<<"*****  1.���ְ����Ϣ  *****"<<endl;
    cout<<"*****  2.��ʾְ����Ϣ  *****"<<endl;
    cout<<"*****  3.ɾ����ְְ��  *****"<<endl;
    cout<<"*****  4.�޸�ְ����Ϣ  *****"<<endl;
    cout<<"*****  5.����ְ����Ϣ  *****"<<endl;
    cout<<"*****  6.���ձ������  *****"<<endl;
    cout<<"*****  7.��������ĵ�  *****"<<endl;
    cout<<"**************************"<<endl;
    cout<<endl;
}


//5.2ʵ���˳�����
void WorkerManager::Exitsystem() {
    cout<<"��ӭ�´�ʹ��"<<endl;
    system("pause");//ˢ����Ļ
    exit(0);//ֻҪ�������������������˳�
}

//7.2�����ְ������ʵ��
void WorkerManager::Add_Emp(){
    cout<<"���������ְ������"<<endl;

    int addNum = 0;//�����û���������
    cin>>addNum;

    if(addNum>0){
//        ���

//        ��������µĿռ��С
        int newSize = this->m_EmpNum+addNum;//�¿ռ����� = ԭ����¼���� + ��������

//      �� ���� �����¿ռ�
        Worker ** newSpace = new Worker*[newSize];//��Ҫ������

        //��ԭ���ռ������ݣ��������¿ռ���
        if(this->m_EmpArray != NULL){
            for(int i=0;i< this->m_EmpNum;i++){
                newSpace[i] = this->m_EmpArray[i];
            }
        }

//        �������������
        for(int i=0;i<addNum;i++){
            int id;//ְ�����
            string name;//ְ������
            int dSelect;//����ѡ��

            cout<<"������� "<<i+1<<"����ְ���ı�ţ�"<<endl;
            cin>>id;

            cout<<"������� "<<i+1<<"����ְ����������"<<endl;
            cin>>name;

            cout<<"��ѡ���ְ����λ��"<<endl;
            cout<<"1����ְͨ��"<<endl;
            cout<<"2������"<<endl;
            cout<<"3���ܲ�"<<endl;
            cin>>dSelect;

             Worker * worker = NULL;//���� worker ǰ�� ָ�� ��
            switch (dSelect) {
                case 1:
                    worker = new Employee(id,name,1);
                    break;
                case 2:
                    worker = new Manager(id,name,2);
                    break;
                case 3:
                    worker = new Boss(id,name,3);
                    break;
                default:
                    break;
            }

//            ������ְ��ְ�𣬱��浽������
            newSpace[this->m_EmpNum+i] = worker;
        }

//        �ͷ�ԭ�пռ�
        delete[] this->m_EmpArray;//��Ҫ������

//        �����¿ռ��ָ��
        this->m_EmpArray = newSpace;

//        �����µ�ְ������
        this->m_EmpNum = newSize;

//        9.2 ����ְ����Ϊ�ձ�־
        this->m_FileIsEmpty = false;

        //��ʾ��ӳɹ�
        cout<<"�ɹ����"<<addNum<<"����ְ��"<<endl;

        //8.1�ɹ���Ӻ� ���浽�ļ���
        this->save();//��������Ϊû���� ->
    }else{
        cout<<"������������"<<endl;
    }

//    ��������� ���� �ص��ϼ�Ŀ¼
    system("pause");//�������
    system("cls");//����
}

//8.3�����ļ�����ʵ��
void WorkerManager::save(){
    ofstream ofs;
    ofs.open(FILENAME,ios::out);//������ķ�ʽ���ļ� һ д�ļ�

//    ��ÿ��������д�뵽�ļ���
    for(int i=0;i<this->m_EmpNum;i++){
        ofs<<this->m_EmpArray[i]->m_Id<<" "
            <<this->m_EmpArray[i]->m_Name<<" "
            << this->m_EmpArray[i]->m_DeptId<< endl;
    }
//    �ر��ļ�
    ofs.close();
}

//9.3ͳ���ļ�������
int WorkerManager::get_EmpNum(){
    ifstream ifs;
    ifs.open(FILENAME,ios::in);//���ļ� ��

    int id;
    string name;
    int dId;

    int num = 0;
//    ifs<<�����ո�ʱ���Զ�����
    while (ifs>>id && ifs>>name && ifs>>dId){
        //ͳ����������
        num++;
    }
    return num;
}

//9.3.2��ʼ������
void WorkerManager::init_Emp(){
    ifstream ifs;
    ifs.open(FILENAME,ios::in);//���ļ� ��

    int id;
    string name;
    int dId;

    int index = 0;
    while (ifs>>id && ifs>>name && ifs>>dId){
        Worker * worker = NULL;

//        ���ݲ�ͬ���ŵ�Id������ͬ����
        if(dId==1)// 1��ͨԱ��
        {
            worker = new Employee(id,name,dId);
        }
        else if(dId==2)// 2����
        {
            worker = new Manager(id,name,dId);
        }
//        else(dId==3)// 3�ܲ�  �������ﲻ��д�����
        else
        {
            worker = new Boss(id,name,dId);
        }

//        �����������
        this->m_EmpArray[index] = worker;
        index++;
    }

    //�ر��ļ�
    ifs.close();
}

//10.2��ʾְ������ʵ��
void WorkerManager::Show_Emp(){
//    �ж��ļ��Ƿ�Ϊ��  �����ھ���true ���ھ���false
    if(this->m_FileIsEmpty) {//m_FileIsEmpty����һ����������
        cout<<"�ļ������ڻ��¼Ϊ�գ�"<<endl;
    }
    else{
        for(int i=0;i<m_EmpNum;i++){
            //���ö�̬���ó���ӿ�
            this->m_EmpArray[i]->showInfo();
        }
    }
    //    ��������� ���� �ص��ϼ�Ŀ¼
    system("pause");//�������
    system("cls");//����
}

//11.3ְ���Ƿ���ں���ʵ��
//����ְ������ж�ְ���Ƿ���ڣ������ڷ���ְ����������λ�ã������ڷ���-1
int WorkerManager::IsExist(int id) {
    int index = -1;

    for(int i=0;i< this->m_EmpNum;i++){
        if(this->m_EmpArray[i]->m_Id == id){
            //�ҵ�ְ��
            index = i;
            break;
        }
    }
    return index;
}

//11.4ɾ��ְ������ʵ��  ������ɾ�� ���ʾ�������ǰ��
void WorkerManager::Del_Emp() {
    if(this->m_FileIsEmpty){
        cout<<"�ļ������ڻ��¼Ϊ�գ�"<<endl;
    }else{
        //����ְ�����ɾ��
        cout<<"��������Ҫɾ����ְ����ţ�"<<endl;
        int id = 0;
        cin >> id;

        int index = this->IsExist(id);// -1���ǲ�����

        if(index != -1){//˵��ְ�����ڣ�����Ҫɾ����indexλ���ϵ�ְ��
//            ����ǰ��
            for(int i=index;i< this->m_EmpNum-1;i++){
                this->m_EmpArray[i]= this->m_EmpArray[i+1];
            }
            this->m_EmpNum--;//���������м�¼��Ա����

            if(m_EmpNum==0){
                this->m_FileIsEmpty = true;//�����ļ�Ϊ��  �������Ż���д��
            }
            //����ͬ�����µ��ļ���
            this->save();

            cout<<"ɾ���ɹ�!"<<endl;
        }else{
            cout<<"ɾ��ʧ�ܣ�δ�ҵ���ְ��"<<endl;
        }
    }
    //    ��������� ���� �ص��ϼ�Ŀ¼
    system("pause");//�������
    system("cls");//����
}

//12.2�޸�ְ������ʵ��
void WorkerManager::Mod_Emp(){
    if(this->m_FileIsEmpty){
        cout<<"�ļ������ڻ��¼Ϊ�գ�"<<endl;
    }else{
        //����ְ������޸�
        cout<<"��������Ҫ�޸ĵ�ְ����ţ�"<<endl;
        int id = 0;
        cin >> id;

        int index = this->IsExist(id);// -1���ǲ�����  д��retҲ�У���һ��

        if(index != -1) {//˵��ְ�����ڣ�����Ҫ�޸�indexλ���ϵ�ְ��
            //���ҵ���ŵ�ְ��
            delete this->m_EmpArray[index];
            int newId = 0;
            string newName = "";//Ĭ�Ͽ��ַ���
            int dSelect = 0;

            cout<<"�鵽��"<<id<<"��ְ������������ְ���ţ�"<<endl;
            cin>>newId;

            cout<<"��������������"<<endl;
            cin>>newName;

            cout<<"�������λ��"<<endl;
            cout<<"1����ְͨ��"<<endl;
            cout<<"2������"<<endl;
            cout<<"3���ܲ�"<<endl;
            cin>>dSelect;

            Worker *worker = NULL;
            switch (dSelect) {
                case 1:
                    worker = new Employee(newId,newName,dSelect);
                    break;
                case 2:
                    worker = new Manager(newId,newName,dSelect);
                    break;
                case 3:
                    worker = new Boss(newId,newName,dSelect);
                    break;
                default:
                    break;
            }

            //���� �������ݵ�������
            this->m_EmpArray[index] = worker;

            cout<<"�޸ĳɹ���"<< this->m_EmpArray[index]->m_DeptId<<endl;

            //���浽�ļ���
            this->save();

        }else{
            cout<<"�޸�ʧ�ܣ����޴���"<<endl;
        }
    }
    //    ��������� ���� �ص��ϼ�Ŀ¼
    system("pause");//�������
    system("cls");//����
}


//13.2����ְ������ʵ��
//�����������ṩ���ֲ���ְ����ʽ��һ�ְ���ְ����ţ�һ�ְ���ְ������
//    ���ձ�ţ�ְ��������Ҫ��ʾ
//    ��������������Ҫ��ʾ������������Ϣ
void WorkerManager::Find_Emp(){
    if(this->m_FileIsEmpty){
        cout<<"�ļ������ڻ��¼Ϊ�գ�"<<endl;
    }else{
        cout<<"��������ҵķ�ʽ��"<<endl;
        cout<<"1������ְ����Ų���"<<endl;
        cout<<"2��������������"<<endl;

        int select = 0;//ѡ��
        cin>>select;

        if(select == 1) {//���ձ�Ų�
            int id = 0;
            cout<<"��������ҵ�ְ����ţ�"<<endl;
            cin>>id;

            int ret = IsExist(id);
            if(ret!=-1){//˵��ְ�����ڣ�����Ҫ�޸�indexλ���ϵ�ְ��
                cout<<"���ҳɹ�����ְ������Ϣ���£�"<<endl;
                this->m_EmpArray[ret]->showInfo();
            } else{
                cout<<"����ʧ�ܣ����޴���"<<endl;
            }
        } else if(select == 2) {//����������
            string name= "";
            cout<<"��������ҵ�������"<<endl;
            cin>>name;

            bool flag = false;//���ҵ��ı�־
            for(int i=0;i< this->m_EmpNum;i++){
                if(this->m_EmpArray[i]->m_Name == name){
                    cout<<"���ҳɹ�����ְ�����Ϊ��"
                    <<this->m_EmpArray[i]->m_Id
                    <<"����Ϣ���£�"<<endl;

                    flag = true;
                    //������ʾ��Ϣ�ӿ�
                    this->m_EmpArray[i]->showInfo();
                }
            }
            if(flag == false){
                cout<<"����ʧ�ܣ����޴���"<<endl;
            }
        }else{
            cout<<"����ѡ������"<<endl;
        }
    }
    //    ��������� ���� �ص��ϼ�Ŀ¼
    system("pause");//�������
    system("cls");//����
}

//14.2������ʵ��
void WorkerManager::Sort_Emp(){
    if(this->m_FileIsEmpty){
        cout<<"�ļ������ڻ��¼Ϊ�գ�"<<endl;
        //    ��������� ���� �ص��ϼ�Ŀ¼
        system("pause");//�������
        system("cls");//����
    }else{//�ļ����ڵ������
        cout<<"��ѡ������ʽ��"<<endl;
        cout<<"1����ְ���Ž�������"<<endl;
        cout<<"2����ְ���Ž��н���"<<endl;

        int select = 0;
        cin>>select;

//        for(int i=0;i< this->m_EmpNum;i++){
        for(int i=0;i< m_EmpNum;i++){
            int minOrMax = i;//��Сֵ��־ ������Сֵ �� ���ֵ�±�
            for(int j=i+1;j<m_EmpNum;j++){
                if(select ==1 ){//����
                    if(m_EmpArray[minOrMax]->m_Id>m_EmpArray[j]->m_Id)
                        minOrMax = j;
                }
                else{//����
                    if(m_EmpArray[minOrMax]->m_Id<m_EmpArray[j]->m_Id)
                        minOrMax = j;
                }
            }
//            �ж�һ��ʼ�϶� ��Сֵ�����ֵ �ǲ��� �������Сֵ�����ֵ��
//            ������� ��������
            if(i!=minOrMax){
                Worker *temp = m_EmpArray[i];
                m_EmpArray[i] = m_EmpArray[minOrMax];
                m_EmpArray[minOrMax] = temp;
            }
        }
        cout<<"����ɹ����������Ϊ��"<<endl;
        this->save();//����������浽�ļ���
        //չʾ����ְ��
        this->Show_Emp();// ����д��������
//        WorkerManager::Show_Emp();
    }
//    ��Ϊ��һ���Զ�ת����ʾ���� Show�ˣ��������ﲻ��Ҫ�ٴ�ˢ����Ļ
//    //    ��������� ���� �ص��ϼ�Ŀ¼
//    system("pause");//�������
//    system("cls");//����
}

//15.2��պ���ʵ��
//�������������ļ��м�¼�������
void WorkerManager::Clean_File(){
    cout<<"ȷ����գ�"<<endl;
    cout<<"1��ȷ��"<<endl;
    cout<<"2������"<<endl;

    int select = 0;
    cin>>select;

    if(select==1){
//        ����ļ�
//        ��ģʽios::trunc�������ɾ���ļ������´���
        ofstream ofs(FILENAME,ios::trunc);
        ofs.close();

        if(this->m_EmpArray!=NULL){
            //ɾ��������ÿ��ְ������
            for(int i=0;i< this->m_EmpNum;i++){
                if(this->m_EmpArray[i]!=NULL){
                    delete this->m_EmpArray[i];//�Ѷ���ά����ÿһ�������ͷŸɾ�
                }
            }
//            ɾ����������ָ��
            this->m_EmpNum = 0;//����Ϊ 0
            delete[] this->m_EmpArray;//��������������
            this->m_EmpArray = NULL;
            this->m_FileIsEmpty = true;//�ļ���־��Ϊ ��
        }
        cout<<"��ճɹ���"<<endl;
    }
//    else if(select==2){ }  //ֱ�ӷ�����������дҲ��
    system("pause");//�������
    system("cls");//����
}



//��������Ҫ�ͷŶ�������
WorkerManager::~WorkerManager() {
//    if(this->m_EmpArray != NULL){
//        delete[] this->m_EmpArray;
//        this->m_EmpArray = NULL;
//    }

//    �Ľ�  �ͷ�ÿһ��Ԫ��
    if(this->m_EmpArray != NULL) {
        for (int i = 0; i < this->m_EmpNum; i++) {
            if (this->m_EmpArray[i] != NULL) {
                delete this->m_EmpArray[i];//�Ѷ���ά����ÿһ�������ͷŸɾ�
            }
        }
        delete[] this->m_EmpArray;
        this->m_EmpArray = NULL;
    }
}