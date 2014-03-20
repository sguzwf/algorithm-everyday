#include <stdio.h>
#include <stdlib.h>

//给定一个数组，判断数组内是否存在一个连续区间，使其和恰好等于给定整数k。
int main()
{
    int n, k;
    while (scanf("%d", &n) != EOF)
    {
        int *a = new int[n];
        int max = -10000, min = 10000;
        int nowmax = 0, nowmin = 0;//最大子序列与最小子序列
        for (int i = 0 ; i <n; ++i)
        {
            scanf("%d", &a[i]);
            nowmax += a[i];
            if (nowmax > max) max = nowmax;
            if (nowmax < 0) nowmax = 0;
            nowmin += a[i];
            if (nowmin < min) min = nowmin;
            if (nowmin > 0) nowmin = 0;
        }
        //printf("max:%d min:%d\n", max, min);
        scanf("%d", &k);
        if (k > max || k < min)//对不和条件的过滤
        {
            printf("No\n");
            continue;
        }
        int i, j;
        int flag = false;
        for (i = 0; i < n && !flag; ++i)
        {
            int sum = 0;
            for (j = i; j < n; ++j)
            {
                sum += a[j];
                if (sum == k)
                {
                    flag = true;
                    break;
                }
            }
        }
        if (flag == true)
        {
            printf("%d %d\n", i, j+1);
        }
        else
            printf("No\n");
    }
    return 0;
}
