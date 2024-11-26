//
// Created by tianya on 2024/11/23.
//

#include "05manager.h"

//    默认构造
Manager::Manager(){

}

//    有参构造 参数：职工编号、姓名、密码
Manager::Manager(string name,string pwd){
//    初始化管理员信息
    this->m_Name = name;
    this->m_Pwd = pwd;//后期可以修改密码

//    初始化容器  获取到所有文件中学生、老师信息
    this->initVertor();


//    7.4.3初始化机房信息容器
    ifstream ifs;//文件
    ifs.open(COMPUTER_FILE,ios::in);

    ComputerRoom com;
    while (ifs>>com.m_ComId && ifs>>com.m_MaxNum){
        vCom.push_back(com);//插入对象
    }
    ifs.close();
    cout<<"机房的数量为："<<vCom.size()<<endl;


}

//    菜单界面  重写纯虚函数
void Manager::openMenu(){
    cout <<endl<<"欢迎管理员："<< this->m_Name<<"登录！"<<endl;
    cout << "\t\t ——————————————————————————— \n";
    cout << "\t\t|                           |\n";
    cout << "\t\t|         1.添加账号         |\n";
    cout << "\t\t|                           |\n";
    cout << "\t\t|         2.查看账号         |\n";
    cout << "\t\t|                           |\n";
    cout << "\t\t|         3.查看机房         |\n";
    cout << "\t\t|                           |\n";
    cout << "\t\t|         4.清空预约         |\n";
    cout << "\t\t|                           |\n";
    cout << "\t\t|         0.注销登录         |\n";
    cout << "\t\t|                           |\n";
    cout << "\t\t ——————————————————————————— \n";
    cout <<"输入您的选择：";
}

//    添加账号
void Manager::addPerson(){

    cout <<"请输入添加账号类型："<<endl;
    cout <<"1、学生"<<endl;
    cout <<"2、老师"<<endl;

    string filename;    //操作的文件名
    string tip;         //提示id号 学号还是职工号
    string errorTip;    //重复错误提示  字符串

    ofstream ofs;       //文件操作对象

    int select = 0;
//  接收用户选项
    cin>>select;

    if(select == 1){
//        添加的是学生
        filename = STUDENT_FILE;
        tip = "请输入学号：";
        errorTip = "学号重复，请重新输入";
    } else if(select == 2){
//        添加的是教师
        filename = TEACHER_FILE;
        tip = "请输入职工号：";
        errorTip = "职工号重复，请重新输入";
    } else {
        cout<<"输入错误，请重新输入！"<<endl;
        system("pause");//按任意键继续
        system("cls");//清屏
        return;
    }

//    利用追加的方式写文件
    ofs.open(filename,ios::out|ios::app);

    int id;     //学号或者职工号
    string name;
    string pwd;

    cout<<tip<<endl;//打印 请输入学号或者职工号
    while (true){
        cin>>id;//输入 学号或者职工号
        bool ret = checkRepeat(id,select);//id 和 用户类型
        if(ret){//有重复
            cout<<errorTip<<endl;//输出错误提示信息
        } else{//没有重复，说明输入正确，退出循环
            break;
        }
    }

//    cin>>id;//输入 学号或者职工号 放到上面while检测重复的循环中输入了

    cout<<"请输入姓名："<<endl;
    cin>>name;

    cout<<"请输入密码："<<endl;
    cin>>pwd;

//    向文件中添加数据
    ofs<<endl;
    ofs<<id<<" "<<name<<" "<<pwd<<" "<<endl;
    cout<<"添加成功！"<<endl;

    system("pause");//按任意键继续
    system("cls");//清屏

    ofs.close();//关闭文件

    //调用初始化容器接口，从新获取文件中的数据
    this->initVertor();//添加完初始化容器  解决连续添加查重失效问题 放开头也可以
}
void printStudent(Student &s){
    cout<<"学生号"<<s.m_Id
        <<" 姓名："<<s.m_Name
        <<" 密码："<<s.m_Pwd<<endl;
}
void printTeacher(Teacher &t){
    cout<<"职工编号"<<t.m_EmpId
        <<" 姓名："<<t.m_Name
        <<" 密码："<<t.m_Pwd<<endl;
}

//    查看账号
void Manager::showPerson(){
    cout<<"请选择查看内容："<<endl;
    cout<<"1、查看所有学生"<<endl;
    cout<<"2、查看所有老师"<<endl;

    int select = 0;//接受用户选择
    static int count;//输错次数超过三次，也要跳出循环
    while (true) {
        cin>>select;
        if (select == 1) {
            cout<<"所有学生的信息如下："<<endl;
            for_each(vStu.begin(), vStu.end(), printStudent);//最后一个参数 遍历打印函数
            break;
        } else if (select == 2) {
            cout<<"所有教师的信息如下："<<endl;
            for_each(vTea.begin(), vTea.end(), printTeacher);
            break;
        } else {
            cout << "输入错误，请重新输入！" << endl;//直到输入正确，才能跳出循环
            count++;
            if(count == 3){
                cout << "输入错误次数过多，请重新登录！" << endl;//想办法退出系统
//                system("pause");//按任意键继续  暂无效果
//                system("cls");//清屏
                break;
            }
        }
    }
    system("pause");//按任意键继续
    system("cls");//清屏
}

//    查看机房信息
void Manager::showComputer(){
    cout << "机房信息如下：" << endl;
    for(vector<ComputerRoom>::iterator it=vCom.begin();it!=vCom.end();it++){
        cout << "机房编号：" <<it->m_ComId
             << " 机房最大容量：" <<it->m_MaxNum<<endl;
    }
    system("pause");//按任意键继续
    system("cls");//清屏
}

//    清空预约记录  暂不做清空判断
void Manager::cleanFile(){
//    删除文件再重新创建，达到清空的效果
    ofstream ofs(ORDER_FILE,ios::trunc);
    ofs.close();

    cout << "清空成功！" << endl;
    system("pause");//按任意键继续
    system("cls");//清屏
}

//    7.2.2去重操作
//    初始化容器
void Manager::initVertor(){

//    确保容器清空状态  初始化容器
    vStu.clear();
    vTea.clear();

//    读取信息 学生
    ifstream ifs;
    ifs.open(STUDENT_FILE,ios::in);
    if(!ifs.is_open()){
        cout<<"文件读取失败"<<endl;
        return;
    }

    Student s;//创建实例化对象
//    从文件中读取数据
    while (ifs>>s.m_Id && ifs>>s.m_Name && ifs>>s.m_Pwd){
        vStu.push_back(s);//一行行插入数据
    }
    cout<<"当前学生数量为："<<vStu.size()<<endl;//登录管理员后，点继续可以看到学生和老师人数
    ifs.close();


//    读取信息 老师
    ifs.open(TEACHER_FILE,ios::in);
    if(!ifs.is_open()){
        cout<<"文件读取失败"<<endl;
        return;
    }

    Teacher t;//创建实例化对象
//    从文件中读取数据
    while (ifs>>t.m_EmpId && ifs>>t.m_Name && ifs>>t.m_Pwd){
        vTea.push_back(t);//一行行插入数据
    }
    cout<<"当前教师数量为："<<vTea.size()<<endl;
    ifs.close();

}


//    7.2.2.2去重函数封装
//    参数1 检测学号/职工号   参数2  检测类型
//    检测重复参数：（传入id,传入类型）返回值：(true代表有重复，false代表没有重复)
bool Manager::checkRepeat(int id,int type){

    if(type == 1){
        //检测学生
        for(vector<Student>::iterator it=vStu.begin();it!=vStu.end();it++){
            if(id == it->m_Id){
                return true;
            }
        }
    } else if(type == 2){
        //检测老师
        for(vector<Teacher>::iterator it=vTea.begin();it!=vTea.end();it++){
            if(id == it->m_EmpId){
                return true;
            }
        }
    }

    return false;//没有重复，返回假
}