//
// Created by tianya on 2024/10/23.
//
#include "iostream"
using namespace std;

//继承方式

//公共继承
class Base1{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};

class Son1:public Base1{  // 第一个儿子
public:
    void func(){
        m_A = 10;//没报错说明正常访问  父类中的公共权限成员,到子类中依然是公共权限
        m_B = 20;//父类中的保护权限成员到子类中依然是保护权限
//        m_C = 10;//报错  父类中的私有权限成员，子类访问不到
    }
};

void test01(){
    Son1 s1;
    s1.m_A = 100;//公共权限  类内和类外  都可以访问
//    s1.m_B = 100;//保护权限  类内可以访问，类外访问不到
}


//保护继承
class Base2{
    public:
        int m_A;
    protected:
        int m_B;
    private:
        int m_C;
};

class Son2: protected Base2{//保护继承
public:
    void func(){
        m_A = 100;//父类中公共成员，到子类中变为保护权限
        m_B = 100;//父类中保护成员，到子类中变为保护权限
//        m_C = 100;//报错  父类中私有成员，子类访问不到
    }
};

void test02(){
    Son2 s1;
//    s1.m_A = 1000;//报错，在Son2中m_A变为保护权限，因此类外访问不到
//    s1.m_B = 1000;//报错，在Son2中m_B变为保护权限，因此类外访问不到
}


//保护继承
class Base3{
    public:
        int m_A;
    protected:
        int m_B;
    private:
        int m_C;
};

class Son3:private Base3{
public:
    void func(){
        m_A = 100;//父类中公共成员  到子类中变为私有成员
        m_B = 100;//父类中保护成员  到子类中变为私有成员
//        m_C = 100;//父类中私有成员，子类访问不到
    }
};
class GrandSon3:public Son3{//孙子类
public:
    void func(){
        m_A = 1000;//到了Son3中m_A变为私有，既是是儿子，也是访问不到
        m_B = 1000;
    }
};
void test03(){
    Son3 s1;
//    s1.m_A = 1000;//私有属性访问不到
//    s1.m_B = 1000;//到Son3中，变为私有成员，类外访问不到
}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
