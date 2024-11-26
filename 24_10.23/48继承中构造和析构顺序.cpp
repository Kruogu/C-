//
// Created by tianya on 2024/10/25.
//

#include "iostream"
using namespace std;

//继承中构造和析构顺序

class Base{
public:
    Base(){
        cout<<"Base的构造函数"<<endl;
    }
    ~Base(){
        cout<<"Base的析构函数"<<endl;
    }
};

class Son:public Base{
public:
    Son(){
        cout<<"Son的构造函数"<<endl;
    }
    ~Son(){
        cout<<"Son的析构函数"<<endl;
    }
};

void test01(){
//    Base b;//父类 创建对象

    Son s;//子类  创建对象  先有父亲再有儿子，白发人送黑发人
    //继承中的构造和析构顺序如下：
    //先构造父类，再构造子类，析构的顺序与构造的顺序相反
//    总结：继承中先调用父类构造函数，再调用子类构造函数，析构顺序与构造相反
}

int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
