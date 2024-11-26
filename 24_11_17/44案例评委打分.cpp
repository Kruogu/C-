 //
// Created by tianya on 2024/11/18.
//
#include "algorithm"//标准算法头文件
#include "vector"//迭代器头文件
#include "deque"
#include "iostream"
using namespace std;
//#include<stdlib.h>   // 随机数库
//#include<time.h>	//  随机数相关库
#include<ctime>	//  时间库 跟上面一样

//3.4案例-评委打分

//3.4.1案例描述
//  有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分。

//3.4.2实现步骤
//    1.创建五名选手，放到vector中
//    2.遍历vector容器，取出来每一个选手，执行for循环，可以把10个评分打分存到deque容器中
//    3.sort算法对deques容器中分数排序，去除最高和最低分
//    4.deque容器遍历一遍，累加总分
//    5.获取平均分

//选手类
class Person{
public:
    Person(string name,int score){
        this->m_Name = name;
        this->m_Score = score;
    }
    string m_Name;//姓名
    int m_Score;//评分
};

// 创建选手
void creatPerson(vector<Person> &v){
    string nameSeed = "ABCDE";//seed 种子
    for(int i=0;i<5;i++){
        string name = "选手";
        name += nameSeed[i];//拼接

        int score = 0;//默认0分

        Person p(name,score);//创建类
//        将创建的Person对象放入到容器中
        v.push_back(p);//插入容器
    }
}

//打分
void setScore(vector<Person> &v){
//     srand((unsigned int)time(NULL));  // 随机数相关
       srand(time(0));  // 随机数相关  和上一行一样
     for(vector<Person>::iterator it=v.begin();it!=v.end();it++){
//        将评委的分数放入到deque容器中
         deque<int>d;
         for (int i = 0; i < 10; i++) {
//          rand()%40 默认0~39  rand()%40+60 是60~99  取余几就是最大几  加1可以避免 0
            int score = rand()%41+60;//60-100 随机数
            d.push_back(score);//插入10个人的分数
        }

//         测试代码  查看每个选手的10个分数
//         {
//             cout<<"选手："<<it->m_Name<<"打分："<<endl;
//             for(deque<int>::iterator dit=d.begin();dit!=d.end();dit++){
//                 cout<<*dit<<" ";
//             }
//             cout<<endl;
//         }

//        排序
        sort(d.begin(),d.end());//从小到大

//        去除最高和最低分  同时size自动减掉两个人
        d.pop_back();//尾删   去最大
        d.pop_front();//头删  去最小

//        取平均分
        int sum = 0;//总分
        for(deque<int>::iterator dit=d.begin();dit!=d.end();dit++){
            sum+=*dit;//累加每个评委的分数
        }

        int avg = sum/d.size();//求平均分  size目前正好只剩8个人

        //将平均分赋值给选手身上
        it->m_Score = avg;

//        测试代码 查看 选手最终分数  也可以封装成打印函数showScore
//         {
//             cout<<"姓名："<<(*it).m_Name<<" "
//                     <<" 分数："<<it->m_Score<<endl;
//         }
    }
}

void showScore(vector<Person> &v){
    for(vector<Person>::iterator it=v.begin();it!=v.end();it++){
//        cout<<"姓名："<<(*it).m_Name<<" "
        cout<<"姓名："<<it->m_Name<<" "//两种写法都可以
            <<" 平均分："<<it->m_Score<<endl;
    }
}
void test01(){
    //随机数种子  也可以加这里
    srand((unsigned int)time(NULL));

//    1、创建5名选手
    vector<Person>v;//存放选手容器
    creatPerson(v);

//    测试
//    {
//        for(vector<Person>::iterator it=v.begin();it!=v.end();it++){
//            cout<<"姓名："<<(*it).m_Name<<" "
//                //        cout<<"姓名："<<it->m_Name<<" "//两种写法都可以
//                <<" 分数："<<it->m_Score<<endl;
//        }
//    }

//    2、给5名选手打分
    setScore(v);

//    3、显示最后得分
    showScore(v);
//    deque<int>d;
}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
