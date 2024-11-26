//
// Created by tianya on 2024/11/3.
//
#include "iostream"
using namespace std;
//#include"workerManager.h"
#include "02workerManager.cpp"// Clion中引用头文件貌似需要 .cpp 才行
#include "03worker.h"
//#include "04employee.h"
#include "04employee.cpp"
#include "05manager.cpp"
#include "06boss.cpp"// .h就不能运行

/*
    修改功能只修改单值
 */
void test(){
    //    测试代码
//    Worker * worker = NULL;
//    Employee ep;
//    ep.m_Id = 1;
//    ep.m_Name = "张三";
//    ep.m_DeptId = 1;
//    ep.showInfo();

//    抽象类不能实例化，只能创建指针
    Worker * worker = NULL;

    worker = new Employee(1,"张三",1);
    worker->showInfo();
    delete worker;

    worker = new Manager(2,"李四",2);
    worker->showInfo();
    delete worker;

    worker = new Boss(3,"王五",3);
    worker->showInfo();
    delete worker;
}

//职工管理系统
int main(){
//    test01();
//    test();

//    实化管理者对象
    WorkerManager wm;//创建一个管理类的对象
    int choice = 0;//选择

    while (true){
//    调用 展示菜单 成员函数   显示
        wm.Show_Menu();
        cout<<"请输入您的选择："<<endl;
        cin>>choice;//接受用户的选项

        switch (choice) {
            case 0://退出系统
                wm.Exitsystem();
                break;
            case 1://添加职工
                wm.Add_Emp();
                break;
            case 2://显示职工
                wm.Show_Emp();
                break;
            case 3://删除职工
                wm.Del_Emp();
                break;
//            {
//                //测试  输入 1 2 4显示职工存在，其他都是不存在
//                int ret = wm.IsExist(2);
//                if(ret!=-1){
//                    cout<<"职工存在"<<endl;
//                }else{
//                    cout<<"职工不存在"<<endl;
//                }
//                break;
//            }
            case 4://修改职工
                wm.Mod_Emp();
                break;
            case 5://查找职工
                wm.Find_Emp();
                break;
            case 6://排序职工
                wm.Sort_Emp();
                break;
            case 7://清空文件
                wm.Clean_File();
                break;
            default:
                system("cls");//刷新屏幕,清屏
                break;
        }
    }

    cout<<"HelloWorld"<<endl;
    return 0;
}
