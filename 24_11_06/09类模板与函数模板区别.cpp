//
// Created by tianya on 2024/11/8.
//
#include "iostream"
using namespace std;
//1.类模板没有自动类型推导的使用方式

//1.3.2类模板与函数模板区别
template<class NameType,class AgeType>//两个类型 模板  test01  可以

//template<class NameType,class AgeType=int>//可以默认指定类型 test02  可以
//template<class NameType=string,class AgeType>//这样会报错 test02    不可以
//template<class NameType=string,class AgeType>//这样会报错 test02    不可以
//template<class NameType=string,class AgeType=int>//可以默认指定类型 test02  可以

//template<class NameType,class AgeType,class IdType=string>//test02  如果是三个类型？最后一个指定string  不可以
//template<class NameType,class AgeType=int,class IdType>//test02  如果是三个类型？中间一个指定int  不可以
//template<class NameType,class AgeType,class IdType=int>//test02  如果是三个类型？最后一个指定int  不可以
//template<class NameType,class AgeType=int,class IdType>//test02  如果是三个类型？中间一个指定int  不可以
//template<class NameType,class AgeType,class IdType=int>//test02  如果是三个类型？最后一个指定int  不可以
//template<class NameType,class AgeType=int,class IdType=int>//test02  如果是三个类型？后两个指定int 可以
//template<class NameType,class AgeType=string,class IdType=string>//test02  如果是三个类型？后两个指定string 可以
//template<class NameType=string,class AgeType=string,class IdType=string>//test02  如果是三个类型？ 可以
//默认指定类型只能指定后面，如果指定前面冲突后会报错
class Person{
public:
    Person(NameType name,AgeType age){
//    Person(NameType name,AgeType age,IdType id){
        this->m_Name = name;
        this->m_Age = age;
//        this->m_id = id;
    }

    void showPerson()//打印输出一下
    {
        cout<<"name："<<this->m_Name<< endl;
        cout<<"age："<<this->m_Age<< endl;
//        cout<<"id："<<this->m_id<< endl;
    }
    //姓名
    NameType m_Name;
    //年龄
    AgeType m_Age;
    //id
//    IdType m_id;

};

//void test01(){
////    Person p("孙悟空",1000);//错误，不能自动类型推导
//    Person<string,int> p("孙悟空",1000);//正确，只能用显示指定类型
//    p.showPerson();
//}

//2.类模板在模板参数列表中可以有默认参数
void test02(){
//    Person<string,int> p("猪八戒",999);//可以
//    Person<string> p("猪八戒",999);//如果第二个指定int  可以
//    Person<string> p("猪八戒","姓名");//如果指定第一个 string  不可以
    Person<string,string> p("猪八戒","姓名");//如果两个都指定string  可以
//    Person<int> p("猪八戒",999);//如果第一个指定string   不可以
//    Person<> p("猪八戒",999);//如果两个分别都指定好string和int  可以

//    Person<int> p(11,1,"八");//如果 最后 一个指定好string  不可以
//    Person<string> p("猪八戒",1,"八");//如果 中间 一个指定好int  不可以
//    Person<string> p("猪八戒","八",1);//如果 最后 一个指定好int  不可以
//    Person<string> p("猪八戒",18,1);//如果 中间 一个指定好int  不可以
//    Person<string> p("猪八戒",18,1);//如果 最后 一个指定好int  不可以
//    Person<string> p("猪八戒",18,1);//如果 后两个 都指定好 int  可以
//    Person<string> p("猪八戒","猪","八");//如果 后两个 都指定好 string  可以
//    Person<> p("猪八戒","猪","八");//如果 三个都 指定好string  可以

//    经过大量测试发现，如果只指定了一个类型，代表指定第一个类模板参数类型，其余参数必须 提前声明默认，否则报错

    p.showPerson();
}

int main(){
//    test01();
    test02();
    cout<<"HelloWorld"<<endl;
    return 0;
}
