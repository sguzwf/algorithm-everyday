#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[100];

int main()
{
    scanf("%s", str);
    int count[256];//���ڴ��ÿ���ַ��ĳ��ִ���
    memset(count, 0, sizeof(count));
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        count[str[i]]++;
    }
    char c;
    while (scanf("%c", &c)!= EOF)//�����ַ����ؽ��
    {
       printf("%d\n", count[c]);
    }
    return 0;
}
