//
// Created by tianya on 2024/11/18.
//
#include "iostream"
using namespace std;
#include "vector"//������ͷ�ļ�

void printVector(vector<int> &v){//����������
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

//3.2.8 vectoriԤ���ռ�
//reserve(int len);     //����Ԥ��len��Ԫ�س��ȣ�Ԥ��λ�ò���ʼ����Ԫ�ز��ɷ��ʡ�

void test01(){
    vector<int>v;
//    ����reserveԤ���ռ�
    v.reserve(100000);//�������� num����1������num=18
    int num = 0;//ͳ�ƿ��ٴ���
    int *p = NULL;
    for(int i=0;i<100000;i++){//��Ҫ����
        v.push_back(i);//0-99999

        if(p!= &v[0]){
            p = &v[0];
            num++;
        }
    }
    cout<<"num = "<<num<<endl;//18  �����ظ�������18�οռ䣬ֱ���ҵ��ܴ��100000��С�Ŀռ�

    cout<<"v������Ϊ��"<<v.capacity()<<endl;//v������Ϊ��131072
    cout<<"v�Ĵ�СΪ��"<<v.size()<<endl;//v�Ĵ�СΪ��100000

}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
