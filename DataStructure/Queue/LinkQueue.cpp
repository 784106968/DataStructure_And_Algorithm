//
// Created by 78410 on 2024/4/15.
//
#include<iostream>

using namespace std;

typedef struct LinkNode{
    int data;
    struct LinkNode* next;
}LinkNode;

//对于每一个队列，其内必包含头尾两指针
typedef struct {
    LinkNode* front;
    LinkNode* rear;
}LinkQue;

//头尾指针初始化
void InitQueue(LinkQue &q){
    LinkNode *p=new LinkNode;
    if (!p)
    {
        cout << "分配内存失败" << endl;
        return;
    }
    p->next=NULL;
    q.front=q.rear=p;    //初始为空链队
}

bool isEmpty(LinkQue &q){
    if(q.front==q.rear) return true;
    return false;
}

void EnQueue(LinkQue &q,int data){
    LinkNode *p=(LinkNode*) malloc(sizeof (LinkNode));
    p->data=data;
    p->next=NULL;
    q.rear->next=p;
    q.rear=p;
}

bool DeQueue(LinkQue &q,int &data){
    if(isEmpty(q)){
        return false;
    }
    LinkNode *p=q.front->next;
    data=p->data;
    q.front->next=p->next;
    if(q.rear==p){
        q.rear=q.front;    //判断是不是最后一个数据
    }
    free(p);
    return true;
}

void printQueue(LinkQue &q){
    LinkNode *p=q.front->next;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
}

int main(){
    LinkQue q;
    InitQueue(q);
    EnQueue(q,10);
    EnQueue(q,8);
    EnQueue(q,6);
    int data;
    DeQueue(q,data);
    cout<<data<<endl;
    printQueue(q);
    return 0;
}