#include <iostream>

int Ds_2011()
{
    const int length1 = 10, length2 = 11;
    int array1[length1] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int array2[length2]{3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    int tag1 = 0, tag2 = 0;
    int length = length1 + length2;
    int length3 = length / 2 + 1;
    int array3[length3];
    for (int i = 0; i < length3; i++)
    {
        if (array1[tag1] < array2[tag2])
        {
            array3[i] = array1[tag1];
            tag1++;
        } else if (array1[tag1] > array2[tag2])
        {
            array3[i] = array2[tag2];
            tag2++;
        } else
        {
            array3[i] = array1[tag1];
            i++;
            array3[i] = array2[tag2];
            tag1++;
            tag2++;
        }
    }
    int medium;
    if (length3 % 2 == 0)
        medium = array3[length3 - 1] + array3[length - 2];
    else
        medium = array3[length3 - 1];
//    printf("%d \n", medium);
    return 0;
}


void Ds_2011_2()
{
    const int length1 = 10, length2 = 11;
    int array1[length1] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int array2[length2]{3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    int tag1 = 0, tag2 = 0;
    int tag=2;
    int medium;
    int length=(length1+length2)/2+1;
    int count=0;
    do
    {
        if(array1[tag1]==array2[tag2])
        {
            tag1++;
            tag2++;
            tag=1;
            count+=2;
        }
        else if(array1[tag1]<array2[tag2])
        {
            tag1++;
            tag=0;
            count++;
        }
        else
        {
            tag2++;
            count++;
            tag=0;
        }
    }while(count<length);
    if(tag==1)
        medium=array1[tag1-1];
    else
        medium=array2[tag2-1];
    printf("%d",medium);
}


int Ds_2013(int nums[8],int length)
{

//已知一个整数序列A = (a0, a1,…, an-1)，其中0≤ai＜n（0≤i < n）。
//若存在ap1 = ap2 =…= apm= x且m > n/2（0≤pk < n, 1≤k≤m），则称x为A的主元素。
//例如A= (0, 5, 5, 3, 5, 7, 5, 5)，则5为主元素；
//又如A = (0, 5, 5, 3, 5, 1, 5, 7)，则A中没有主元素。
    int array[length];
    for(int i=0;i<length;i++)
    {
        array[i]=0;
    }
    int max=0;
    for(int i=0;i<length;i++)
    {
        array[nums[i]]++;
    }
    for (int i = 0; i < length; ++i)
    {
        if(array[i]>max)
            max=array[i];
    }
    if(max>(length/2))
        return max;
    else
        return -1;
}


int main()
{
    
    return 0;
}
