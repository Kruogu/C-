//
// Created by tianya on 2024/11/1.
//
#include "iostream"
using namespace std;
//多态案例二-制作饮品
//  制作饮品的大致流程为：煮水·冲泡-倒入杯中-加入辅料
//  利用多态技术实现本案例，提供抽象制作饮品基类，提供子类制作咖啡和茶叶

//coffee 咖啡   tea  茶
class AbstractDrinking{ //抽象饮品
public:
//    virtual void zs() = 0;//1、煮水  boil
    virtual void cp() = 0;//2、冲泡咖啡  茶叶  brew
//    virtual void db() = 0;//3、倒入杯中  pour In Cup
    virtual void jf() = 0;//4、加糖和牛奶  加柠檬  Put Something 放一些

//    制作饮品
    void makeDrink(){
        cp();
        jf();
    }
};

//制作咖啡
class Coffee:public AbstractDrinking{
    void cp(){
        cout<<"1、煮水"<<endl;
        cout<<"2、冲泡咖啡"<<endl;

    }
    void jf(){
        cout<<"3、倒入杯中"<<endl;
        cout<<"2、加糖和牛奶"<<endl;
    }
};

//制作茶
class Tea:public AbstractDrinking{
    void cp(){
        cout<<"1、煮水"<<endl;
        cout<<"2、冲泡茶叶"<<endl;

    }
    void jf(){
        cout<<"3、倒入杯中"<<endl;
        cout<<"2、加柠檬"<<endl;
    }
};

//制作函数
void doWork1(AbstractDrinking &abs){
    abs.makeDrink();
//    delete abs;
}
//还有一种写法
void doWork2(AbstractDrinking * abs){
    abs->makeDrink();
    delete abs;//释放空间
}

//多态指针
void test01(){
    AbstractDrinking *AbstractDrinking = new Coffee;
    AbstractDrinking->cp();
    AbstractDrinking->jf();
    delete AbstractDrinking;

    cout<<"——————————"<<endl;

    AbstractDrinking = new Tea;
    AbstractDrinking->makeDrink();//简写版
    delete AbstractDrinking;
}

//多态引用
void test02(){
    Coffee c;//咖啡
    doWork1(c);

    cout<<"——————————"<<endl;

//    Tea t;//茶  也可以不写
    doWork2(new Tea);//报错未知原因  在这里直接new  其实也算指针写法
//              已找到报错原因，doWork2函数中指针写成引用不能直接创建对象
}
int main(){
//    test01();
    test02();
    cout<<"HelloWorld"<<endl;
    return 0;
}
