#include <iostream>
#include <string>
#include <cstring>
#include <cassert>
using namespace std;

#define N 5
#define INF 0x7FFFFF
//无向图的邻接矩阵
int g[N][N] = {{0, 1, INF, 2, INF},
               {1, 0, 1, INF, 1},
               {INF, 1, 0, INF, 3},
               {2, INF, INF, 0, INF},
               {INF, 1, 3, INF, 0}};

//无向图第0个节点到第n个节点最短距离
//动态规划法
//时间复杂度
//空间复杂度
int ShortestDistance(int n)
{
    assert(n >= 0 && n < N);
    if (n == 0) return 0;

    int *d = new int[n];
    memset(d, 0, sizeof(d));
    for (int i = 1; i <= n; i++)
    {
        int min = g[0][i];
        for (int j = 0; j < i; j++)
        {
            if (d[j] + g[j][i] < min)
                min = d[j] + g[j][i];
        }
        d[i] = min;
    }
    return d[n];
}


int main ()
{
    int n;
    while (cin >> n)
    {
        cout << ShortestDistance(n) << endl;
    }
    return 0;
}
