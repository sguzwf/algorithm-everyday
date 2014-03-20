#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Longest Increasing Subsequence
//最长非降序子序列(子序列不要求是连续的)
//动态规划法，状态d[len]，状态转移方程d[i]=max{{d[j]+1},1}，j满足j<i&&a[i]>=a[j].
int LIS(int *a, int len)
{
    int *d = new int[len];
    memset(d, 0, sizeof(d));
    d[0] = 1;
    for (int i = 1; i < len; i++)
    {
        int nowmax = 1;
        for (int j = 0; j < i; j++)
        {
            if ((a[i] >= a[j]) && (d[j]+1>nowmax)) nowmax = d[j]+1;
        }
        d[i] = nowmax;
    }
    return d[len-1];
}

int main()
{
    int a[] = {5,3,4,8,6,7};
    printf("%d\n", LIS(a, 6));
    return 0;
}
