//
// Created by tianya on 2024/11/3.
//

#include "iostream"
using namespace std;
#include "fstream"

//�ı��ļ� ���ļ�
void test01(){
//    1������ͷ�ļ� fstream
//    2������������
    ifstream ifs;

//    3�����ļ������ж��Ƿ�򿪳ɹ�
//    ifs.open("test.txt",ios::in);
    ifs.open("Person.txt",ios::in);//ֻ�е�һ�ֺ͵ڶ��ֿ�����������������������������
//    ifs.open("E:\\0Work\\0workspace\\test.txt",ios::out);//��������
//    ifs.open("E:\0Work\0workspace\test1.txt",ios::out);//��������

    if(ifs.is_open()==1){//���� 1 Ҳ�� ���Զ�Ϊ�棬ǰ��ӣ����Ǽ�
        cout<<"�ļ��򿪳ɹ�"<<endl;
    } else{
        cout<<"�ļ���ʧ��"<<endl;
        return;//��������
    }

//    4��������  ָ���򿪷�ʽ
//    ��һ��
//    char buf[1024] = {0};//�ַ�����  �ļ��е�����ȫ���Ž���
//    while (ifs>>buf){//���������  ifs�����buf��
//        cout<<buf<<endl;
//    }

//    �ڶ���
    char buf[1024] = {0};
    while (ifs.getline(buf,sizeof(buf))){// getline ��ȡһ��   buf����ͷ��ַ  sizeof����1024
        cout<<buf<<endl;
    }

//    ������
//    string buf;//�ַ���
//    //���ļ������������ ifs �ŵ�  buf��
//    while (getline(ifs,buf)){//�����getline��ȫ�ֺ���
//        cout<<buf<<endl;
//    }

//    ������  ��̫�Ƽ���  Ч�ʵ�
//    char c;//�ļ��е��ַ�һ��һ����ȡ����  �ŵ�c��
//    //EOF end of file   �ļ�β����־
//    while ((c=ifs.get())!=EOF) {//���û�ж����ļ�βEOF����һֱ����ȥ
//        cout<<c;//���ܼ� endl
//    }
//    5���ر��ļ�
    ifs.close();
}

int main(){
    test01();
    cout<<"HelloWorld"<<endl;
    return 0;
}
