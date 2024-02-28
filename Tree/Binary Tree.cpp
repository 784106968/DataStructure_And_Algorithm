//
// Created by 78410 on 2024/2/20.
//

//二叉树的实现：
#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
    char data;
    struct Node *lchild,*rchild;
}*BiTree,BiNode;

//递归创建二叉树：
//按照先序遍历进行创建，无节点处使用#代替
void creatTree(BiTree& t){
    char ch;
    cin>>ch;
    if(ch=='#'){
        t=NULL;
    }
    else{
        t=new BiNode;//创建新节点
        t->data=ch;
        creatTree(t->lchild);
        creatTree(t->rchild);
    }
}

//先序递归遍历：
void PreOrder(BiNode* t){
    if(t==NULL){
        return;
    }
    cout<<t->data;
    PreOrder(t->lchild);
    PreOrder(t->rchild);
}

//中序递归遍历:
void InOrder(BiNode* t){
    if(t==NULL){
        return;
    }
    InOrder(t->lchild);
    cout<<t->data;
    InOrder(t->rchild);
}

//后序递归遍历：
void PostOrder(BiNode* t){
    if(t==NULL){
        return;
    }
    PostOrder(t->lchild);
    PostOrder(t->rchild);
    cout<<t->data;
}



//统计二叉树中节点个数：
//自底向上，首先递归到最底层，以叶子节点为例，叶子节点左右子树都递归为0，此时可计数叶子节点为1
//从叶子节点继续向上回溯，此时以叶子节点为1，向上回溯，判断是其父节点的左子树或右子树并加1
//直至回溯到根节点，得到所有节点个数
//            ()
//            /\
//          ()  ()
//          0   0
int NodeCount(BiTree t){
    if(t==NULL){
        return 0;
    }
    else
        return NodeCount(t->lchild)+ NodeCount(t->rchild)+1;
}

//求树的深度：
//不懂，再次测试递归方法：
int Depth(BiTree t){
    if(t==NULL){
        return 0;
    }
    int i= Depth(t->lchild);
    int j= Depth(t->rchild);
    return i>j?i+1:j+1;
}

//递归复制二叉树：
void Copy(BiTree t,BiTree& Newt){
    if(t==NULL){
        Newt=NULL;
        return;
    }
    Newt=new BiNode;
    Newt->data=t->data;
    Copy(t->lchild,Newt->lchild);
    Copy(t->rchild,Newt->rchild);
}

//统计二叉树中的叶子节点个数
//递归到底层，然后判断是否为叶子节点，随后累加和
int LeafCount(BiTree t){
    if(!t){
        return 0;
    }
    if(t->lchild==NULL&&t->rchild==NULL)    return 1;
    return LeafCount(t->lchild)+ LeafCount(t->rchild);
}

//判断二叉树是否为空
bool isEmpty(BiTree t){
    if(t){
        return true;
    }
    return false;
}

int main(){
    BiTree t;
    creatTree(t);


    return 0;
}