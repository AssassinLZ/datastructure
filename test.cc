#include <iostream>
#include <math.h>
// #define MaxSize 10
// typedef struct Lnode
// {
//     int data;
//     struct Lnode *next;
// }LNode;

int pivotIndex(int *nums, int numsSize)
{
    int sum1 = 0, sum2 = 0;
    int sum = 0;
    int i;
    for (i = 0; i < numsSize; i++)
        sum += nums[i];
    // printf("%d",sum);
    for (i = 0; i < numsSize; i++)
    {
        sum1 += sum1 + nums[i - 1];
        sum2 = sum - sum1 - nums[i];
        if (sum1 == sum2)
            return i;
    }
    return -1;
}

int pivotIndex2(int *nums, int numsSize)
{
    int total = 0;
    for (int i = 0; i < numsSize; ++i)
    {
        total += nums[i];
    }
    int sum = 0;
    for (int i = 0; i < numsSize; ++i)
    {
        if (2 * sum + nums[i] == total)
        {
            return i;
        }
        sum += nums[i];
    }
    return -1;
}

int searchInsert(int *nums, int numsSize, int target)
{
    for (int i = 0; i < numsSize; i++)
        if (target == nums[i])
            return i;
    for (int i = 0; i < numsSize; i++)
        if (target > nums[i])
            return i;
    return -1;
}

int main()
{
    // printf("hello\n");
    // printf("hello\n");
    // printf("hello\n");
    int nums[6] = {1, 7, 3, 6, 5, 6};
    int a = pivotIndex(nums, 6);
    printf("%d\n", a);
    printf("hello\n");
    return 0;
}