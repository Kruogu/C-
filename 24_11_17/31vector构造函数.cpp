//
// Created by tianya on 2024/11/17.
//

#include "iostream"
using namespace std;
#include "vector"//������ͷ�ļ�
#include "algorithm"//��׼�㷨ͷ�ļ�


//3.2.2 vector���캯��

//vector<T> v;                  //����ģ��ʵ����ʵ�֣�Ĭ�Ϲ��캯��
//vector(v.begin(),v.end());    //��v[begin(0,end))�����е�Ԫ�ؿ���������
//vector(n,elem);               //���캯����n��elem����������
//vector(const vector &vec);    //�������캯����

void printVector(vector<int> &v){//����������
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test01(){
    vector<int>v1;//Ĭ�Ϲ���  �޲ι���

    for(int i=0;i<10;i++){
        v1.push_back(i);
    }
    printVector(v1);

//    ͨ�����䷽ʽ���й���
    vector<int>v2(v1.begin(),v1.end());
    printVector(v2);

//    n��elem����
    vector<int>v3(10,100);//10��100
    printVector(v3);

//    �������캯��
    vector<int>v4(v3);
    printVector(v4);
}
int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
