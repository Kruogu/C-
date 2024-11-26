//
// Created by tianya on 2024/11/23.
//
#include "iostream"
using namespace std;
#include "fstream"      //文件库
#include "02Identity.cpp"  //身份基类
#include "03student.cpp"
#include "04teacher.cpp"
#include "05manager.cpp"
#include "06globalfile.h"//全局文件
//机房预约系统


//全局函数
//8.1学生登录和注销
void StudentMenu(Identity * &student){
    while (true){
        //调用学生字菜单
        student->openMenu();

//        将父类指针 强转为 子类指针，调用子类里其他接口
        Student *stu =(Student*)student;

        int select = 0;

//        接收用户选项
        cin>>select;
        if(select == 1){//申请预约
//            cout<<"申请预约"<<endl;
            stu->applyOrder();
        } else if(select == 2){//查看自身预约
//            cout<<"查看自身预约"<<endl;
            stu->showMyOerder();
        } else if(select == 3){//查看所有预约
//            cout<<"查看所有预约"<<endl;
            stu->showAllOrer();
        } else if(select == 4){//取消预约
//            cout<<"取消预约"<<endl;
            stu->cancelOrder();
        } else{//选错了 或者 默认注销登录
//            注销
            delete student;//销毁掉堆区对象
            cout<<"注销成功！"<<endl;
            system("pause");//按任意键继续
            system("cls");//清屏
            return;
        }
    }
}

//全局函数
//7.1.2教师子菜单界面
void TeacherMenu(Identity * &teacherr){
    while (true){
        //调用教师字菜单
        teacherr->openMenu();

//        将父类指针 强转为 子类指针，调用子类里其他接口
        Teacher *tea =(Teacher*)teacherr;

        int select = 0;

//        接收用户选项
        cin>>select;
        if(select == 1){//查看所有预约
//            cout<<"查看所有预约"<<endl;
            tea->showAllOrer();
        } else if(select == 2){//审核预约
//            cout<<"审核预约"<<endl;
            tea->validOrder();
        } else{//选错了 或者 默认注销登录
//            注销
            delete teacherr;//销毁掉堆区对象
            cout<<"注销成功！"<<endl;
            system("pause");//按任意键继续
            system("cls");//清屏
            return;
        }
    }
}

//全局函数
//7.1.2管理员子菜单界面
void mangerMenu(Identity * &manager){
    while (true){
//        调用管理员子菜单  父类指针创建子类对象调用共同接口  重写纯虚函数
        manager->openMenu();

//        将父类指针 强转为 子类指针，调用子类里其他接口
            Manager* man = (Manager*) manager;

            int select = 0;

//        接收用户选项
        cin>>select;
        if(select == 1){//添加账号
//            cout<<"添加账号"<<endl;
            man->addPerson();
        } else if(select == 2){//查看账号
//            cout<<"查看账号"<<endl;
            man->showPerson();
        } else if(select == 3){//查看机房信息
//            cout<<"查看机房"<<endl;
            man->showComputer();
        } else if(select == 4){//清空预约
//            cout<<"清空预约"<<endl;
            man->cleanFile();
        } else{//选错了 或者 默认注销登录
//            注销
            delete manager;//销毁掉堆区对象
            cout<<"注销成功！"<<endl;
            system("pause");//按任意键继续
            system("cls");//清屏
            return;
        }
    }
}

//全局函数
//6.2登录函数封装 参数1  操作文件名   参数2  操作身份类型
void LoginIn(string fileName,int type){

//    父类指针指向子类对象
    Identity *person = NULL;

//    读文件
    ifstream ifs;
    ifs.open(fileName,ios::in);//传进来什么文件，就读什么文件

//    判断文件是否存在
    if(!ifs.is_open()){
        cout<<"文件不存在！"<<endl;
        ifs.close();
        return;
    }

//    准备接收用户信息
    int id = 0;
    string name;
    string pwd;

//    判断身份
    if(type == 1)//学生身份
    {
        cout<<"请输入您的学号"<<endl;
        cin>>id;
    }else if(type == 2)//教师身份
    {
        cout<<"请输入您的职工编号"<<endl;
        cin>>id;
    }

    cout<<"请输入用户名："<<endl;
    cin>>name;

    cout<<"请输入密码："<<endl;
    cin>>pwd;

    if(type==1){
        //学生身份验证
        int fId;        //从文件中读取的id号
        string fName;   //从文件中获取的姓名
        string fPwd;    //从文件中获取密码
//        暂时不能读取汉字，张三，只能读取 zhangsan ，否则会导致乱码，用写字板打开修改汉字乱码也可以
//        在简体txt中，ANS1编码就是GB2312编码，改成ANSI就好，用记事本打开，另存为，格式选择ANSI就正常了
        while (ifs>>fId && ifs>>fName && ifs>>fPwd){//读到空格自动换下一个
//            测试读取文件输入信息
//            {
//                cout<<fId<<endl;
//                cout<<fName<<endl;
//                cout<<fPwd<<endl;
//                cout<<endl;
//            }

//            与用户输入的信息做对比
            if(id==fId && name==fName && pwd==fPwd){
                cout<<"学生验证登录成功！"<<endl;
                system("pause");//按任意键继续
                system("cls");//清屏

                //这里person报错找了半天，原来 pwd 是 string类型的，
                // 在Student类中有参构造声明写成了int，改成string就好了
                person = new Student(id,name,pwd);
//                进入学生身份的子菜单
                StudentMenu(person);

                return;
            }
        }
    }
    else if(type==2){
        //教师身份验证
        int fId;        //从文件中读取的id号
        string fName;   //从文件中获取的姓名
        string fPwd;    //从文件中获取密码
        while (ifs>>fId && ifs>>fName && ifs>>fPwd){//读到空格自动换下一个

//            与用户输入的信息做对比
            if(id==fId && name==fName && pwd==fPwd){
                cout<<"教师验证登录成功！"<<endl;
                system("pause");//按任意键继续
                system("cls");//清屏

                person = new Teacher(id,name,pwd);
//                进入教师身份的子菜单
                TeacherMenu(person);
                return;
            }
        }
    }
    else if(type==3){
        //管理员身份验证
        string fName;   //从文件中获取的姓名
        string fPwd;    //从文件中获取密码
        while (ifs>>fName && ifs>>fPwd) {//读到空格自动换下一个

//            与用户输入的信息做对比
            if(name==fName && pwd==fPwd) {
                cout << "管理员验证登录成功！" << endl;
                //登录成功后，按任意键进入管理员界面
                system("pause");//按任意键继续
                system("cls");//清屏

//                创建管理员对象
                person = new Manager(name, pwd);//管理员就 1 个，没有ID
//                进入管理员身份的子菜单
                mangerMenu(person);

                return;
            }
        }
    }

    cout<<"验证登录失败！"<<endl;
    system("pause");//按任意键继续
    system("cls");//清屏
}
int main(){

    int select = 0;
    while (true){
        cout << "===================== 欢迎来到机房预约系统 ====================="<<endl;
        cout <<endl<<"请输入您的身份"<<endl;
        cout << "\t\t ——————————————————————————— \n";
        cout << "\t\t|                           |\n";
        cout << "\t\t|         1.学生代表         |\n";
        cout << "\t\t|                           |\n";
        cout << "\t\t|         2.老   师          |\n";
        cout << "\t\t|                           |\n";
        cout << "\t\t|         3.管 理 员         |\n";
        cout << "\t\t|                           |\n";
        cout << "\t\t|         0.退   出          |\n";
        cout << "\t\t|                           |\n";
        cout << "\t\t ——————————————————————————— \n";
        cout <<"输入您的选择：";

        cin>>select;    //接收用户选择

        switch(select)//根据用户选择 实现不同接口
        {
            case 1:     //学生身份
                LoginIn(STUDENT_FILE,1);
                break;
            case 2:     //老师身份
                LoginIn(TEACHER_FILE,2);
                break;
            case 3:     //管理员身份
                LoginIn(ADMIN_FILE,3);
                break;
            case 0:     //退出系统
                cout <<"欢迎下一次使用"<<endl;
                system("pause");
                return 0;
                break;
            default:
                cout <<"输入有误，请重新选择！"<<endl;
                system("pause");
                system("cls");
                break;
        }

    }

    cout<<"HelloWorld"<<endl;
    return 0;
}

