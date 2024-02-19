//
// Created by 78410 on 2024/2/18.
//
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define DEFAULT_SIZE 10

typedef struct HashNode{
    int data;
    HashNode* next;
}*Hashmap;

typedef Hashmap Hashtable[DEFAULT_SIZE];//typedef重命名数组名称，此过程可指定数组大小

bool InitHashTable(Hashtable& ht);
int Hash(int data);
bool Insert_HashTbale(Hashtable& ht,int x);
void PrintHashTable(Hashtable ht);
Hashmap SearchHashTable(Hashtable ht,int x);
bool DeleteHashTabel(Hashtable &ht,int x);

//下面开始哈希表的增删改查操作完善：
//首先是初始化：
//此处创立的是无头结点的链式哈希表
bool InitHashTable(Hashtable& ht){
    if(ht==NULL){
        return false;
    }
    for(int i=0;i<DEFAULT_SIZE;i++){
        ht[i]=NULL;
    }
    return true;
}

//其次设置映射函数：
int Hash(int data){
    return data%DEFAULT_SIZE;
}

//接下来完成向哈希表内增添数据
//元素增加采用头插法：
bool Insert_HashTbale(Hashtable& ht,int x){
    if(SearchHashTable(ht,x)!=NULL){
        return false;
    }
    //确定映射的下标
    int index=Hash(x);
    Hashmap s=(Hashmap)malloc(sizeof(HashNode));
    if(s==NULL){
        return false;
    }
    //无头节点头插法放数据：
    s->data=x;
    s->next=ht[index];
    ht[index]=s;
    return true;
}

//哈希表的显示：
void PrintHashTable(Hashtable ht){
    for(int i=0;i<DEFAULT_SIZE;i++){
        cout<<i<<":";
        Hashmap p=ht[i];
        while(p!=NULL){
            cout<<p->data<<"->";
            p=p->next;
        }
        cout<<"NULL"<<endl;
    }
}

//哈希表的数据查找：
Hashmap SearchHashTable(Hashtable ht,int x){
    int index=Hash(x);
    Hashmap p=ht[index];
    while(p){
        if(p->data==x){
            return p;
        }
        p=p->next;
    }
    return NULL;
}

//哈希表的数据删除：
bool DeleteHashTabel(Hashtable &ht,int x){
    Hashmap p= SearchHashTable(ht,x);
    if(!SearchHashTable(ht,x)){
        return false;
    }
    int index=Hash(x);
    Hashmap q=ht[index];
    if(q==p){
        ht[index]=q->next;
        free(q);
        return true;
    }
    while(q&&q->next->data!=x){
        q=q->next;
    }
    q->next=p->next;
    free(p);
    return true;
}

int main(){
    Hashtable ht;
    InitHashTable(ht);
    srand(time(0));
    for(int i=0;i<10;i++){
        int x=rand()%1000;
        cout<<x<<" ";
        Insert_HashTbale(ht,x);
    }
    PrintHashTable(ht);

}