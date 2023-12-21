#include <stdio.h>
#include <stdlib.h>

#define InitSize 10
#define MaxSize 10
typedef struct
{
    int data[MaxSize];
    int length;
} SqList; //静态数组实现顺序表

void InitList(SqList &L)
{
    // for(int i=0;i<MaxSize;i++)
    //     L.data[i]=0;
    L.length = 0;
} //初始化顺序表

bool ListInsert0(SqList &L, int i, int e)
{
    if (i < 1 || i > L.length + 1) //判断插入位置是否合法
        return false;
    if (L.length >= MaxSize) //判断储存空间是否已满
        return false;
    for (int j = L.length; j >= i; j--)
        L.data[j] = L.data[j - 1];
    L.data[i - 1] = e;
    L.length++;
    return true;
} //顺序表的插入操作

// bool ListDelete(SqList &L,int i,int &e)
// {}

///////////////////////////////////////////////////////////

typedef struct
{
    int *data;
    int MaxSize0;
    int length;
} SeqList; //指针实现动态内存分配的顺序表

void InitList1(SeqList &L)
{
    //用malloc函数申请一片连续的空间
    L.data = (int *)malloc(InitSize * sizeof(int));
    L.length = 0;
    L.MaxSize0 = InitSize;
}

void IncreaseSize(SeqList &L, int length)
{
    int *p = L.data;
    L.data = (int *)malloc((L.MaxSize0 + length) * sizeof(int));
    for (int i = 0; i < L.length; i++)
    {
        L.data[i] = p[i];
    }
    L.MaxSize0 = L.MaxSize0 + length;
    free(p);
}

///////////////////////////////////////////////////////////

int main()
{
    SqList L;
    InitList(L);
    for (int i = 0; i < MaxSize; i++)
    {
        printf("Data[%d]=%d\n", i, L.data[i]);
    }

    SeqList L1;
    InitList1(L1);
    IncreaseSize(L1, 5);

    return 0;
}
