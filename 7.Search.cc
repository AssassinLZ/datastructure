#include <iostream>
//折半查找
typedef struct 
{
    int *elem;
    int TableLen;
}SSTable;

int Binary_Search(SSTable L,int key)
{
    int low=0,high=L.TableLen-1,mid;
    while (low<=high)
    {
        mid=(low+high)/2;
        if (L.elem[mid]==key)
            return mid;
        else if(L.elem[mid]>key)
            high=mid-1;
        else
            low=mid+1;
    }
    return -1;
}


//分块查找
typedef struct 
{
    int maxValue;
    int low,high;
}Index;//索引表

int List[100];//顺序表存储实际元素

int main()
{

    return 0;
}