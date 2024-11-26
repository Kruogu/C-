//
// Created by tianya on 2024/7/31.
//
#include "iostream"
using namespace std;

//1构造函数的分类及调用
//分类
//    按照参数分类    无参构造（默认构造） 和 有参构造
//    按照类型分类    普通构造 和 拷贝构造
class Person{
public:
    //构造函数
    Person(){
        cout<<"Person 无参构造函数的调用"<<endl;
    }
    Person(int a){
        age = a;//初始化
        cout<<"Person 有参构造函数的调用"<<endl;
    }
//    拷贝构造函数
    Person(const Person &p){
//        将传入的人身上的所有属性，拷贝到我身上
        age = p.age;
        cout<<"Person 拷贝构造函数的调用"<<endl;
    }
    ~Person(){
        cout<<"Person 析构函数的调用"<<endl;
    }

    int age;
};


//调用
void test01(){
//    1.括号法     老师喜欢这种
//    Person p1;//默认构造函数的调用
//    Person p2(10);//有参构造函数
//    Person p3(p2);  //拷贝构造函数

//    注意事项
//    调用默认构造函数的时候，不要加（）小括号
//    因为下面这行代码，编译器会认为是一个函数的声明,不会认为在创建对象
//    Person p1();//没有任何输出

//    cout<<"p2的年龄为："<<p2.age<<endl;
//    cout<<"p3的年龄为："<<p3.age<<endl;


//    2.显示法  调用
//    Person p1;  //默认构造函数
//    Person p2 = Person(10); //有参构造
//    Person p3 = Person(p2); //拷贝构造

//    特点：当前行执行结束后，系统会立即回收掉匿名对象
//    Person(10); //这个是匿名对象   vector容器交换会用到！
//    cout<<"aaaaa"<<endl;

//    注意事项2
//    不要利用拷贝构造函数  初始化匿名对象
//    编译器会认为Person(p3) === Person p3; 对象声明
//                  加上小括号
//    Person(p3); //直接报错


//    3.隐式转换法
    Person p4 = 10; //Person p4 = Person(10);   有参构造
    Person p5 = p4; //Person p5 = Person(p4);   拷贝构造
}


int main(){

    test01();

    cout<<"HelloWorld1"<<endl;
    return 0;
}
