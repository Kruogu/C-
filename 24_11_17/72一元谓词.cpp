//
// Created by tianya on 2024/11/20.
//
#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"
//4.2.2һԪν��

//�º�������ֵ������bool�������ͣ���Ϊν��
//һԪν��

class GreaterFive{
public:
    bool operator()(int val){
        return val>5;
    }
};

void test01(){
    vector<int>v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }

//    ���������� ��û�д���5������
    //��������  ���俪ʼ������  ν��(������������Ҳ����) GreaterFive()������������
//    ���ص��ǵ�����
    vector<int>::iterator it = find_if(v.begin(),v.end(),GreaterFive());
    if(it == v.end()){
        cout<<"δ�ҵ�"<<endl;
    } else{
        cout<<"�ҵ��˴���5������Ϊ��"<<*it<<endl;//�ҵ��˴���5������Ϊ��6
    }
}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
