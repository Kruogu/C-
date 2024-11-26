//
// Created by tianya on 2024/10/3.
//
#include "iostream"
using namespace std;

//重载递增运算符

//自定义整型
class MyInteger{
//    friend ostream &operator<<(ostream &cout,MyInteger &myInt);
    friend ostream &operator<<(ostream &cout,MyInteger myInt);//如果返回值需要删掉myInt前面的&
public:
    MyInteger(){
        m_Num = 0;
    }

//    重载++运算符  前置递增    返回引用为了一直对一个数据进行递增操作
//    void operator++(){
    MyInteger &operator++(){
//        先进行++运算
        m_Num++;
//        再将自身做返回
        return *this;
    }

//    重载++运算符  后置递增  要返回 值 而不是 解引用
//    void operator++(int){   int代表占位参数 可以用于区分前置和后置递增
    MyInteger operator++(int){ //后置递增一定是返回值，前置递增是返回解引用
//        先 记录当时结果
        MyInteger temp = *this;
//        后 进行++运算 递增
        m_Num++;
//        最后 将记录结果做返回  局部对象的引用 执行完就释放了
        return temp;
    }

private:
    int m_Num;
};

//重载<<运算符
//ostream &operator<<(ostream &cout,MyInteger &myInt)
ostream &operator<<(ostream &cout,MyInteger myInt)//如果返回值需要删掉myInt前面的&
{
    cout<<myInt.m_Num;
    return cout;
}
void test01(){
    MyInteger myInt;
//    cout<<myInt<<endl;//报错<<  通过重载<< 和 友元 解决
//    cout<<++myInt<<endl;//报错++
    cout<<++(++myInt)<<endl;//返回解引用 2   返回值 2
    cout<<myInt<<endl;      //返回解引用 2   返回值 1  所以不能返回值
}

void test02(){
    MyInteger myInt;
    cout<<myInt++<<endl;//返回值 0   返回解引用 非法操作 进程结束
    cout<<myInt<<endl;  //返回值 1   返回解引用 非法操作 所以只能返回值
}
int main(){
//    test01();
    test02();
    int a = 0;
    cout<<"++a="<<++(++a)<<endl;
    cout<<" a="<<a<<endl;
    cout<<"HelloWorld"<<endl;
    return 0;
}
