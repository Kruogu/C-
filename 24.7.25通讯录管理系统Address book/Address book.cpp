//
// Created by tianya on 2024/7/25.
//
//debug关键词   abs.personArray[0]   abs.personArray[1]


#include "iostream"
using namespace std;
#define MAX 1000    //最大人数



//联系人结构体
struct Person{
    string m_Name;  //姓名
    int m_Sex;      //性别：1男 2女
    int m_Age;      //年龄
    string m_Phone; //电话
    string m_Addr;  //住址
};

//通讯录结构体
struct Addressbooks{
    //通讯录中保存的联系人数组
    struct Person personArray[MAX];

    //通讯录中人员个数
    int m_Size;
};

//1.添加联系人
void addPerson(Addressbooks *abs1){
//    判断通讯录是否己满，如果满了就不再添加
    if(abs1->m_Size==MAX){
        cout<<"通讯录已满，无法继续添加!"<<endl;
        return;
    }else{
//        添加具体联系人
//        姓名
        cout<<"请输入姓名："<<endl;
        string name;
        cin>>name;
        abs1->personArray[abs1->m_Size].m_Name = name;
//        性别
        cout<<"请输入性别："<<endl;
        cout<<"1 —— 男"<<endl;
        cout<<"2 —— 女"<<endl;
        int sex = 0;
        while (true){
            cin>>sex;
//            如果输入的是1或者2可以退出循环，因为输入的是正确值
//            如果输入有误，重新输入
            if(sex==1 || sex==2){
                abs1->personArray[abs1->m_Size].m_Sex = sex;
                break;
            }
            cout<<"输入错误，请重新输入"<<endl;
        }
//        年龄
        cout<<"请输入年龄："<<endl;
        int age = 0;
        while (true){
            cin>>age;
//            如果输入的是大于5或小于100可以退出循环，因为输入的是正确值
//            如果输入有误，重新输入
            if(age>0 && age<120){
                abs1->personArray[abs1->m_Size].m_Age = age;
                break;
            }
            cout<<"输入错误，请重新输入"<<endl;
        }
//        电话
        cout<<"请输入电话："<<endl;
        string phone;
        cin>>phone;
        abs1->personArray[abs1->m_Size].m_Phone = phone;
//        住址
        cout<<"请输入住址："<<endl;
        string addr;
        cin>>addr;
        abs1->personArray[abs1->m_Size].m_Addr = addr;

//        更新通讯录人数
        abs1->m_Size++;

        cout<<"添加成功！"<<endl;

//        system("pause");//请按任意键继续  不能用
//        system("cls");//清空屏幕  不能用

//        system("read");//请按任意键继续  不能用
//        system("clear");//清空屏幕  不能用
    }
}

//2.显示联系人
void showPerson(Addressbooks * abs2){
//    判断通讯录中人数是否为0，如果为0，提示记录为空
//    如果不为0，显示记录的联系人信息
    if(abs2->m_Size==0){
        cout<<"当前通讯录为空！"<<endl;
        return;
    }else{
        for(int i=0;i<abs2->m_Size;i++){
            cout<<abs2->personArray[i].m_Name<<"\t"
                <<(abs2->personArray[i].m_Sex==1?"男":"女")<<"\t"
                <<abs2->personArray[i].m_Age<<"\t"
                <<abs2->personArray[i].m_Phone<<"\t"
                <<abs2->personArray[i].m_Addr<<endl;
        }
    }
//        system("pause");//请按任意键继续  不能用
//        system("cls");//清空屏幕  不能用
}

//检测联系人是否存在，如果存在，返回联系人所在数组中的具体位置，不存在返回-1
//参数1 通讯录  参数2 对比姓名
int isExist(Addressbooks * abs3,string name){

    for(int i=0;i<abs3->m_Size;i++){
//        找到用户输入的姓名了
        if(name==abs3->personArray[i].m_Name){
            return i;//找到了，返回这个人在数组中的下标编号
        }
    }
    return -1;//如果遍历结束都没有找到，返回-1
}


//3、删除指定联系人
void deletePerson(Addressbooks * abs4){
    cout<<"请输入您要删除的联系人"<<endl;
    string name;
    cin>>name;

    //ret==-1   未查到
    //ret!=-1   查到了
    int ret = isExist(abs4,name);
    if(ret!=-1){
//        查找到人，要进行删除操作
        for(int i=ret;i<abs4->m_Size;i++){
//            数据前移
            abs4->personArray[i] = abs4->personArray[i+1];
        }
//      更新通讯录人数
        abs4->m_Size--;
        cout<<"删除成功"<<endl;
    }else{
        cout<<"查无此人"<<endl;
    }
}

//4、查找指定联系人信息
void findPerson(Addressbooks *abs5){
    cout<<"请输入您要查找的联系人"<<endl;
    string name;
    cin>>name;

//    判断指定的联系人是否存在通讯录中
    int ret = isExist(abs5,name);

    if(ret!=-1){  //ret!=-1   查到了
        cout<<"姓名："<<abs5->personArray[ret].m_Name<<"\t";
        cout<<"性别："<<abs5->personArray[ret].m_Sex<<"\t";
        cout<<"年龄："<<abs5->personArray[ret].m_Age<<"\t";
        cout<<"电话："<<abs5->personArray[ret].m_Phone<<"\t";
        cout<<"地址："<<abs5->personArray[ret].m_Addr<<"\t"<<endl;
    }else{  //ret==-1   未查到联系人
        cout<<"查无此人！"<<endl;
    }
}

//5.修改指定的联系人信息
void modifyPerson(Addressbooks *abs6){
    cout<<"请输入您要修改的联系人："<<endl;
    string name;
    cin>>name;

//    判断指定的联系人是否存在通讯录中
    int ret = isExist(abs6,name);
    if(ret!=-1) {  //ret!=-1   查到了
//        姓名
        string name;
        cout<<"请输入姓名："<<endl;
        cin>>name;
        abs6->personArray[ret].m_Name = name;

//        性别
        cout<<"请输入性别："<<endl;
        cout<<"1 —— 男"<<endl;
        cout<<"2 —— 女"<<endl;
        int sex = 0;
        while (true){
            cin>>sex;
//            如果输入的是1或者2可以退出循环，因为输入的是正确值
//            如果输入有误，重新输入
            if(sex==1 || sex==2){
                abs6->personArray[ret].m_Sex = sex;
                break;
            }
            cout<<"输入错误，请重新输入"<<endl;
        }
//        年龄
        cout<<"请输入年龄："<<endl;
        int age = 0;
        while (true){
            cin>>age;
//            如果输入的是大于5或小于100可以退出循环，因为输入的是正确值
//            如果输入有误，重新输入
            if(age>0 && age<120){
                abs6->personArray[ret].m_Age = age;
                break;
            }
            cout<<"输入错误，请重新输入"<<endl;
        }
//        电话
        cout<<"请输入电话："<<endl;
        string phone;
        cin>>phone;
        abs6->personArray[ret].m_Phone = phone;
//        住址
        cout<<"请输入住址："<<endl;
        string addr;
        cin>>addr;
        abs6->personArray[ret].m_Addr = addr;

        cout<<"修改成功"<<endl;
    }else{  //ret==-1   未查到联系人
        cout<<"查无此人！"<<endl;
    }
}


//-封装函数显示该界面如void showMenu()
//-在main函数中调用封装好的函数
//菜单界面
void showMenu(){
    cout<<"************************"<<endl;
    cout<<"*****  1.添加联系人  *****"<<endl;
    cout<<"*****  2.显示联系人  *****"<<endl;
    cout<<"*****  3.删除联系人  *****"<<endl;
    cout<<"*****  4.查找联系人  *****"<<endl;
    cout<<"*****  5.修改联系人  *****"<<endl;
    cout<<"*****  6.清空联系人  *****"<<endl;
    cout<<"*****  0.退出联系人  *****"<<endl;
    cout<<"************************"<<endl;
}

//6.清空所有联系人
void cleanPeron(Addressbooks *abs7){
    cout<<"你确定要清空吗？1确定 0放弃"<<endl;
    int ret;
    cin>>ret;
    if(ret==1){
        abs7->m_Size = 0; ///将当前记录联系人数量置为0，做逻辑清空操作
        cout<<"通讯录已清空"<<endl;
    }
    return;
}


int main(){

    //创建通讯录结构体变量
    Addressbooks abs;
    //初始化用驯鹿中当前人员个数
    abs.m_Size = 0;



    int select = 0; //创建一个用户选择输入的变量

    while(true){
        showMenu();
        cin>>select;

        //1.菜单调用
        switch (select) {
            case 1: //1.添加联系人
                addPerson(&abs);//利用地址传递，可以修饰实参
                break;
            case 2: //2.显示联系人
                showPerson(&abs);
                break;
            case 3: //3.删除联系人
                deletePerson(&abs);
//            {
//                cout<<"请输入删除联系人的姓名："<<endl;
//                string name;
//                cin>>name;
//                if(isExist(&abs,name)==-1){
//                    cout<<"此人不存在"<<endl;
//                } else{
////                    cout<<"删除位置为："<<i+1<<endl;
//                    cout<<"找到此人"<<endl;
//                }
//            }
                break;
            case 4: //4.查找联系人
                findPerson(&abs);
                break;
            case 5: //5.修改联系人
                modifyPerson(&abs);
                break;
            case 6: //6.清空联系人
                cleanPeron(&abs);
                break;
            case 0: //0.退出联系人
                cout<<"欢迎下次使用"<<endl;
//            system("pause");
                return 0;
                break;
            default:
                break;
        }
    }

    system("cls");//清空屏幕
    cout<<"HelloWorld"<<endl;
    system("pause");
    return 0;
}
