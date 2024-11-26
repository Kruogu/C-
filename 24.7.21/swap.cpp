//
// Created by tianya on 2024/7/22.
//

#include "swap.h"
//#include <iostream>
//using namespace std;

int main(){
    int a=2,b=3;
    swap(a,b);

    cout<<"HelloWorld嘿哈嘿"<<endl;
    return 0;
}
void swap(int a,int b){
    int temp = a;
    a = b;
    b = temp;
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;
}