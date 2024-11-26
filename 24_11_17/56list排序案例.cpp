//
// Created by tianya on 2024/11/19.
//
#include "list"

#include "iostream"
using namespace std;


//1ist容器 排序案例 对于自定义数据类型做排序

//案例描述：将Person自定义数据类型进行排序,Person中属性有姓名、年龄、身高
//排序规则：按照年龄进行升序,如果年龄相同按照身高进行降序

class Person{
public:
    Person(string name,int age,int height){
        this->m_Name = name;
        this->m_Age = age;
        this->m_Height = height;
    }
    string m_Name;//姓名
    int m_Age;//年龄
    int m_Height;//身高
};

void printList(const list<Person> &L){
//    it可以++是因为重载过了,封装好直接使用
    for(list<Person>::const_iterator it = L.begin();it!=L.end();it++){
        cout<<"姓名："<<(*it).m_Name<<" "//两种写法都可以
            <<" 年龄："<<it->m_Age
            <<" 身高："<<it->m_Height <<endl;
    }
    cout<<endl;
}

//指定排序规则，回调函数，仿函数
bool comparePerson(Person &p1,Person &p2){
    //按照年龄升序 就让第一个数 < 第二个数
//    return p1.m_Age<p2.m_Age;//如果成立，就返回真
    //降序 就让第一个数 > 第二个数
//    return p1.m_Age>p2.m_Age;//如果成立，就返回真

//    还要考虑身高需求
    if(p1.m_Age == p2.m_Age){
//        年龄相同 按照身高降序
        return p1.m_Height>p2.m_Height;
    } else{
        return p1.m_Age<p2.m_Age;//如果成立，就返回真  升序
    }
}

void test01(){
//    创建list容器
    list<Person>L; //默认构造

//    准备数据
    Person p1("刘备",35,175);
    Person p2("曹操",45,180);
    Person p3("孙权",40,170);
    Person p4("赵云",25,190);
    Person p5("张飞",35,160);
    Person p6("关羽",35,200);

//    插入数据
    L.push_back(p1);
    L.push_back(p2);
    L.push_back(p3);
    L.push_back(p4);
    L.push_back(p5);
    L.push_back(p6);

//    for(list<Person>::const_iterator it = L.begin();it!=L.end();it++){
//        cout<<"姓名："<<(*it).m_Name<<" "//两种写法都可以
//            <<" 年龄："<<it->m_Age
//            <<" 身高："<<it->m_Height <<endl;
//    }
    printList(L);//封装好了

//    排序
    cout<<"——————————————"<<endl;
    cout<<"升序排序后："<<endl;
    L.sort(comparePerson);
    printList(L);//封装好了
}

int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}


