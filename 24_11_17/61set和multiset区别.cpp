//
// Created by tianya on 2024/11/19.
//
#include "iostream"
using namespace std;
#include "set"
//3.8.6set���� �� multiset���� ����

//        set�����Բ����ظ����ݣ���multiseti����
//        set�������ݵ�ͬʱ�᷵�ز���������ʾ�����Ƿ�ɹ�
//        multiset���������ݣ���˿��Բ����ظ�����


void test01(){
    set<int>s1;

//    �������� ֻ��insert��ʽ
//    s1.insert(30);//�ظ�û��
//    s1.insert(30);//ͨ���鿴insertԴ����Է���Դ������pair���ڶ���λ����bool�������ͣ�����Ƿ�ɹ�

//    ͨ��pair�鿴�Ƿ����ɹ�   �ظ����ݾͻᵼ�²���ʧ��
    pair<set<int>::iterator,bool> ret = s1.insert(10);//�ڶ���

//    ���Ϊ��ͳɹ�������ʧ��
    if(ret.second){//���ret�еڶ���boool���ݣ���һ����int����
        cout<<"��һ�β���ɹ�"<<endl;
    } else{
        cout<<"��һ�β���ʧ��"<<endl;
    }

    ret = s1.insert(10);
    if(ret.second){//���ret�еڶ���boool���ݣ���һ����int����
        cout<<"�ڶ��β���ɹ�"<<endl;
    } else{
        cout<<"�ڶ��β���ʧ��"<<endl;
    }


    multiset<int>ms;
//    ��������ظ�ֵ   ��set��һ��   ���Զ�����������
    ms.insert(10);//�����insertԴ�����������������set��һ��
    ms.insert(10);
    ms.insert(10);
    ms.insert(10);

    for(multiset<int>:: iterator it=ms.begin();it!=ms.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
