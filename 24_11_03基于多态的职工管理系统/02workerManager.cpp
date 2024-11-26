//
// Created by tianya on 2024/11/3.
//

#include "02workerManager.h"


//在workerManager.cpp中将构造和析构函数空实现补全
WorkerManager::WorkerManager(){
//    7.2添加物职工功能实现  初始化属性  注释掉加入下面文件判断内
//    this->m_EmpNum = 0;//职工数初始为 0
//    this->m_EmpArray = NULL;

//    9.1文件未创建  分三种情况 初始化属性
    ifstream ifs;//读文件
    ifs.open(FILENAME,ios::in);

//    文件不存在情况
    if(!ifs.is_open()){
        cout<<"文件不存在"<<endl;//测试输出
//        初始化属性
        this->m_EmpNum = 0;//初始化人数
        this->m_EmpArray = NULL;//初始化数组
        this->m_FileIsEmpty = true;//初始化文件为空标志
        ifs.close();//关闭文件
        return;
    }

//  9.2文件存在且数据为空   文件存在，并且没有记录
//  测试就是把文件中的数据删除干净
    char ch;
    ifs>>ch;//文件流对象  读 字符
    if(ifs.eof()){//文件为空，代表读完了
        cout<<"文件为空！"<<endl;//测试输出
        this->m_EmpNum = 0;//初始化人数
        this->m_EmpArray = NULL;//初始化数组
        this->m_FileIsEmpty = true;//初始化文件为空标志
        ifs.close();//关闭文件
        return;
    }

//    9.3文件存在 且 保存职工数据
    int num = this->get_EmpNum();
    cout<<"职工人数为："<<num<<endl;
    this->m_EmpNum = num;//成员属性更新数据

//    9.3.2初始化数组 测试
    //开辟空间
    this->m_EmpArray = new Worker * [this->m_EmpNum];
//    将文件中的数据，存到数组中
    this->init_Emp();
//    if(num){// 刚删除完职工后  调用显示函数遗漏  需要继续做优化
        this->m_FileIsEmpty = false;//初始化文件为真标志！！！
//    }

    //测试代码 可以注释掉
//    for(int i=0;i< this->m_EmpNum;i++){
//        cout<<"职工编号："<< this->m_EmpArray[i]->m_Id
//        <<" 姓名："<< this->m_EmpArray[i]->m_Name
//        <<" 部门编号："<< this->m_EmpArray[i]->m_DeptId<<endl;//显示数字
////        <<" 部门编号："<< this->m_EmpArray[i]->getDeptName()<<endl;//直接显示汉字
//    }

}

void test01(){
    cout<<"哈哈哈111"<<endl;
}

//4.2菜单功能实现   实现显示
void WorkerManager::Show_Menu() {
    cout<<"**************************"<<endl;
    cout<<"***  欢迎使用职工管理系统  ***"<<endl;
    cout<<"*****  0.退出管理程序  *****"<<endl;
    cout<<"*****  1.添加职工信息  *****"<<endl;
    cout<<"*****  2.显示职工信息  *****"<<endl;
    cout<<"*****  3.删除离职职工  *****"<<endl;
    cout<<"*****  4.修改职工信息  *****"<<endl;
    cout<<"*****  5.查找职工信息  *****"<<endl;
    cout<<"*****  6.按照编号排序  *****"<<endl;
    cout<<"*****  7.清空所有文档  *****"<<endl;
    cout<<"**************************"<<endl;
    cout<<endl;
}


//5.2实现退出功能
void WorkerManager::Exitsystem() {
    cout<<"欢迎下次使用"<<endl;
    system("pause");//刷新屏幕
    exit(0);//只要调用这个函数，程序就退出
}

//7.2添加物职工功能实现
void WorkerManager::Add_Emp(){
    cout<<"请输入添加职工数量"<<endl;

    int addNum = 0;//保存用户输入数量
    cin>>addNum;

    if(addNum>0){
//        添加

//        计算添加新的空间大小
        int newSize = this->m_EmpNum+addNum;//新空间人数 = 原来记录人数 + 新增人数

//      在 堆区 开辟新空间
        Worker ** newSpace = new Worker*[newSize];//重要！！！

        //将原来空间下数据，拷贝到新空间下
        if(this->m_EmpArray != NULL){
            for(int i=0;i< this->m_EmpNum;i++){
                newSpace[i] = this->m_EmpArray[i];
            }
        }

//        批量添加新数据
        for(int i=0;i<addNum;i++){
            int id;//职工编号
            string name;//职工姓名
            int dSelect;//部门选择

            cout<<"请输入第 "<<i+1<<"个新职工的编号："<<endl;
            cin>>id;

            cout<<"请输入第 "<<i+1<<"个新职工的姓名："<<endl;
            cin>>name;

            cout<<"请选择该职工岗位："<<endl;
            cout<<"1、普通职工"<<endl;
            cout<<"2、经理"<<endl;
            cout<<"3、总裁"<<endl;
            cin>>dSelect;

             Worker * worker = NULL;//创建 worker 前先 指向 空
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

//            将创建职工职责，保存到数组中
            newSpace[this->m_EmpNum+i] = worker;
        }

//        释放原有空间
        delete[] this->m_EmpArray;//重要！！！

//        更改新空间的指向
        this->m_EmpArray = newSpace;

//        更新新的职工人数
        this->m_EmpNum = newSize;

//        9.2 更新职工不为空标志
        this->m_FileIsEmpty = false;

        //提示添加成功
        cout<<"成功添加"<<addNum<<"名新职工"<<endl;

        //8.1成功添加后 保存到文件中
        this->save();//报错是因为没有用 ->
    }else{
        cout<<"输入数据有误"<<endl;
    }

//    按任意键后 清屏 回到上级目录
    system("pause");//按任意键
    system("cls");//清屏
}

//8.3保存文件功能实现
void WorkerManager::save(){
    ofstream ofs;
    ofs.open(FILENAME,ios::out);//用输出的方式打开文件 一 写文件

//    将每个人数据写入到文件中
    for(int i=0;i<this->m_EmpNum;i++){
        ofs<<this->m_EmpArray[i]->m_Id<<" "
            <<this->m_EmpArray[i]->m_Name<<" "
            << this->m_EmpArray[i]->m_DeptId<< endl;
    }
//    关闭文件
    ofs.close();
}

//9.3统计文件中人数
int WorkerManager::get_EmpNum(){
    ifstream ifs;
    ifs.open(FILENAME,ios::in);//打开文件 读

    int id;
    string name;
    int dId;

    int num = 0;
//    ifs<<读到空格时会自动结束
    while (ifs>>id && ifs>>name && ifs>>dId){
        //统计人数变量
        num++;
    }
    return num;
}

//9.3.2初始化数组
void WorkerManager::init_Emp(){
    ifstream ifs;
    ifs.open(FILENAME,ios::in);//打开文件 读

    int id;
    string name;
    int dId;

    int index = 0;
    while (ifs>>id && ifs>>name && ifs>>dId){
        Worker * worker = NULL;

//        根据不同部门的Id创建不同对象
        if(dId==1)// 1普通员工
        {
            worker = new Employee(id,name,dId);
        }
        else if(dId==2)// 2经理
        {
            worker = new Manager(id,name,dId);
        }
//        else(dId==3)// 3总裁  报错，这里不能写序号了
        else
        {
            worker = new Boss(id,name,dId);
        }

//        存放在数组中
        this->m_EmpArray[index] = worker;
        index++;
    }

    //关闭文件
    ifs.close();
}

//10.2显示职工函数实现
void WorkerManager::Show_Emp(){
//    判断文件是否为空  不存在就是true 存在就是false
    if(this->m_FileIsEmpty) {//m_FileIsEmpty就是一个布尔变量
        cout<<"文件不存在或记录为空！"<<endl;
    }
    else{
        for(int i=0;i<m_EmpNum;i++){
            //利用多态调用程序接口
            this->m_EmpArray[i]->showInfo();
        }
    }
    //    按任意键后 清屏 回到上级目录
    system("pause");//按任意键
    system("cls");//清屏
}

//11.3职工是否存在函数实现
//按照职工编号判断职工是否存在，若存在返回职工在数组中位置，不存在返回-1
int WorkerManager::IsExist(int id) {
    int index = -1;

    for(int i=0;i< this->m_EmpNum;i++){
        if(this->m_EmpArray[i]->m_Id == id){
            //找到职工
            index = i;
            break;
        }
    }
    return index;
}

//11.4删除职工函数实现  数组中删除 本质就是数据前移
void WorkerManager::Del_Emp() {
    if(this->m_FileIsEmpty){
        cout<<"文件不存在或记录为空！"<<endl;
    }else{
        //按照职工编号删除
        cout<<"请输入想要删除的职工编号："<<endl;
        int id = 0;
        cin >> id;

        int index = this->IsExist(id);// -1就是不存在

        if(index != -1){//说明职工存在，并且要删除掉index位置上的职工
//            数据前移
            for(int i=index;i< this->m_EmpNum-1;i++){
                this->m_EmpArray[i]= this->m_EmpArray[i+1];
            }
            this->m_EmpNum--;//更新数组中记录人员个数

            if(m_EmpNum==0){
                this->m_FileIsEmpty = true;//更新文件为空  可能有优化的写法
            }
            //数据同步更新到文件中
            this->save();

            cout<<"删除成功!"<<endl;
        }else{
            cout<<"删除失败，未找到该职工"<<endl;
        }
    }
    //    按任意键后 清屏 回到上级目录
    system("pause");//按任意键
    system("cls");//清屏
}

//12.2修改职工函数实现
void WorkerManager::Mod_Emp(){
    if(this->m_FileIsEmpty){
        cout<<"文件不存在或记录为空！"<<endl;
    }else{
        //按照职工编号修改
        cout<<"请输入想要修改的职工编号："<<endl;
        int id = 0;
        cin >> id;

        int index = this->IsExist(id);// -1就是不存在  写成ret也行，都一样

        if(index != -1) {//说明职工存在，并且要修改index位置上的职工
            //查找到编号的职工
            delete this->m_EmpArray[index];
            int newId = 0;
            string newName = "";//默认空字符串
            int dSelect = 0;

            cout<<"查到："<<id<<"号职工，请输入新职工号："<<endl;
            cin>>newId;

            cout<<"请输入新姓名："<<endl;
            cin>>newName;

            cout<<"请输入岗位："<<endl;
            cout<<"1、普通职工"<<endl;
            cout<<"2、经理"<<endl;
            cout<<"3、总裁"<<endl;
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

            //更新 更改数据到数组中
            this->m_EmpArray[index] = worker;

            cout<<"修改成功！"<< this->m_EmpArray[index]->m_DeptId<<endl;

            //保存到文件中
            this->save();

        }else{
            cout<<"修改失败，查无此人"<<endl;
        }
    }
    //    按任意键后 清屏 回到上级目录
    system("pause");//按任意键
    system("cls");//清屏
}


//13.2查找职工函数实现
//功能描述：提供两种查找职工方式，一种按照职工编号，一种按照职工姓名
//    按照编号，职工不存在要提示
//    按照姓名，重名要显示所有重名的信息
void WorkerManager::Find_Emp(){
    if(this->m_FileIsEmpty){
        cout<<"文件不存在或记录为空！"<<endl;
    }else{
        cout<<"请输入查找的方式："<<endl;
        cout<<"1、按照职工编号查找"<<endl;
        cout<<"2、按照姓名查找"<<endl;

        int select = 0;//选项
        cin>>select;

        if(select == 1) {//按照编号查
            int id = 0;
            cout<<"请输入查找的职工编号："<<endl;
            cin>>id;

            int ret = IsExist(id);
            if(ret!=-1){//说明职工存在，并且要修改index位置上的职工
                cout<<"查找成功，该职工的信息如下："<<endl;
                this->m_EmpArray[ret]->showInfo();
            } else{
                cout<<"查找失败，查无此人"<<endl;
            }
        } else if(select == 2) {//按照姓名查
            string name= "";
            cout<<"请输入查找的姓名："<<endl;
            cin>>name;

            bool flag = false;//查找到的标志
            for(int i=0;i< this->m_EmpNum;i++){
                if(this->m_EmpArray[i]->m_Name == name){
                    cout<<"查找成功，该职工编号为："
                    <<this->m_EmpArray[i]->m_Id
                    <<"的信息如下："<<endl;

                    flag = true;
                    //调用显示信息接口
                    this->m_EmpArray[i]->showInfo();
                }
            }
            if(flag == false){
                cout<<"查找失败，查无此人"<<endl;
            }
        }else{
            cout<<"输入选项有误！"<<endl;
        }
    }
    //    按任意键后 清屏 回到上级目录
    system("pause");//按任意键
    system("cls");//清屏
}

//14.2排序函数实现
void WorkerManager::Sort_Emp(){
    if(this->m_FileIsEmpty){
        cout<<"文件不存在或记录为空！"<<endl;
        //    按任意键后 清屏 回到上级目录
        system("pause");//按任意键
        system("cls");//清屏
    }else{//文件存在的情况下
        cout<<"请选择排序方式："<<endl;
        cout<<"1、按职工号进行升序"<<endl;
        cout<<"2、按职工号进行降序"<<endl;

        int select = 0;
        cin>>select;

//        for(int i=0;i< this->m_EmpNum;i++){
        for(int i=0;i< m_EmpNum;i++){
            int minOrMax = i;//最小值标志 声明最小值 或 最大值下标
            for(int j=i+1;j<m_EmpNum;j++){
                if(select ==1 ){//升序
                    if(m_EmpArray[minOrMax]->m_Id>m_EmpArray[j]->m_Id)
                        minOrMax = j;
                }
                else{//降序
                    if(m_EmpArray[minOrMax]->m_Id<m_EmpArray[j]->m_Id)
                        minOrMax = j;
                }
            }
//            判断一开始认定 最小值或最大值 是不是 计算的最小值或最大值，
//            如果不是 交换数据
            if(i!=minOrMax){
                Worker *temp = m_EmpArray[i];
                m_EmpArray[i] = m_EmpArray[minOrMax];
                m_EmpArray[minOrMax] = temp;
            }
        }
        cout<<"排序成功，排序后结果为："<<endl;
        this->save();//排序后结果保存到文件中
        //展示所有职工
        this->Show_Emp();// 两种写法都可以
//        WorkerManager::Show_Emp();
    }
//    因为上一步自动转到显示函数 Show了，所以这里不需要再次刷新屏幕
//    //    按任意键后 清屏 回到上级目录
//    system("pause");//按任意键
//    system("cls");//清屏
}

//15.2清空函数实现
//功能描述：将文件中记录数据清空
void WorkerManager::Clean_File(){
    cout<<"确认清空？"<<endl;
    cout<<"1、确认"<<endl;
    cout<<"2、返回"<<endl;

    int select = 0;
    cin>>select;

    if(select==1){
//        清空文件
//        打开模式ios::trunc如果存在删除文件并重新创建
        ofstream ofs(FILENAME,ios::trunc);
        ofs.close();

        if(this->m_EmpArray!=NULL){
            //删除堆区的每个职工对象
            for(int i=0;i< this->m_EmpNum;i++){
                if(this->m_EmpArray[i]!=NULL){
                    delete this->m_EmpArray[i];//把堆区维护的每一个对象都释放干净
                }
            }
//            删除堆区数组指针
            this->m_EmpNum = 0;//人数为 0
            delete[] this->m_EmpArray;//最后清空整个数组
            this->m_EmpArray = NULL;
            this->m_FileIsEmpty = true;//文件标志改为 空
        }
        cout<<"清空成功！"<<endl;
    }
//    else if(select==2){ }  //直接返回跳过，不写也行
    system("pause");//按任意键
    system("cls");//清屏
}



//析构函数要释放堆区数据
WorkerManager::~WorkerManager() {
//    if(this->m_EmpArray != NULL){
//        delete[] this->m_EmpArray;
//        this->m_EmpArray = NULL;
//    }

//    改进  释放每一个元素
    if(this->m_EmpArray != NULL) {
        for (int i = 0; i < this->m_EmpNum; i++) {
            if (this->m_EmpArray[i] != NULL) {
                delete this->m_EmpArray[i];//把堆区维护的每一个对象都释放干净
            }
        }
        delete[] this->m_EmpArray;
        this->m_EmpArray = NULL;
    }
}