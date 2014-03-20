#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define COINNUM 3
int coin[COINNUM] = {1,3,5};

//有面值为1元、3元和5元的硬币若干枚，用最少的硬币凑够n元
//动态规划法
int MinCoin(int n)
{
    int *mincoins = new int[n+1];
    //“状态"用来描述该问题的子问题的解
    //mincoins[i]代表i元需要的硬币数
    memset(mincoins, 0x7F, sizeof(mincoins));
    mincoins[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        //状态转移方程：mincoins[i] = min{mincoins[i-vj]+1},vj是第j个硬币的面值
        for (int j = 0; j < COINNUM; j++)
        {
            if (i >= coin[j] && mincoins[i-coin[j]]+1 < mincoins[i])
                mincoins[i] = mincoins[i-coin[j]]+1;
        }
    }
    return mincoins[n];
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        printf("%d\n", MinCoin(n));
    }
    return 0;
}
