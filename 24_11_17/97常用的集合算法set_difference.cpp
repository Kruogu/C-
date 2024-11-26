//
// Created by tianya on 2024/11/21.
//

#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"
//5.6.3 ���õļ����㷨set_difference

//����������
//    �����������ϵĲ
//
//����ԭ�ͣ�
//    ��set_difference(iterator beg1,iterator end1,iterator beg2,iterator end2,iterator dest);
    //���������ϵĲ
    //ע�⣺�������ϱ�������������
    //beg1����1��ʼ������
    //end1����1���������
    //beg2����2��ʼ������
    //end2����2����������
    //destĿ��������ʼ������




//�º�����ӡ
class MyPrint{
public:
    void operator()(int val){
        cout<<val<<" ";
    }
};

void test01(){
    vector<int>v1;
    vector<int>v2;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);//0~9
        v2.push_back(i+5);//5~14
    }
    cout<<"v1��"<<endl;
    for_each(v1.begin(),v1.end(), MyPrint());//�º���
    cout<<endl;
    cout<<"v2��"<<endl;
    for_each(v2.begin(),v2.end(), MyPrint());//�º���
    cout<<endl;

    //����Ŀ������
    vector<int>vTarget;

//    ��Ŀ���������ٿռ�
//    �����������������û�н�����Ҫȡ���������д��size��Ϊ���ٿռ�
    vTarget.resize(max(v1.size(),v2.size()));//��ǰ���ٿռ�

//    ��ȡ�  itEnd�� it�����һ��λ��       ����Ŀ�����������һ��Ԫ�صĵ�������ַ
    vector<int>::iterator itEnd = set_difference(v1.begin(),v1.end(),v2.begin(),v2.end(),vTarget.begin());

    cout<<"v1��v2�ĲΪ��"<<endl;
    for_each(vTarget.begin(),itEnd, MyPrint());//�º���  ������itEnd����
//    for_each(vTarget.begin(),vTarget.end(), MyPrint());//�º��� ����������������5���ռ�
    cout<<endl;

//    ��ȡ�  itEnd�� it�����һ��λ��       ����Ŀ�����������һ��Ԫ�صĵ�������ַ
    itEnd = set_difference(v2.begin(),v2.end(),v1.begin(),v1.end(),vTarget.begin());

    cout<<"v2��v1�ĲΪ��"<<endl;
    for_each(vTarget.begin(),itEnd, MyPrint());//�º���  ������itEnd����
//    for_each(vTarget.begin(),vTarget.end(), MyPrint());//�º��� ����������������5���ռ�
    cout<<endl;
}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
