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

//3.2.5 vector�����ɾ��

//push_back(ele);                                       //β������Ԫ��ele
//pop_back();                                           //ɾ�����һ��Ԫ��
//insert(const iterator pos,ele);                       //������ָ��λ��pos����Ԫ��ele
//insert(const_iterator pos,int count,ele);             //������ָ��λ��pos����count��Ԫ��ele
//erase(const_iterator pos);                            //ɾ��������ָ���Ԫ��
//erase(const_iterator start,const_iterator end);       //ɾ����������start��end֮���Ԫ��
//clear();                                              //ɾ������������Ԫ��

void test01(){
    vector<int>v1;
    //β�巨
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);
    printVector(v1);

    //βɾ��
    v1.pop_back();//50û��
    printVector(v1);

    //����  ��һ�������ǵ�����
    v1.insert(v1.begin(),100);//ͷ������100
    printVector(v1);

    v1.insert(v1.begin(),2,1000);//ͷ����������1000
    printVector(v1);

    v1.insert(v1.begin()+1,33);//�ڶ���λ�ò���22
    printVector(v1);

    //ɾ��
    v1.erase(v1.begin());//ɾ����һ��
    printVector(v1);

    //�൱�������
//    v1.erase(v1.begin(),v1.end());//��ͷ��βȫɾ
    v1.clear();//��պ�������һ��д��Ҳ���ԣ���ѡһ
    printVector(v1);


}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
