//
// Created by tianya on 2024/7/29.
//
#include "iostream"
using namespace std;

//成员属性设置为私有
//1.可以自己控制读写权限
//2.对于写可以检测数据有效性

//人类
class Person{
public:
        //设置姓名
        void setName(string name){
            m_Name = name;
        }
//        获取姓名
        string getName(){
            return m_Name;
        }
//        设置年龄  (0~150)
        void setAge(int age){
            if(age>=0&&age<=150)
                m_Age = age;
            else
                cout<<"年龄输入"<<age<<"有误，赋值失败！"<<endl;
                return;
        }
//        获取年龄  只读
        int getAge(){
            return m_Age;
        }
//        设置偶像  只写
        void setIdol(string idol){
            m_Idol = idol;
        }
//    获取偶像  没有这个就读不出来
        string getIdol(){
            return m_Idol;
        }
private:
    string  m_Name; //姓名 可读可写

    int m_Age=18;  //年龄  只读 也可以写（年龄必须在0到150之间）

    string m_Idol; //偶像  只写
};
int main(){
    Person p;
    //姓名设置
//    p.m_Name = "张三";  //这样不能直接获取

    p.setName("张三");
//    获取姓名
    cout<<"姓名："<<p.getName()<<endl;


    //年龄设置
    p.setAge(160);
//    p.m_Age = 20;
//    获取年龄  没问题  只读
    cout<<"年龄："<<p.getAge()<<endl;

//    偶像设置
    p.setIdol("小明");
//    获取偶像
    cout<<"偶像："<<p.getIdol()<< endl;//只写状态外界访问不到


    cout<<"Hello World111"<<endl;
    return 0;
}
