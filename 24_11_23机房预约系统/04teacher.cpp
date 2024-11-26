//
// Created by tianya on 2024/11/23.
//

#include "04teacher.h"

//    默认构造
Teacher::Teacher(){

}

//    有参构造 参数：学号、姓名、密码
Teacher::Teacher(int empId,string name,string pwd){
    //    初始化教师信息 属性
    this->m_EmpId = empId;
    this->m_Name = name;
    this->m_Pwd = pwd;//后期可以修改密码
}

//    菜单界面  重写纯虚函数
void Teacher::openMenu(){
    cout <<endl<<"欢迎教师："<< this->m_Name<<"登录！"<<endl;
    cout << "\t\t ——————————————————————————— \n";
    cout << "\t\t|                           |\n";
    cout << "\t\t|         1.查看所有预约      |\n";
    cout << "\t\t|                           |\n";
    cout << "\t\t|         2.审核预约         |\n";
    cout << "\t\t|                           |\n";
    cout << "\t\t|         0.注销登录         |\n";
    cout << "\t\t|                           |\n";
    cout << "\t\t ——————————————————————————— \n";
    cout <<"输入您的选择：";
}


//    查看所有预约
void Teacher::showAllOrer(){
    OrderFile of;
    if(of.m_Size == 0){
        cout<<"无预约记录"<<endl;
        system("pause");//按任意键继续
        system("cls");//清屏
        return;
    }

    for (int i = 0; i < of.m_Size; ++i) {
        cout<<i+1<<"、";
        cout<<"预约日期：周"<<of.m_orderData[i]["date"];
        cout<<" 时间段："<<(of.m_orderData[i]["interval"]=="1"?"上午":"下午");
        cout<<" 姓名："<<of.m_orderData[i]["stuName"];
        cout<<" 学号："<<of.m_orderData[i]["stuId"];
        cout<<" 机房编号："<<of.m_orderData[i]["roomId"];

        string status = " 状态：";//1审核中  2成功预约 -1预约失败 0取消预约
        if(of.m_orderData[i]["status"] == "1"){
            status += "审核中";
        } else if(of.m_orderData[i]["status"] == "2"){
            status += "成功预约";
        } else if(of.m_orderData[i]["status"] == "-1"){
            status += "预约失败,审核未通过";
        } else if(of.m_orderData[i]["status"] == "0"){
            status += "预约已取消";
        }
        cout<<status<<endl;
    }
    system("pause");//按任意键继续
    system("cls");//清屏
}

//    审核预约
void Teacher::validOrder(){
    OrderFile of;
//    Student *st = new Student;//这行不要，老师不需要判断，可以取消所有人
    if(of.m_Size == 0){
        cout<<"无预约记录"<<endl;
        system("pause");//按任意键继续
        system("cls");//清屏
        return;
    }
    cout<<"待审核的预约记录如下："<<endl;

    vector<int>v;//存放在最大容器中的下标编号
    int index = 1;//如果是 0 的话，下面就前置 ++index 效果一样
    for (int i = 0; i < of.m_Size; ++i) {
//        先判断是自身的学号
//        if(st->m_Id == atoi(of.m_orderData[i]["stuId"].c_str())){//这行不要，老师不需要判断，可以取消所有人

        //筛选状态，只有审核中状态1才能修改，已经成功预约2和取消预约3，还有预约失败-1的都不能修改
            if(of.m_orderData[i]["status"] == "1" ){

                v.push_back(i);
                cout<<index++<<"、";
                cout<<"预约日期：周"<<of.m_orderData[i]["date"];
                cout<<" 时间段："<<(of.m_orderData[i]["interval"]=="1"?"上午":"下午");
                cout<<" 学号："<<of.m_orderData[i]["stuId"];
                cout<<" 姓名："<<of.m_orderData[i]["stuName"];
                cout<<" 机房编号："<<of.m_orderData[i]["roomId"];

                string status = " 状态：";//1审核中  2成功预约 -1预约失败 0取消预约
                if(of.m_orderData[i]["status"] == "1"){
                    status += "审核中";
                }
//                else if(of.m_orderData[i]["status"] == "2"){     //下面三种状态都不需要
//                    status += "成功预约";
//                }else if(of.m_orderData[i]["status"] == "-1"){
//                    status += "预约失败,审核未通过";
//                } else if(of.m_orderData[i]["status"] == "0"){1
//                    status += "预约已取消";
//                }
                cout<<status<<endl;
            }
//        }
    }

    //index没有++，说明上面的for循环没有进入  也就是没有满足条件的预约记录，审核为空，直接退出到上一级
    if(index == 1){
        cout<<"暂无待审核记录！"<<endl;
        system("pause");//按任意键继续
        system("cls");//清屏
        return;
    }
    cout<<"请输入审核的预约记录，0代表返回"<<endl;//没有1这个选项
    int select = 0;
    int ret = 0;
    while (true){
        cin>>select;    //输入选择
        if(select>=0 && select<=v.size()){//3
            if(select == 0){//返回
                break;
            } else{//要审核的记录
                cout<<"请输入审核结果："<<endl;
                cout<<"1、通过"<<endl;
                cout<<"2、不通过"<<endl;
                cin>>ret;

                while (true){//1审核中  2成功预约 -1预约失败 0取消预约
                    if(ret==1){
                        of.m_orderData[v[select-1]]["status"] = "2";//通过  2成功预约
                        break;
                    }else if(ret==2){
                        of.m_orderData[v[select-1]]["status"] = "-1";//不通过  -1预约失败
                        break;
                    }
                    cout<<"输入有误，请重新输入！"<<endl;
                }

                of.updateOrder();   //更新文件
                cout<<"审核完毕！"<<endl;
                break;
            }
        }
        cout<<"输入有误，请重新输入！"<<endl;
    }
    system("pause");//按任意键继续
    system("cls");//清屏
}
