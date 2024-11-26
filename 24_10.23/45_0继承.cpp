//
// Created by tianya on 2024/10/23.
//
#include "iostream"
using namespace std;

//普通实现页面

//Java页面
class Java{
public:
    void header(){//公共头部
        cout<<"首页、公开课、登录、注册...(公共头部)"<<endl;
    }
    void footer(){//公共底部
        cout<<"帮助中心、交流合作、站内地图...(公共底部)"<<endl;
    }
    void left(){//左侧列表
        cout<<"Java、Python、C++...(公共分类列表)"<<endl;
    }
    void content(){
        cout<<"Java学科视频"<<endl;
    }
};



//Python页面
class Python{
public:
    void header(){//公共头部
        cout<<"首页、公开课、登录、注册...(公共头部)"<<endl;
    }
    void footer(){//公共底部
        cout<<"帮助中心、交流合作、站内地图...(公共底部)"<<endl;
    }
    void left(){//左侧列表
        cout<<"Java、Python、C++...(公共分类列表)"<<endl;
    }
    void content(){
        cout<<"Python学科视频"<<endl;
    }
};

//C++页面
class CPP{
public:
    void header(){//公共头部
        cout<<"首页、公开课、登录、注册...(公共头部)"<<endl;
    }
    void footer(){//公共底部
        cout<<"帮助中心、交流合作、站内地图...(公共底部)"<<endl;
    }
    void left(){//左侧列表
        cout<<"Java、Python、C++...(公共分类列表)"<<endl;
    }
    void content(){
        cout<<"C++学科视频"<<endl;
    }
};

void test01(){
    cout<<"Java下载视频页面如下："<<endl;
    Java ja;
    ja.header();
    ja.footer();
    ja.left();
    ja.content();

    cout<<"————————————————————"<<endl;//分割线
    cout<<"Python下载视频页面如下："<<endl;
    Python py;
    py.header();
    py.footer();
    py.left();
    py.content();

    cout<<"————————————————————"<<endl;//分割线
    cout<<"C++下载视频页面如下："<<endl;
    CPP cpp;
    cpp.header();
    cpp.footer();
    cpp.left();
    cpp.content();
}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
