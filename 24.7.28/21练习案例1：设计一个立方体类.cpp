//
// Created by tianya on 2024/7/29.
//
#include "iostream"
using namespace std;
//��ϰ����1�����һ����������
//    1.������������(Cube)
//    2.��������������
//    3.�����Ϊ ������������������
//    4.�ֱ���ȫ�ֺ����ͳ�Ա�����ж������������Ƿ����
//    5.m��mumber��Ա����˼



class Cube{

public://��Ϊ  set��ȡ������� �� �� ��   get����������� �� �� ��
    void setL(int l){
        m_L = l;
    }
    int getL(){
        return m_L;
    }
    void setW(int w){
        m_W = w;
    }
    int getW(){
        return m_W;
    }
    void setH(int h){
        m_H = h;
    }
    int getH(){
        return m_H;
    }
//    ��������������  û��Ҫ
//    void setArea(int l,int w){
//        m_area = l*w;
//    }
//    ��ȡ������ı����
//    calculateS(){ //����S  д��������
    int getArea(){
//        return m_area;    //����ֱ�Ӽ���
        return 2 * (m_L*m_W + m_W*m_H + m_L*m_H);
    }
//    ��������������  û��Ҫ
//    void setVolume(int l,int w,int h){
//        m_volume = l*w*h;
//    }
//    ��ȡ����������
//    calculateV(){ //����V  д��������
    int getVolume(){
//        return m_volume;  û��Ҫ
        return m_L*m_W*m_H;
    }

//    ���ó�Ա�����ж������������Ƿ����
    bool isSameByClass(Cube &c){   //ֵ���� ���þͲ��´��һ�������ˣ���ԭʼ�������ж�
        if(m_L ==c.getL() && m_W==c.getW() && m_H==c.getH()){
            return true;    //�����������������
        }
        return false;   //�������������岻���
    }
private://����
    int m_L;    //��
    int m_W;    //��
    int m_H;    //��
    int m_area;   //�����
//    int m_volume = m_L*m_W*m_H; //��� ���ܼ���
    int m_volume; //���
};

//ȫ�ֺ��� ��Ҫ�������������������ȥ�ſ������ж�
//��Ա���� ֻ��Ҫ����һ�������������ȥ�Ϳ������ж�
//����ȫ�ֺ����ж������������Ƿ����
bool isSame(Cube &c1,Cube &c2){   //ֵ���� ���þͲ��´��һ�������ˣ���ԭʼ�������ж�
    if(c1.getL()==c2.getL()&&c1.getW()==c2.getW()&&c1.getH()==c2.getH()){
        return true;    //�����������������
    }
    return false;   //�������������岻���
}

int main(){

//    ʵ����һ�����������
    Cube c1;    //������һ�����������
    c1.setL(10);
    c1.setW(20);
    c1.setH(30);
    cout<<"����"<<c1.getL()<<endl;
    cout<<"��"<<c1.getW()<<endl;
    cout<<"�ߣ�"<<c1.getH()<<endl;
//    c.setArea(10,20); û��Ҫ��������
    cout<<"c1�������"<<c1.getArea()<<endl;
//    c.setVolume(10,20,30);  û��Ҫ��������
    cout<<"c1�����"<<c1.getVolume()<<endl;

    Cube c2;    //�����ڶ������������
    c2.setL(10);
    c2.setW(20);
    c2.setH(20);
    cout<<"c2�������"<<c2.getArea()<<endl;
    cout<<"c2�����"<<c2.getVolume()<<endl;

//    ��ȫ�ֺ����ж������������Ƿ����
    bool ret1 = isSame(c1,c2);
    if(ret1){
        cout<<"ȫ�ֺ����жϣ�c1��c2����ȵ�"<<endl;
    } else{
        cout<<"ȫ�ֺ����жϣ�c1��c2�ǲ���ȵ�"<<endl;
    }

//    �ó�Ա�����ж������������Ƿ����
    int ret2 = c1.isSameByClass(c2); //��c2��c1���Ա�  ������c1��c2 ������
    if(ret2){
        cout<<"��Ա�����жϣ�c1��c2����ȵ�"<<endl;
    } else{
        cout<<"��Ա�����жϣ�c1��c2�ǲ���ȵ�"<<endl;
    }

    cout<<"HelloWorld"<<endl;
    return 0;
}
