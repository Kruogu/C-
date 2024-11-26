//
// Created by tianya on 2024/7/29.
//
#include "iostream"
using namespace std;

//访问权限有三种：
//1.public      公共权限    成员 类内可以访问,类外可以访问
//2.protected   保护权限    成员 类内可以访问,类外不可以访问  儿子可以访问父亲的私有内容
//3.private     私有权限    成员 类内可以访问,类外不可以访问  儿子不可以访问父亲的私有内容

class Person{

public://公共权限
    string m_Name;  //姓名

protected://保护权限
    string m_Car;   //汽车

private://私有权限
    int m_Password; //银行卡密码

public:
//private://类外函数访问不到了
    void func(){
        m_Name = "张三";
        m_Car = "拖拉机";
        m_Password = 123456;
    }

};

int main(){

    //实例化具体对象
    Person p1;

    p1.m_Name = "李四";
//    p1.m_Car = "轿车";    //报错，保护权限内容，在类外访问不到
//    p1.m_Password = "123123"; //报错，私有权限内容，在类外访问不到
    p1.func();
    cout<<p1.m_Name<<endl;
//    cout<<p1.m_Car<<endl;
//    cout<<p1.m_Password<<endl;
    cout<<"HelloWorld"<<endl;
    return 0;
}
