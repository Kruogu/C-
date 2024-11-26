//
// Created by tianya on 2024/11/21.
//

#ifndef INC_24_11_21_02SPEECHMANAGER_H
#define INC_24_11_21_02SPEECHMANAGER_H

#pragma once//防止头文件重复包含
#include "iostream"
using namespace std;
#include "vector"       //容器
#include "map"          //对组容器
#include "algorithm"    //sort排序算法  洗牌
#include "deque"        //双端容器
#include "functional"   //greater 降序
#include "numeric"      //accumulate累加
#include "fstream"      //文件操作
#include "03speaker.h"
#define FILENAME "speech.csv"//指定文件目录和文件名

//设计演讲管理类
class SpeechManager{
public:
    //构造函数
    SpeechManager();

//    4、菜单功能
    void show_Menu();

//    5、退出功能
    void exitsystem();

//    6.3.2初始化属性
    void initspeech();

//    6.3.3创建选手   初始化创建12名选手
    void createSpeaker();

//    6.3.4开始比赛成员函数添加
    //开始比赛-比赛流程控制   比赛整个流程的控制函数
    void startspeech();

//    6.3.5抽签
    void speechDraw();

//    6.3.6开始比赛
    void speechContest();  //Contest  比赛，竞争

//    6.3.7显示比赛分数  比赛结果
    void showScore();

//    6.4保存分数   保存记录
    void saveRecord();

//    7.1读取记录分数
    void loadRecord();

//    7.2查看记录功能  显示往届记录
    void showRecord();
//    判断文件是否为空
    bool fileIsEmpty;

//    存放往届记录的容器
    map<int,vector<string >>m_Record;

//    8.1清空记录功能
    void clearRecord();
//    析构函数
    ~SpeechManager();




//    6.3.1成员属性添加
//比赛选手容器12人
    vector<int>v1;

//第一轮晋级容器6人
    vector<int>v2;

//胜利前三名容器3人
    vector<int>vVictory;

//存放编号以及对应的具体选手容器
    map<int,Speaker>m_Speaker;

//记录比赛轮数
    int m_Index;
};

#endif //INC_24_11_21基于STL的演讲比赛流程管理系统_02SPEECHMANAGER_H
