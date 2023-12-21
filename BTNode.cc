#include <iostream>

typedef struct BTNode    //二叉树
{
    int data;
    struct BTNode *lchild;
    struct BTNode *rchild;
}BiTNode,*BiTree;

typedef struct ThredNode //线索二叉树节点
{
    int data;
    struct ThredNode *lchild;
    struct ThredNode *rchild;
    int ltag;
    int rtag;
}ThredNode,*ThreadTree;
void Pop();

void Push();

void InitStack();

void visit();

void IsEmpty();

void EnQueue();

void InetQueue();


void PreOrder(BiTree T)    //先序遍历递归算法
{
    if(T!=NULL)
    {
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

void PreOrder2(BiTree T)    //先序遍历非递归算法
{
    InitStack(S);
    BiTree p=T;
    while(p||IsEmpty(s))
    {
        if(p)
        {
            visit(p);
            Push(s,p);
            p=p->lchild;
        }
        else
        {
            Pop(s,p);
            p=p->rchild;
        }
    }
}

void InOrder(BiTree T)    //中序遍历递归算法
{
    if(T!=NULL)
    {
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}

void Inorder2(BiTree T)    //中序遍历非递归算法
{
    InitStack(s);
    BiTree p=T;
    while(p||!IsEmpty(s))
    {
        if(p)
        {
            Push(s,p);
            p=p->lchild;
        }
        else
        {
            Pop(s,p);
            visit(p);
            p=p->rchild;
        }
    }
}

void PostOrder(BiTree T)    //后序遍历递归算法
{
    if(T!=NULL)
    {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}

void LevelOrder(BiTree T)    //层序遍历递归算法
{
    InitQueue(Q);
    BiTree p;
    EnQueue(Q,T);
    while(!IsEmpty(Q))
    {
        DeQueue(Q,p);
        visit(p);
        if(p->lchild!=NULL)
            EnQueue(Q,p->lchild);
        if(p->rchild!=NULL)
            EnQueue(Q,p->rchild);
    }
}

int main()
{
    
    return 0;
}