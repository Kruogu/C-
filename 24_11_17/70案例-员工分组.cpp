//
// Created by tianya on 2024/11/20.
//
#include "iostream"
using namespace std;

#include "vector"
#include "map"

#define CEHUA  0
#define MEISHU 1
#define YANFA  2

//3.10案例-员工分组

//3.10.1案例描述
//    ·公司今天招聘了10个员工(ABCDEFGHIJ)，10名员工进入公司之后，需要指派员工在那个部门工作
//    ·员工信息有：姓名  工资组成：部门分为：策划、美术、研发
//    ·随机给10名员工分配部门和工资
//    ·通过multimap:进行信息的插入key(部门编号)value(员工)
//    ·分部门显示员工信息


//3.10.2实现步骤
//    1.创建10名员工，放到vector中
//    2.遍历vector容器，取出每个员工，进行随机分组
//    3.分组后，将员工部门编号作为key,具体员工作为value,放入到multimap容器中
//    4.分部门显示员工信息

//员工类
class Worker{
public:
//    不能写构造函数
//    Worker(string name){
//        this->m_Name = name;
//    }
    string m_Name;//姓名
    int m_Salary;//工资

};

//打印信息

//1、创建员工
void createWorker(vector<Worker> &v){
    string nameSeed = "ABCDEFGHIJ";
    for(int i=0;i<10;i++){
        Worker worker;
        worker.m_Name = "员工";
        worker.m_Name += nameSeed[i];

//        工资
//        worker.m_Salary = rand()%60+41;//60~100
        worker.m_Salary = rand()%10000+10000;//10000~19999

//        将员工放入到容器中
        v.push_back(worker);
    }

//    Worker w2("B");//不能这么写
//    Worker w3("C");
}

//2、员工分组
void setGroup(vector<Worker> &v,multimap<int,Worker> &m){
    for(vector<Worker>::iterator it=v.begin();it!=v.end();it++){
        //产生随机部门编号
        int deptID = rand()%3;//0 1 2

//        将员工插入到分组中
//        key部门编号，value具体员工  *it
        m.insert(make_pair(deptID,*it));
//        cout<<"姓名："<<it->m_Name
//            <<" 工资："<<(*it).m_Salary<<endl;
    }
}

//3、分组显示员工  自己写的
void showWorkerByGourp1(multimap<int,Worker> &m){
    static int flag = 0;
    cout<<"分组显示员工："<<endl;
    for(multimap<int,Worker>::iterator it=m.begin();it!=m.end();it++){
        string deptName;
        int index;
        switch (it->first) {
            case 0:
                deptName="策划";
                index = 0;
                break;
            case 1:
                deptName="美术";
                index = 1;
                break;
            case 2:
                index = 2;
                deptName="研发";
                break;
            default:
                break;
        }
        if(flag!=index){
            flag = index;
            cout<<endl;
        }

        cout<<"部门："<<deptName
            <<" 姓名："<<it->second.m_Name
            <<" 工资："<<(*it).second.m_Salary<<endl;
    }
}

//3、分组显示员工  教师版
void showWorkerByGourp2(multimap<int,Worker> &m){
    // 0 A B C 1 D E 2 F G...
    cout<<"策划部门："<<endl;
    multimap<int,Worker>::iterator pos = m.find(CEHUA);
    int count = m.count(CEHUA);//统计部门人数
    int index = 0;//索引值
    for(;pos!=m.end() && index<count;pos++,index++){
        cout<<"部门："
            <<" 姓名："<<pos->second.m_Name
            <<" 工资："<<(*pos).second.m_Salary<<endl;
    }

    cout<<"——————————"<<endl;
    cout<<"美术部门："<<endl;
    pos = m.find(MEISHU);
    count = m.count(MEISHU);//统计部门人数
    index = 0;//索引值
    for(;pos!=m.end() && index<count;pos++,index++){
        cout<<"部门："
            <<" 姓名："<<pos->second.m_Name
            <<" 工资："<<(*pos).second.m_Salary<<endl;
    }

    cout<<"——————————"<<endl;
    cout<<"研发部门："<<endl;
    pos = m.find(YANFA);
    count = m.count(YANFA);//统计部门人数
    index = 0;//索引值
    for(;pos!=m.end() && index<count;pos++,index++){
        cout<<"部门："
            <<" 姓名："<<pos->second.m_Name
            <<" 工资："<<(*pos).second.m_Salary<<endl;
    }
}


void test01(){
//    srand(time(0));//随机数种子
    srand((unsigned int) time(NULL));//随机数种子

//    1、创建员工
    vector<Worker>vWorker;
    createWorker(vWorker);

//    测试
    for(vector<Worker>::iterator it=vWorker.begin();it!=vWorker.end();it++){
        cout<<"姓名："<<it->m_Name
            <<" 工资："<<(*it).m_Salary<<endl;
    }
    cout<<endl;

//    2、员工分组
    multimap<int,Worker>mWorker;//key值  部门编号   value值 具体员工
    setGroup(vWorker,mWorker);

//    3、分组显示员工
    showWorkerByGourp1(mWorker);//自创
//    showWorkerByGourp2(mWorker);//教师
}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
