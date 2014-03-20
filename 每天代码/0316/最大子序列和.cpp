#include <stdio.h>
#include <stdlib.h>

int max(int a, int b, int c)
{
    if (b > a) a = b;
    if (c > a) a = c;
    return a;
}
//最大子序列和
//递归方法，时间复杂度O(nlogn)
int MaxSubSum(int *a, int low, int high)
{
    if (low == high)
    {
        if (a[low] < 0) return 0;
        else return a[low];
    }
    int mid = (low + high)/2;
    int lMaxSum = MaxSubSum(a, low, mid);
    int rMaxSum = MaxSubSum(a, mid+1, high);

    int lBorderMaxSum = a[mid], rBorderMaxSum = a[mid+1];
    int lBorderSum = a[mid], rBorderSum = a[mid+1];
    for (int i = mid-1; i >= low; i--)
    {
        lBorderSum += a[i];
        if (lBorderSum > lBorderMaxSum)
            lBorderMaxSum = lBorderMaxSum;
    }
    for (int i = mid+2; i <= high; ++i)
    {
        rBorderSum += a[i];
        if (rBorderSum > rBorderMaxSum)
            rBorderMaxSum = rBorderSum;
    }
    return max(lMaxSum, rMaxSum, rBorderMaxSum+lBorderMaxSum);
}

//时间复杂度O(n)
int MaxSubSum2(int *a, int low, int high)
{
    int nowSum = 0, maxSum = 0;
    for (int i = low; i <= high; ++i)
    {
        nowSum += a[i];
        if (nowSum > maxSum) maxSum = nowSum;
        if (nowSum < 0) nowSum = 0;
    }
    return maxSum;
}

int main()
{
    int a[10] = {-1, 2, 1, -4, 5, 1, -1, 2, 2, -1};
    printf("%d", MaxSubSum2(a, 0, 9));
    return 0;
}
