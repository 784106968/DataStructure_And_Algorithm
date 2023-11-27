//
// Created by 78410 on 2023/11/27.
//
//循环队列：
#include <iostream>

using namespace std;
#define MAXSIZE 10
typedef struct{
    int data[MAXSIZE];
    int front;//队头指针
    int rear;//队尾指针
}SqQueue;

//队列的初始化
void InitQueue(SqQueue &Q){
    Q.front=Q.rear=0;
}

//判空操作
bool QueueEmpty(SqQueue Q){
    if(Q.front==Q.rear){
        return true;
    }
    else{
        return false;
    }
}

//入队操作：
bool EnQueue(SqQueue &Q,int x){
    if((Q.rear+1)%MAXSIZE==Q.front){
        return false;
    }
    Q.data[Q.rear]=x;
    Q.rear=(Q.rear+1)%MAXSIZE;
    return true;
}

//出队操作：
bool DestoryQueue(SqQueue &Q,int &x){
    if(Q.rear==Q.front){//判空
        return false;
    }
    x=Q.data[Q.front];
    Q.front=(Q.front+1)%MAXSIZE;
    return true;
}

//获取队列头元素：
bool GetHead(SqQueue Q,int &x){
    if(Q.front==Q.rear){
        return false;
    }
    x=Q.data[Q.front];
    return true;
}

int main(){


    return 0;
}