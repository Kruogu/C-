 //
// Created by tianya on 2024/11/18.
//
#include "algorithm"//��׼�㷨ͷ�ļ�
#include "vector"//������ͷ�ļ�
#include "deque"
#include "iostream"
using namespace std;
//#include<stdlib.h>   // �������
//#include<time.h>	//  �������ؿ�
#include<ctime>	//  ʱ��� ������һ��

//3.4����-��ί���

//3.4.1��������
//  ��5��ѡ�֣�ѡ��ABCDE��10����ί�ֱ��ÿһ��ѡ�ִ�֣�ȥ����߷֣�ȥ����ί����ͷ֣�ȡƽ���֡�

//3.4.2ʵ�ֲ���
//    1.��������ѡ�֣��ŵ�vector��
//    2.����vector������ȡ����ÿһ��ѡ�֣�ִ��forѭ�������԰�10�����ִ�ִ浽deque������
//    3.sort�㷨��deques�����з�������ȥ����ߺ���ͷ�
//    4.deque��������һ�飬�ۼ��ܷ�
//    5.��ȡƽ����

//ѡ����
class Person{
public:
    Person(string name,int score){
        this->m_Name = name;
        this->m_Score = score;
    }
    string m_Name;//����
    int m_Score;//����
};

// ����ѡ��
void creatPerson(vector<Person> &v){
    string nameSeed = "ABCDE";//seed ����
    for(int i=0;i<5;i++){
        string name = "ѡ��";
        name += nameSeed[i];//ƴ��

        int score = 0;//Ĭ��0��

        Person p(name,score);//������
//        ��������Person������뵽������
        v.push_back(p);//��������
    }
}

//���
void setScore(vector<Person> &v){
//     srand((unsigned int)time(NULL));  // ��������
       srand(time(0));  // ��������  ����һ��һ��
     for(vector<Person>::iterator it=v.begin();it!=v.end();it++){
//        ����ί�ķ������뵽deque������
         deque<int>d;
         for (int i = 0; i < 10; i++) {
//          rand()%40 Ĭ��0~39  rand()%40+60 ��60~99  ȡ�༸�������  ��1���Ա��� 0
            int score = rand()%41+60;//60-100 �����
            d.push_back(score);//����10���˵ķ���
        }

//         ���Դ���  �鿴ÿ��ѡ�ֵ�10������
//         {
//             cout<<"ѡ�֣�"<<it->m_Name<<"��֣�"<<endl;
//             for(deque<int>::iterator dit=d.begin();dit!=d.end();dit++){
//                 cout<<*dit<<" ";
//             }
//             cout<<endl;
//         }

//        ����
        sort(d.begin(),d.end());//��С����

//        ȥ����ߺ���ͷ�  ͬʱsize�Զ�����������
        d.pop_back();//βɾ   ȥ���
        d.pop_front();//ͷɾ  ȥ��С

//        ȡƽ����
        int sum = 0;//�ܷ�
        for(deque<int>::iterator dit=d.begin();dit!=d.end();dit++){
            sum+=*dit;//�ۼ�ÿ����ί�ķ���
        }

        int avg = sum/d.size();//��ƽ����  sizeĿǰ����ֻʣ8����

        //��ƽ���ָ�ֵ��ѡ������
        it->m_Score = avg;

//        ���Դ��� �鿴 ѡ�����շ���  Ҳ���Է�װ�ɴ�ӡ����showScore
//         {
//             cout<<"������"<<(*it).m_Name<<" "
//                     <<" ������"<<it->m_Score<<endl;
//         }
    }
}

void showScore(vector<Person> &v){
    for(vector<Person>::iterator it=v.begin();it!=v.end();it++){
//        cout<<"������"<<(*it).m_Name<<" "
        cout<<"������"<<it->m_Name<<" "//����д��������
            <<" ƽ���֣�"<<it->m_Score<<endl;
    }
}
void test01(){
    //���������  Ҳ���Լ�����
    srand((unsigned int)time(NULL));

//    1������5��ѡ��
    vector<Person>v;//���ѡ������
    creatPerson(v);

//    ����
//    {
//        for(vector<Person>::iterator it=v.begin();it!=v.end();it++){
//            cout<<"������"<<(*it).m_Name<<" "
//                //        cout<<"������"<<it->m_Name<<" "//����д��������
//                <<" ������"<<it->m_Score<<endl;
//        }
//    }

//    2����5��ѡ�ִ��
    setScore(v);

//    3����ʾ���÷�
    showScore(v);
//    deque<int>d;
}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
