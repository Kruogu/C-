//
// Created by tianya on 2024/11/2.
//
#include "iostream"
using namespace std;
//多态案例三-电脑组装


//抽象出每个零件的类
class CPU{//抽象CPU类
public:
//    抽象计算函数
    virtual void calculate() = 0;
};
class VideoCard{//抽象类  显卡
public:
//    抽象显示函数
    virtual void display() = 0;//显示
};
class Memory{//抽象类  内存
public:
//    抽象存储函数
    virtual void storage() = 0;//存储
};

//电脑类
class Computer{
public:
    Computer(CPU *cpu,VideoCard *vc,Memory *mem){
        m_cpu = cpu;
        m_vc = vc;
        m_mem = mem;
    }

    //提供工作的函数
    void work(){
        //调用每个零件工作的接口
        m_cpu->calculate();
        m_vc->display();
        m_mem->storage();
    }

    //提供析构函数
    ~Computer(){
        //释放CPU零件
        if(m_cpu!=NULL){
            delete m_cpu;
            m_cpu = NULL;
        }
        //释放显卡零件
        if(m_vc!=NULL){
            delete m_vc;
            m_vc = NULL;
        }
        //释放内存条零件
        if(m_mem!=NULL){
            delete m_mem;
            m_mem = NULL;
        }
    }

//    构造函数中传入三个零件指针
private:
    CPU *m_cpu;//CPU的零件指针
    VideoCard *m_vc;//显卡的零件指针
    Memory *m_mem;//内存条零件指针
};

//具体的零件厂商 Inter
class InterCpu:public CPU{
public:
    void calculate(){
        cout<<"Inter的cpu开始计算了"<<endl;
    }
};
class InterVideoCard:public VideoCard{
public:
    void display(){
        cout<<"Inter的显卡开始显示了"<<endl;
    }
};
class InterMemory:public Memory{
public:
    void storage(){
        cout<<"Inter的内存开始存储了"<<endl;
    }
};

//Lenovo 厂商  也需要提供三个零件
class LenovoCpu:public CPU{
public:
    void calculate(){
        cout<<"Lenovo的cpu开始计算了"<<endl;
    }
};
class LenovoVideoCard:public VideoCard{
public:
    void display(){
        cout<<"Lenovo的显卡开始显示了"<<endl;
    }
};
class LenovoMemory:public Memory{
public:
    void storage(){
        cout<<"Lenovo的内存条开始存储了"<<endl;
    }
};


//测试 开始组装三台不同的电脑
void test01(){
//    第一台电脑的零件
    CPU *interCpu = new InterCpu;
    VideoCard *interCard = new InterVideoCard;
    Memory * interMem = new InterMemory;

    cout<<"第一台电脑开始工作"<<endl;
//    创建第一台电脑
    Computer * computer1 = new Computer(interCpu,interCard,interMem);
    computer1->work();
    delete computer1;//释放

    cout<<"——————————————"<<endl;
    cout<<"第二台电脑开始工作"<<endl;
//    第二台电脑的组装
//    创建第二台电脑
    Computer * computer2 = new Computer(new LenovoCpu,new LenovoVideoCard,new LenovoMemory);
    computer2->work();
    delete computer2;//释放

//    第三台电脑的组装
//    CPU *interCpu = new InterCpu;
//    VideoCard *lenovoCard = new LenovoVideoCard;
//    Memory * interMem = new InterMemory;

//    创建第三台电脑
//    Computer *computer3 = new Computer(interCpu,lenovoCard,interMem);
//    computer3->work();
//    delete computer3;//释放

    cout<<"——————————————"<<endl;
    cout<<"第三台电脑开始工作"<<endl;
//    第三台电脑的组装
//    创建第三台电脑
    Computer * computer3 = new Computer(new InterCpu,new LenovoVideoCard,new InterMemory);
    computer3->work();
    delete computer3;//释放
}

int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
