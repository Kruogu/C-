//
// Created by tianya on 2024/11/21.
//

#include "02speechManager.h"
//构造函数  这里是调用成员函数
SpeechManager::SpeechManager(){
    //初始化属性
    this->initspeech();

//    创建选手
    this->createSpeaker();

//    加载往届记录
    this->loadRecord();
}

//4.2菜单功能实现
void SpeechManager::show_Menu(){
    cout << "*****************************************" << endl;
    cout << "************* 欢迎参加演讲比赛 *************" << endl;
    cout << "************** 1.开始演讲比赛 *************" << endl;
    cout << "************** 2.查看往届记录 *************" << endl;
    cout << "************ * 3.清空比赛记录 *************" << endl;
    cout << "************** 0.退出比赛程序 *************" << endl;
    cout << "*****************************************" << endl;
    cout << endl;
}

//5.2实现退出功能
void SpeechManager::exitsystem(){
    cout <<"欢迎下次使用" << endl;
    system("pause");
    exit(0);
}

//    6.3.2初始化属性
void SpeechManager::initspeech(){
//    容器保证为空
    this->v1.clear();
    this->v2.clear();
    this->vVictory.clear();
    this->m_Speaker.clear();

//    初始化比赛轮数
    this->m_Index = 1;

//    初始化记录容器  将记录的容器也清空
    this->m_Record.clear();
}

//    6.3.3创建选手  初始化创建12名选手
void SpeechManager::createSpeaker(){
    string nameSeed = "ABCDEFGHIJKL";
    for (int i = 0; i < nameSeed.size ();i++){
        string name = "选手";
        name += nameSeed[i];

//        创建具体选手
        Speaker sp;
        sp.m_Name = name;
//        分数置空
        for (int j = 0; j < 2; ++j) {
            sp.m_Score[j] = 0;
        }

        //12名选手编号   创建选手编号  并且放入到v1容器中
        this->v1.push_back(i+10001);

        //选手编号 以及对应的选手 存放到map容器中
        this->m_Speaker.insert(make_pair(i+10001,sp));
    }
}

//    6.3.4开始比赛成员函数添加
//开始比赛-比赛流程控制   比赛整个流程的控制函数
void SpeechManager::startspeech(){
    //第一轮比赛
    //1、抽签
    this->speechDraw();

    //2、比赛
    this->speechContest();

    //3、显示晋级结果
    this->showScore();


    //第二轮比赛
    this->m_Index++;
    //1、抽签
    this->speechDraw();
    //2、比赛
    speechContest();
    //3、显示最终结果
    this->showScore();


    //4、保存分数
    this->saveRecord();

//    重置比赛，获取记录，相当于又做了一次构造函数初始化
//    初始化属性
    this->initspeech();
//    创建选手
    this->createSpeaker();
//    加载往届记录
    this->loadRecord();

    cout<<"本届比赛完毕！"<<endl;

    system("pause");//按任意键继续
    system("cls");//清屏1
}

//    6.3.5抽签
void SpeechManager::speechDraw(){
    cout<<"第<<"<< this->m_Index<<">>轮比赛选手正在抽签"<<endl;
    cout<<"———————————————————————"<<endl;
    cout<<"抽签后演讲顺序如下："<<endl;

    if(this->m_Index == 1){
        //第一轮比赛  random_shuffle洗牌算法
        random_shuffle(v1.begin(),v1.end());
        for(vector<int>::iterator it=v1.begin();it!=v1.end();it++){
            cout<<*it<<" ";
        }
        cout<<endl;
    } else{
        //第二轮比赛
        random_shuffle(v2.begin(),v2.end());
        for(vector<int>::iterator it=v2.begin();it!=v2.end();it++){
            cout<<*it<<" ";
        }
        cout<<endl;
    }
    cout<<"———————————————————————"<<endl;
    system("pause");
}


//    6.3.6开始比赛
void SpeechManager::speechContest(){
    cout<<"—————————第"<< this->m_Index<<"轮比赛正式开始————————"<<endl;

    //准备临时容器 存放小组成绩  临时   multimap可重复
    multimap<double,int,greater<double>> groupScore;

    int num = 0;//记录小组人员个数 6

    vector<int>v_Src;//比赛选手容器
    if(this->m_Index == 1){
        v_Src = v1;
    } else{
        v_Src = v2;
    }

//    遍历所有选手进行比赛
    for(vector<int>::iterator it=v_Src.begin();it!=v_Src.end();it++){
        num++;
        //评委打分
        deque<double>d;
        for (int i = 0; i < 10; ++i) {
            double score = (rand()%401+600)/10.f;//600~1000  除10 为60~100

//        测试打印12个人的所有成绩，每个人有10个评委打分
//            cout<<score<<" ";
//            cout<<score<<"\t";//不太整齐

            d.push_back(score);
        }
//        cout<<endl;

//        排序
        sort(d.begin(),d.end(),greater<double>());//douoble类型的匿名对象

        d.pop_front();//去除最高分
        d.pop_back();//去除最低分

//        求总分
        double sum = accumulate(d.begin(),d.end(),0.0f);

//        求平均分  double强转小数类型
        double avg = sum/(double)d.size();

//        测试打印平均分
//        cout<<"编号："<<*it
//            <<"姓名："<<this->m_Speaker[*it].m_Name
//            <<"获取平均分："<<avg<<endl;

//        将平均分放入到map容器 里面  *it是选手编号
        this->m_Speaker[*it].m_Score[this->m_Index-1] = avg;


//        将打分数据放入到临时小组容器中
        groupScore.insert(make_pair(avg,*it));//key值avg是平均分，value值*it是选手编号

//        每6人取出前三名
        if(num%6 == 0){
            cout<<"第"<<num/6<<"小组比赛名次："<<endl;
            for(multimap<double,int,greater<double>>::iterator it=groupScore.begin();it!=groupScore.end();it++){
                cout<<"编号："<<it->second
                    <<"姓名："<< this->m_Speaker[it->second].m_Name
                    <<"成绩："<< this->m_Speaker[it->second].m_Score[m_Index-1]<<endl;
                //在选手multimap容器的value值(second)中,取出成绩m_Score，[m_Index-1]代表数组下标减一
            }

//            取走前三名
            int count = 0;
            for(multimap<double,int,greater<double>>::iterator it=groupScore.begin();it!=groupScore.end() && count<3;it++,count++){
                if(this->m_Index == 1){//如果是第一轮
                    v2.push_back((*it).second);
                } else{
                    vVictory.push_back((*it).second);//如果是第二轮，那就取晋级选手vVictory
                }
            }
//            第一组比赛完之后小组容器成绩清空，不清空会导致输出剩余的人员
            groupScore.clear();
            cout<<endl;
        }

    }
    cout<<"————————————第"<< this->m_Index<<"轮比赛完毕！————————————"<<endl;
//    cout<<endl;
    system("pause");
}

//    6.3.7显示比赛分数  比赛结果
void SpeechManager::showScore(){
    cout<<"—————————第"<< this->m_Index<<"轮晋级选手信息如下————————"<<endl;

    vector<int>v;
    if(this->m_Index == 1){
        v = v2;
    } else{
        v = vVictory;
    }
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<"选手编号："<<*it
            <<"姓名："<< this->m_Speaker[*it].m_Name
            <<"成绩："<< this->m_Speaker[*it].m_Score[m_Index-1]<<endl;
    }
    cout<<endl;

    system("pause");//按任意键继续
    system("cls");//清屏
    show_Menu();//显示主菜单 多调用了一次，后面解决

}

//    6.4保存分数   保存记录
void SpeechManager::saveRecord(){
//    创建文件
    ofstream ofs;
//    用追加的方写文件
//    ofs.open("speech.csv",ios::out|ios::app);
    ofs.open(FILENAME,ios::out|ios::app);

//    将每个选手的数据 写入到文件中
    for(vector<int>::iterator it=vVictory.begin();it!=vVictory.end();it++){
//        *it 选手编号   csv文件需要用 , 逗号 分割识别
        ofs<<*it<<","<< this->m_Speaker[*it].m_Score[1]<<",";
    }
    ofs<<endl;

//    关闭文件
    ofs.close();
    cout <<"记录已经保存"<<endl;

//    更改文件不为空的状态
    this->fileIsEmpty = false;
}

//    7.1读取记录分数
void SpeechManager::loadRecord(){
    ifstream ifs("speech.csv",ios::in);//读文件
    if(!ifs.is_open()){
        this->fileIsEmpty = true;
//        cout<<"文件不存在"<<endl;//测试代码
        ifs.close();
        return;
    }

//    文件清空情况
    char ch;
    ifs>>ch;//观察能不能读出来
    if(ifs.eof()){
//        cout<<"文件为空"<<endl;//测试代码
        this->fileIsEmpty = true;
        ifs.close();
        return;
    }

//    文件不为空
    this->fileIsEmpty = false;

    ifs.putback(ch);//将上面读取的单个字符，放回来

    string data;//拿到一串字符串出来
    int index = 0;//默认现在是第0届信息

    while (ifs>>data){
        //测试代码  先拿到字符串，然后进行解析
//        cout<<data<< endl;
//        10002,86.675,10009,81.3,10007,78.55,

        vector<string>v;//存放6个字符的字符串
        //zhangsan@sina.com   zhangsan
        int pos = -1;;//查到","位置的变量
        int start = 0;//起始位置为0

        while (true){
            pos = data.find(",",start);
            if(pos == -1){
                //没有找到的情况
                break;
            }
            string temp = data.substr(start,pos-start);
//            cout<<temp<<endl;//不用输出
            v.push_back(temp);//直接放入容器

            start = pos+1;//起始位置变了
        }

//        每届数据追加到容器内
        this->m_Record.insert(make_pair(index,v));
        index++;//第一届
    }
    ifs.close();

//    测试往届冠军信息  详见showRecord()
//    for(map<int,vector<string>>::iterator it=this->m_Record.begin();it!=this->m_Record.end();it++){
//        cout<<"第"<<it->first+1<<"届 "
//            <<"冠军编号："<<it->second[0]
//            <<" 分数："<<it->second[1]<<endl;
//    }
}

//    7.2查看记录功能  显示往届记录
void SpeechManager::showRecord(){
    //先判断文件是否存在
    if(this->fileIsEmpty){
        cout<<"文件为空或文件不存在！"<<endl;
    } else{
//    按照上面迭代器的方式写也可以
        for (int i = 0; i < this->m_Record.size(); ++i) {
            cout<<"第"<<i+1<<"届 "
                <<"冠军编号："<< this->m_Record[i][0]//第i届，第0个
                <<"得分："<<this->m_Record[i][1]

                <<"\t亚军编号："<< this->m_Record[i][2]//第i届，第2个
                <<"得分："<<this->m_Record[i][3]

                <<"\t季军编号："<< this->m_Record[i][4]//第i届，第4个
                <<"得分："<<this->m_Record[i][5]<<endl;
        }
    }
    system("pause");//按任意键继续
    system("cls");//清屏
}

//    8.1清空记录功能实现
void SpeechManager::clearRecord(){

    cout<<"是否确定清空文件？"<<endl;
    cout<<"1、是"<<endl;
    cout<<"2、否"<<endl;

    int select = 0;//选择

    cin>>select;
    if(select == 1){
//        确认清空speech.csv
//        ofstream ofs("speech.csv",ios::trunc);
        ofstream ofs(FILENAME,ios::trunc);
        ofs.close();

//      初始化属性
        this->initspeech();
//      创建选手
        this->createSpeaker();
//      加载往届记录
        this->loadRecord();

        cout<<"清空成功！"<<endl;

        //    更改文件不为空的状态
        this->fileIsEmpty = true;
    }

    system("pause");//按任意键继续
    system("cls");//清屏
}


//    析构函数
SpeechManager::~SpeechManager(){

}