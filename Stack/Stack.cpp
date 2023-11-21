//
// Created by 78410 on 2023/11/21.
//

#include<iostream>

using namespace std;

#define MAXSIZE 10
//栈初始数据结构
typedef struct Stack{
    int data[MAXSIZE];
    int top;
}MyStack;

//初始化栈
void InitStack(MyStack &S){
    S.top=-1;//初始化栈顶指针
}

//新元素入栈
bool Push(MyStack &S,int x){
    if(S.top==MAXSIZE-1){
        return false;
    }
//    S.top++;
//    S.data[S.top]=x;
//    简化代码：
    S.data[++S.top]=x;
    return true;
}

//删除栈顶元素：
bool Pop(MyStack &S,int &x){
    if(S.top==-1){
        return false;
    }
//    x=S.data[S.top];
//    S.top--;
//    简化代码：
    x=S.data[S.top--];
    return true;
}

//读取栈顶元素：
bool GetTop(MyStack S,int &x){
    if(S.top==-1){
        return false;
    }
    x=S.data[S.top];
    return true;
}

int main(){


    return 0;
}