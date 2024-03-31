//带头结点的单链表
//带头结点方便寻找第一个元素开始的位置
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

typedef struct Lnode{
    struct Lnode *next;
    int data;
}Lnode,*LinkList;//这里的LinkList本身就已经是指针形式了

bool InitList(LinkList &L);
bool ListInsert(LinkList &L,int i,int e);
Lnode * GetElem(LinkList L,int i);
Lnode * LocateElem(LinkList L,int e);
int Length(LinkList L);
bool Empty(LinkList L);
bool InsertNextNode(Lnode *p,int e);
void print(LinkList L);
bool DeleteList(LinkList &L,int i,int &e);

bool InitList(LinkList &L){
    L=(LinkList)malloc(sizeof(Lnode));//在开辟空间时可以直接使用LinkList进行开辟
    if(L==NULL){					//但是要注意不能使用LinkList*
        return false;
    }
    L->next=NULL;
    return true;
}

LinkList TailCreate(LinkList &L,int length){//尾插法建立单链表
    L=(LinkList)malloc(sizeof(Lnode));
    Lnode *end=L;
    int i=0;
    while(i<length){
        Lnode *p=(Lnode*)malloc(sizeof(Lnode));
        scanf("%d",&p->data);
        end->next=p;
        end=p;
        i++;
    }
    end->next=NULL;
    return L;
}

LinkList HeadCreate(LinkList &L,int length){
    InitList(L);
    int i=0;
    while(i<length){
        Lnode *p=(Lnode*)malloc(sizeof(Lnode));
        scanf("%d",&p->data);
        p->next=L->next;
        L->next=p;
        i++;
    }
    return L;
}

Lnode * GetElem(LinkList L,int i){//按位查找第i个位置的节点
    int j=1;
    Lnode *p=L->next;
    if(i==0){
        return L;
    }
    if(i<1){
        return NULL;
    }
    while(p!=NULL&&j<i){
        p=p->next;
        j++;
    }
    return p;
}

Lnode * LocateElem(LinkList L,int e){//按值查找特定节点
    Lnode *p=L->next;
    while(p!=NULL&&p->data!=e){
        p=p->next;
    }
    return p;
}

int Length(LinkList L){
    int len=0;
    Lnode *p=L;
    while(p->next!=NULL){
        p=p->next;
        len++;
    }
    return len;
}

bool ListInsert(LinkList &L,int i,int e){//在指定位置按位插入节点
    if(i<1){
        return false;
    }
    Lnode *p=GetElem(L,i-1);
//	int j=0;
//	while(p!=NULL&&j<i-1){
//		p=p->next;
//		j++;
//	}
    return InsertNextNode(p,e);
}

bool Empty(LinkList L){//判断链表是否非空
    return (L->next==NULL);
}

bool InsertNextNode(Lnode *p,int e){//在指定节点后插入数据（后插法）
    if(p==NULL){
        return false;
    }
    Lnode *s=(Lnode*)malloc(sizeof(Lnode));
    s->data=e;
    s->next=p->next;
    p->next=s;
    return true;
}

bool InsertPriorNode(Lnode *p,int e){//在指定节点的前面插入数据
    if(p==NULL){
        return false;
    }
    Lnode *s=(Lnode*)malloc(sizeof(Lnode));
    if(s==NULL){
        return false;
    }
    s->next=p->next;
    p->next=s;
    s->data=p->data;
    p->data=e;
    return true;
}

bool DeleteList(LinkList &L,int i,int &e){//删除指定位置的节点
    if(i<1){
        return false;
    }
    Lnode *p=GetElem(L,i-1);
//	int j=0;
//	while(p!=NULL&&j<i-1){
//		p=p->next;
//		j++;
//	}
    if(p==NULL){
        return false;
    }
    Lnode *q=p->next;
    e=q->data;
    p->next=q->next;
    free(q);
    return true;
}

void print(LinkList L){
    Lnode *p=L->next;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int main(){
    LinkList L;
    InitList(L);
    HeadCreate(L,5);
    print(L);
    ListInsert(L,1,10);
    print(L);

    system("pause");
    return 0;
}