#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getmax(int a, int b)
{
    return a>b ? a : b;
}
//动态规划法求LCS
//状态：d[i][j]表示str1的前i个与str2的前j个的LCS
//状态转换公式：
//当str1[i]==str2[j]时,d[i][j]=d[i-1][j-1]+1
//否则d[i][j]=max{d[i-1][j], d[i][j-1]}
int d[100][100];
int LCS(char *str1, char *str2)
{
    if (str1 == NULL || str2 == NULL) return 0;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int i, j;
    
    for (i = 0; i < len1; i++)
        d[i][0] = 0;
    for (i = 0; i < len2; i++)
        d[0][i] = 0;
    	
    for (i = 1; i <= len1; ++i)
    {
        for (j = 1; j <= len2; ++j)
    	{
            if (str1[i]==str2[j])
                d[i][j] = d[i-1][j-1] + 1;
        	else
                d[i][j] = getmax(d[i-1][j], d[i][j-1]);
    	}
    }
    return d[len1][len2];
}

int main(void) {
    char *str1 = "ABCBDAB";
    char *str2 = "BDCABA";
    printf("%d\n", LCS(str1, str2));
    return 0;
}
