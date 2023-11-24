//
// Created by 78410 on 2023/11/24.
//

#include<iostream>
#include<cstdio>
#include<stdlib.h>

using namespace std;

typedef struct LinkNode{
    int data;
    struct LinkNode* next;
}*LiStack;

bool InitStack(LiStack &S){
    S=(LiStack) malloc(sizeof(LinkNode));
    if(S==NULL) return false;
    S->next=NULL;
    return true;
}
//进栈（前插法）
bool Push(LiStack &S,int x){
    LinkNode *p=(LinkNode*)malloc(sizeof (LinkNode));
    p->data=x;
    p->next=S->next;
    S->next=p;
    return true;
}
//栈顶出栈
int Pop(LiStack &S){
    if(S->next==NULL) return false;
    LinkNode *p=S->next;
    int x=p->data;
    S->next=p->next;
    free(p);
    return x;
}

//获取栈顶元素：
int Top(LiStack &S){
    if(S->next==NULL) return false;
    return S->next->data;
}


int main(){
    LiStack S;
    InitStack(S);
    Push(S,5);
    Push(S,6);
    Push(S,7);
    Push(S,8);
    cout<<Pop(S)<<endl;
    cout<<Pop(S)<<endl;
    cout<<Pop(S)<<endl;
    cout<<Pop(S)<<endl;
    return 0;
}