#include <iostream>
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

LinkList ListHeadInsert(LinkList &L)
{
    LNode *s;
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    printf("input:\n");
    scanf("%d", &x);
    while (x != 999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}

LinkList ListTailInsert(LinkList &L)
{
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s, *r = L;
    scanf("%d", &x);
    while (x != 999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
        r->next = NULL;
    }
    return L;
}

bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL)
        return false;
    L->next = NULL;
    return true;
}

LNode *GetElem(LinkList L, int i)
{
    int j = 1;
    LNode *p = L->next;
    if (i == 0)
        return L;
    if (i < 1)
        return NULL;
    while (p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}

bool InitList0(LinkList &L)
{
    L = NULL;
    return true;
}

bool InitList1(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL)
        return false;
    L->next = NULL;
    return true;
}

bool Empty0(LinkList L)
{
    // if (L==NULL)
    //     return true;
    // else
    //     return false;
    return (L == NULL); //The same as the up
}

bool Empty1(LinkList L)
{
    return (L->next == NULL);
}

bool ListInsert0(LinkList &L, int i, int e)
{
    if (i < 1)
        return false;
    LNode *p;
    int j = 0;
    p = L;
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool ListInsert1(LinkList &L, int i, int e)
{
    if (i < 1)
        return false;
    if (i == 1)
    {
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->data = e;
        s->next = L;
        L = s;
        return true;
    }

    LNode *p;
    int j = 1;
    p = L;
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool InsertNextNode(LNode *p, int e)
{
    if (p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL)
        return false;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool InsertPriorNode(LNode *p, int e)
{
    if (p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL)
        return false;
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;
    return true;
}

bool ListDelete0(LNode *p)
{
    if (p == NULL)
        return false;
    LNode *q = p->next;
    p->data = p->next->data;
    p->next = q->next;
    free(q);
    return true;
}

bool ListDelete1(LinkList &L, int i, int &e)
{
    if (i < 1)
        return false;
    LNode *p;
    int j = 0;
    p = L;
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
        return false;
    if (p->next == NULL)
        return false;
    LNode *q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return true;
}

// bool InsertPriorNode1(LinkList L, LNode *p, int e)
// {
// }

bool PrintElem(LinkList L)
{
    LNode *p = L->next;
    if (Empty0(L))
        return false;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    return true;
}

void ReverseList(LinkList &head)
{
    LinkList L = (LinkList)malloc(sizeof(LinkList));
    L->next = NULL;
    LNode *p = head->next;
    while (p != NULL)
    {
        L = (LinkList)malloc(sizeof(LinkList));
        L->data = head->data;
        L->next = p->next;
        p = p->next;
    }
    printf("output:\n");
    while (L->next != NULL)
    {
        printf("%d ", L->data);
        L = L->next;
    }
}

int main()
{
    LinkList L1;
    // ListHeadInsert(L1);
    // PrintElem(L1);
    // ReverseList(L1);
    // LinkList L2;
    // InitList(L1);
    // InitList(L2);
    // ListTailInsert(L1);
    // ListTailInsert(L2);
    // PrintElem(L1);
    // printf("\n");
    // PrintElem(L2);
    return 0;
}