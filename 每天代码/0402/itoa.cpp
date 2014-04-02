#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* itoa(int value, char *str, int base)
{
    if (str == NULL) return NULL;
    int flag = 0;
    if (value < 0 && base == 10)//处理10进制负数
    {
        flag = 1;
        value = -value;
    }
    else if (value < 0)
        return NULL;
    int len = 0;//字符串的长度
    while (value)
    {
        str[len++] = '0' + value%base;
        value /= base;
    }
    if (flag)
        str[len++] = '-';
    str[len] = '\0';
    for (int i = 0; i < len/2; i++)//将字符串逆置
    {
        char t = str[i];
        str[i] = str[len-1-i];
        str[len-1-i] = t;
    }
    return str;
}

int main()
{
    int i;
    char str[20] = {0};

    i = 123;
    memset(str, 0, sizeof(str));
    itoa(i, str, 10);
    if (strcmp(str, "123") == 0) printf("123 10 success!\n");
    else printf("err:%s\n", str);

    i = 123;
    memset(str, 0, sizeof(str));
    itoa(i, str, 2);
    if (strcmp(str, "1111011") == 0) printf("123 2 success!\n");
    else printf("err:%s\n", str);

    i = 123;
    memset(str, 0, sizeof(str));
    itoa(i, str, 8);
    if (strcmp(str, "173") == 0) printf("123 8 success!\n");
    else printf("err:%s\n", str);

    i = -123;
    memset(str, 0, sizeof(str));
    itoa(i, str, 10);
    if (strcmp(str, "-123") == 0) printf("-123 10 success!\n");
    else printf("err:%s\n", str);

    i = -123;
    memset(str, 0, sizeof(str));
    itoa(i, str, 2);
    if (strcmp(str, "") == 0) printf("-123 2 success!\n");
    else printf("err:%s\n", str);
    return 0;
}
