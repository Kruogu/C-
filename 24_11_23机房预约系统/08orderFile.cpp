//
// Created by tianya on 2024/11/24.
//

#include "08orderFile.h"

//    构造函数
OrderFile::OrderFile() {

    ifstream ifs;
    ifs.open(ORDER_FILE,ios::in);//读文件

    string date;        //预约日期
    string interval;    //时间段
    string stuId;       //学生编号
    string stuName;     //学生姓名
    string roomId;        //机房编号
    string status;      //预约状态

    this->m_Size = 0;   //记录条数

    while (ifs>>date && ifs>>interval && ifs>>stuId && ifs>>stuName && ifs>>roomId  && ifs>>status){
//        测试从文件中获取到的内容  代码
//        {
//            cout<<date<<endl;         //date:2
//            cout<<interval<<endl;     //interval:1
//            cout<<stuId<<endl;        //stuId:1
//            cout<<stuName<<endl;      //stuName:张三
//            cout<<roomId<<endl;         //roomId:2
//            cout<<status<<endl;       //status:1
//            cout<<endl;
//        }

//          date是string字符串类型内 有：date:2
//          嵌套小map容器内的两个值
            string key;
            string value;
            map<string ,string > m;

        //截取预约日期date
        int pos = date.find(":");//pos=4   d a t e : 2
        if(pos!=-1){//                        0 1 2 3 4 5   size = 6
            key = date.substr(0,pos);//date  0~4    6-4-1 = 1
            value = date.substr(pos+1,date.size()-pos-1);//起始位置  截取个数
    //                value = date.substr(pos+1,date.size());//这么做也行，但是 size 多了
            m.insert(make_pair(key,value));//对组 插入
        }
//            cout<<"key = "<<key<<endl;
//            cout<<"value = "<<value<<endl;

        //截取时间段interval
        pos = interval.find(":");
        if(pos!=-1){
            key = interval.substr(0,pos);
            value = interval.substr(pos+1,interval.size()-pos-1);//起始位置  截取个数
            m.insert(make_pair(key,value));//对组 插入
        }

        //截取学生编号stuId
        pos = stuId.find(":");
        if(pos!=-1){
            key = stuId.substr(0,pos);
            value = stuId.substr(pos+1,stuId.size()-pos-1);//起始位置  截取个数
            m.insert(make_pair(key,value));//对组 插入
        }

        //截取学生姓名stuName
        pos = stuName.find(":");
        if(pos!=-1){
            key = stuName.substr(0,pos);
            value = stuName.substr(pos+1,stuName.size()-pos-1);//起始位置  截取个数
            m.insert(make_pair(key,value));//对组 插入
        }

        //截取机房编号roomId
        pos = roomId.find(":");
        if(pos!=-1){
            key = roomId.substr(0,pos);
            value = roomId.substr(pos+1,roomId.size()-pos-1);//起始位置  截取个数
            m.insert(make_pair(key,value));//对组 插入
        }

        //截取预约状态status
        pos = status.find(":");
        if(pos!=-1){
            key = status.substr(0,pos);
            value = status.substr(pos+1,status.size()-pos-1);//起始位置  截取个数
            m.insert(make_pair(key,value));//对组 插入
        }

//        将小map容器放入到大的map容器中
        this->m_orderData.insert(make_pair(this->m_Size,m));
        this->m_Size++;
    }
    ifs.close();//关闭

//    测试最大map容器  自身所有预约 从文件中获取，预处理过后的信息
//    {
//        for(map<int,map<string ,string>>::iterator it=m_orderData.begin();it!=m_orderData.end();it++){
//            cout<<"key条数为："<<it->first
//                <<"\tvalue = "<<endl;
//            for(map<string,string>::iterator mit=(*it).second.begin();mit!=(*it).second.end();mit++){
//                cout<<"\tk="<<mit->first<<" "    //date:2  key=
//                    <<"v="<<mit->second<<"";    //value=
//            }
//            cout<<endl;
//        }
//    }
}

//    更新预约记录
void OrderFile::updateOrder(){

    if(this->m_Size == 0){
        return; //预约记录0条，直接return
    }

//    先写入，再删了重写
    ofstream ofs(ORDER_FILE,ios::out|ios::trunc);

//    可以更新容器内所有信息
    for (int i = 0; i < this->m_Size; ++i) {
//        访问嵌套map容器
        ofs<<"date:"<< this->m_orderData[i]["date"]<<" ";
        ofs<<"interval:"<< this->m_orderData[i]["interval"]<<" ";
        ofs<<"stuId:"<< this->m_orderData[i]["stuId"]<<" ";
        ofs<<"stuName:"<< this->m_orderData[i]["stuName"]<<" ";
        ofs<<"roomId:"<< this->m_orderData[i]["roomId"]<<" ";
        ofs<<"status:"<< this->m_orderData[i]["status"]<<" "<<endl;
    }
    ofs.close();

}

