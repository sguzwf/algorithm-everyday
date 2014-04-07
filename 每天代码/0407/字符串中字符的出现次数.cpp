#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[100];

int main()
{
    scanf("%s", str);
    int count[256];//用于存放每个字符的出现次数
    memset(count, 0, sizeof(count));
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        count[str[i]]++;
    }
    char c;
    while (scanf("%c", &c)!= EOF)//输入字符返回结果
    {
       printf("%d\n", count[c]);
    }
    return 0;
}
