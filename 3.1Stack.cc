#include <iostream>
#define MaxSize 10
typedef struct
{
    char data[MaxSize];
    int top;
} SqStack;

typedef struct Linknode
{
    char data;
    struct Linknode *next;
}*LiStack;

void IniStack(SqStack &S)
{
    S.top = -1;
}

bool StackEmpty(SqStack S)
{
    if (S.top == -1)
        return true;
    else
        return false;
}

bool Push(SqStack &S, char x)
{
    if (S.top == MaxSize - 1) //注意数组的最大下标是MaxSize-1
        return false;
    S.data[++S.top] = x;
    return true;
}

bool Pop(SqStack &S, char &x)
{
    if (S.top == -1)
        return false;
    x = S.data[S.top];
    S.top--;
    // x = S.data[S.top--];//也可以写成这样
    return 1;
}

bool GetTop(SqStack S, char &x)
{
    if (S.top == -1)
        return false;
    x = S.data[S.top];
    return true;
}

bool BracketCheck(char str[], int length)
{
    SqStack S;
    IniStack(S);
    for (int i = 0; i < length; i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            Push(S, str[i]);
        else
        {
            if (StackEmpty(S))
                return false;

            char topElem;
            Pop(S, topElem);
            if (str[i] == ')' && topElem == '(')
                return false;
            if (str[i] == ']' && topElem == '[')
                return false;
            if (str[i] == '}' && topElem == '{')
                return false;
        }
    }
    return StackEmpty(S);
}
