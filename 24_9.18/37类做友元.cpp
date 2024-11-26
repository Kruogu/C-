//
// Created by tianya on 2024/9/18.
//
#include "iostream"
#include "string"
using namespace std;

//类做友元
class Building;//类的声明

class GoodGay{
public:

    GoodGay();
    void visit();//参观函数 访问Building中的属性
    Building * building;
};

class Building{
//    GoodGay类是本类的好朋友，可以访问本类中私有的成员
    friend class GoodGay;//不加class也可以正常运行
public:
    Building();
public:
    string m_SittingRoom;//客厅
private:
    string m_BedRoom;//卧室
};

//类外写成员函数
Building::Building(){
    m_SittingRoom = "客厅";
    m_BedRoom = "卧室";
}
GoodGay::GoodGay() {
//    创建建筑物对象
    building = new Building;//堆区创建了一个对象
}
void GoodGay::visit() {
    cout<<"好基友类正在访问："<<building->m_SittingRoom<<endl;
    cout<<"好基友类正在访问："<<building->m_BedRoom<<endl;
}

void test01(){
    GoodGay gg;
    gg.visit();
}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
