//
// Created by tianya on 2024/11/21.
//

#ifndef INC_24_11_21_02SPEECHMANAGER_H
#define INC_24_11_21_02SPEECHMANAGER_H

#pragma once//��ֹͷ�ļ��ظ�����
#include "iostream"
using namespace std;
#include "vector"       //����
#include "map"          //��������
#include "algorithm"    //sort�����㷨  ϴ��
#include "deque"        //˫������
#include "functional"   //greater ����
#include "numeric"      //accumulate�ۼ�
#include "fstream"      //�ļ�����
#include "03speaker.h"
#define FILENAME "speech.csv"//ָ���ļ�Ŀ¼���ļ���

//����ݽ�������
class SpeechManager{
public:
    //���캯��
    SpeechManager();

//    4���˵�����
    void show_Menu();

//    5���˳�����
    void exitsystem();

//    6.3.2��ʼ������
    void initspeech();

//    6.3.3����ѡ��   ��ʼ������12��ѡ��
    void createSpeaker();

//    6.3.4��ʼ������Ա�������
    //��ʼ����-�������̿���   �����������̵Ŀ��ƺ���
    void startspeech();

//    6.3.5��ǩ
    void speechDraw();

//    6.3.6��ʼ����
    void speechContest();  //Contest  ����������

//    6.3.7��ʾ��������  �������
    void showScore();

//    6.4�������   �����¼
    void saveRecord();

//    7.1��ȡ��¼����
    void loadRecord();

//    7.2�鿴��¼����  ��ʾ�����¼
    void showRecord();
//    �ж��ļ��Ƿ�Ϊ��
    bool fileIsEmpty;

//    ��������¼������
    map<int,vector<string >>m_Record;

//    8.1��ռ�¼����
    void clearRecord();
//    ��������
    ~SpeechManager();




//    6.3.1��Ա�������
//����ѡ������12��
    vector<int>v1;

//��һ�ֽ�������6��
    vector<int>v2;

//ʤ��ǰ��������3��
    vector<int>vVictory;

//��ű���Լ���Ӧ�ľ���ѡ������
    map<int,Speaker>m_Speaker;

//��¼��������
    int m_Index;
};

#endif //INC_24_11_21����STL���ݽ��������̹���ϵͳ_02SPEECHMANAGER_H
