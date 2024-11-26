//
// Created by tianya on 2024/11/16.
//

#ifndef INC_24_11_06_MYARRAY_H
#define INC_24_11_06_MYARRAY_H

//�Լ���ͨ�õ�������
#pragma once
#include "iostream"
using namespace std;

template<class T>
class MyArray{
public:
    //�вι���
    MyArray(int capacity){
//        cout<<"Myarray�вι������"<<endl;
        this->m_Capacity = capacity;
        this->m_Size = 0;
        this->pAddress = new T[this->m_Capacity];
    }

    //��������
    MyArray(const MyArray&arr)
    {
//        cout<<"Myarray�����������"<<endl;
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
//        this->pAddress = arr.pAddress;//�������Դ�д������  ǳ����������ᵼ�¶����������ظ��ͷ�

//        ����Ҫ���������  ����newһ��ռ�
        this->pAddress = new T[arr.m_Capacity];
        //��arr�е����ݶ���������
        for(int i=0;i<this->m_Size;i++){
            this->pAddress[i] = arr.pAddress[i];
        }
    }

//    operator=��ֹǳ�����ʿ�
    MyArray& operator=(const MyArray& arr){
//        cout<<"Myarray operator=����"<<endl;
//        ���ж�ԭ�������Ƿ������ݣ������,���ͷ�
        if(this->pAddress!=NULL){
            delete [] this->pAddress;
            this->pAddress = NULL;
            this->m_Capacity = 0;
            this->m_Size = 0;
        }
//        ���
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        this->pAddress = new T[arr.m_Capacity];
        for(int i=0;i<this->m_Size;i++){
            this->pAddress[i] = arr.pAddress[i];
        }
        return *this;
    }

    //β�巨
    void Push_Back(const T &val){
        //�ж������Ƿ���ڴ�С
        if (this->m_Capacity == this->m_Size)
        {
            return;
        }
        this->pAddress[this->m_Size] = val;//������ĩβ��������
        this->m_Size++;//���������С

    }

//    βɾ��
    void Pop_Back()
    {
//        ���û����ʲ������һ��Ԫ�أ���Ϊβɾ,�߼�ɾ��
        if (this->m_Size == 0)
        {
            return;
        }
        this->m_Size--;//���������С
    }

    //ͨ���±귽ʽ���������е�Ԫ��  arr[0] = 100
    T& operator[](int index){
        return this->pAddress[index];
    }

//    ������������
    int getCapacity()
    {
        return this->m_Capacity;
    }
//    ���������С
    int getSize(){
        return this->m_Size;
    }

    //��������
    ~MyArray(){
//        cout<<"Myarray������������"<<endl;
        if(this->pAddress!=NULL){
            delete [] this->pAddress;
            this->pAddress = NULL;
        }
    }

private:
    T * pAddress;//ָ��ָ��������ٵ���ʵ����  ��ַ
    int m_Capacity;//��������   �ݻ�����������  ����������
    int m_Size;//�����С
};

#endif //INC_24_11_06_MYARRAY_H
