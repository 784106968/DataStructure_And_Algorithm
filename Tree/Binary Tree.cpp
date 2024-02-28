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

//层序创建二叉树：
//与遍历类似，由队列控制数据的进出
void OrderCreatTree(BiTree& t){
    char ch;
    cin>>ch;
    queue<BiTree>q;
    if(ch!='#'){
        t=new BiNode;
        t->data=ch;
        q.push(t);
    }
    while(!q.empty()){
        //输入字符，判断左子树是否有数据
        cin>>ch;
        //存在数据，则开辟新节点，并入队列
        if(ch!='#'){
            BiNode *p=q.front();
            p->lchild=new BiNode;
            p->lchild->data=ch;
            q.push(p->lchild);
        }
        //不存在数据，直接置空
        else{
            q.front()->lchild=NULL;
        }
        //输入字符，判断右子树是否有数据
        cin>>ch;
        //右子树存在数据，开辟新节点，并入队列
        if(ch!='#'){
            BiNode *p=q.front();
            p->rchild=new BiNode;
            p->rchild->data=ch;
            q.push(p->rchild);
        }
        //不存在数据，直接置空
        else{
            q.front()->rchild=NULL;
        }
        //最后不要忘记队头节点出队
        q.pop();
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

//层序遍历二叉树：
//思路：建立先进先出队列，首先入队根节点，若队列不为空则执行如下循环：
//输出队头节点的数据，判断队头节点的左右孩子是否存在，存在则入队，判断结束后，将当前根节点（队头节点）出队
void Order(BiTree t){
    queue<BiTree>q;
    q.push(t);
    while(!q.empty()){
        cout<<q.front()->data;
        if(q.front()->lchild!=NULL){
            q.push(q.front()->lchild);
        }
        if(q.front()->rchild!=NULL){
            q.push(q.front()->rchild);
        }
        q.pop();
    }
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
    //先序创建二叉树
    //creatTree(t);
    //层序创建二叉树：
    OrderCreatTree(t);
    //先序遍历结果：
    cout<<"先序遍历：";
    PreOrder(t);
    cout<<endl;
    //中序遍历结果：
    cout<<"中序遍历：";
    InOrder(t);
    cout<<endl;
    //后序遍历结果：
    cout<<"后序遍历：";
    PostOrder(t);
    cout<<endl;
    //层序遍历结果：
    cout<<"层序遍历：";
    Order(t);
    cout<<endl;
    //统计二叉树中的节点个数：
    cout<<"二叉树中的节点个数为："<<NodeCount(t)<<endl;
    //统计二叉树的深度：
    cout<<"二叉树的深度为："<<Depth(t)<<endl;
    //统计二叉树的叶子节点个数：
    cout<<"二叉树的叶子节点个数为："<<LeafCount(t)<<endl;
    //复制二叉树：
    BiTree Newt;
    Copy(t,Newt);
    PreOrder(Newt);
    cout<<endl;
    return 0;
}