//
// Created by tianya on 2024/11/21.
//

//#include "基于STL的演讲比赛流程管理系统.h"
#include "iostream"
using namespace std;
#include "ctime"
#include "02speechManager.cpp"

//测试创建12名选手
void test01(SpeechManager &sm){
    for(map<int,Speaker>::iterator it=sm.m_Speaker.begin();it!=sm.m_Speaker.end();it++){
        cout << "选手编号："<< it->first
             <<"姓名："<<it->second.m_Name
             <<"成绩："<<it->second.m_Score[0]<<endl;
    }
}
int main(){
//    随机数种子
    srand((unsigned int)time(NULL));

//    创建管理类对象
    SpeechManager sm;
//    test01(sm);//测试sm管理类对象 测试创建12名选手

    int choice=0;//用来存储用户的选项

    while(true) {
        sm.show_Menu();
        cout <<"请输入您的选择: "<< endl;
        cin >> choice;//接受用户的选项
        switch (choice) {
            case 1://开始比赛
                sm.startspeech();
                break;
            case 2://查看记录
//                sm.loadRecord();
                sm.showRecord();
                break;
            case 3://清空记录
                sm.clearRecord();
                break;
            case 0://退出系统
                sm.exitsystem();
                break;
            default:
                system("cls");//清屏
                break;
        }
    }

    system("pause");
//    cout<<"HelloWorld"<<endl;
    return 0;
}
