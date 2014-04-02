#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int atoi(const char* str)
{
    if (str == NULL) return 0;//指针为null时返回0

    while (*str == ' ') str++;//跳过开头的空字符

    int ret = 0;
    int flag = 0;//0为正，1为负
    if (*str == '+') str++;//检测正负号
    else if(*str == '-')
    {
        str++;
        flag = 1;
    }
    while (*str != '\0')
    {
        if (*str > '9' || *str < '0') break;//遇到非数字时停止
        ret = ret*10 + (*str-'0');
        if (ret < 0) return -1;//溢出时返回-1
        str++;
    }
    return flag ? -ret : ret;
}

int main()
{
    char str[20] = {0};
    strcpy(str, "123");
    if (atoi(str) == 123) printf("123 sucess!\n");
    else printf("err:%d\n",atoi(str));

    memset(str, 0, sizeof(str));
    strcpy(str, "+123");
    if (atoi(str) == +123) printf("+123 sucess!\n");
    else printf("err:%d\n",atoi(str));

    memset(str, 0, sizeof(str));
    strcpy(str, "-123");
    if (atoi(str) == -123) printf("-123 sucess!\n");
    else printf("err:%d\n",atoi(str));

    memset(str, 0, sizeof(str));
    strcpy(str, " 123");
    if (atoi(str) == 123) printf(" 123 sucess!\n");
    else printf("err:%d\n",atoi(str));

    memset(str, 0, sizeof(str));
    strcpy(str, "123d");
    if (atoi(str) == 123) printf("123d sucess!\n");
    else printf("err:%d\n",atoi(str));

    memset(str, 0, sizeof(str));
    strcpy(str, "d123");
    if (atoi(str) == 0) printf("d123 sucess!\n");
    else printf("err:%d\n",atoi(str));

    memset(str, 0, sizeof(str));
    strcpy(str, "1d23");
    if (atoi(str) == 1) printf("1d23 sucess!\n");
    else printf("err:%d\n",atoi(str));

    memset(str, 0, sizeof(str));
    strcpy(str, "12-3");
    if (atoi(str) == 12) printf("12-3 sucess!\n");
    else printf("err:%d\n",atoi(str));

    memset(str, 0, sizeof(str));
    strcpy(str, "-d123");
    if (atoi(str) == 0) printf("-d123 sucess!\n");
    else printf("err:%d\n",atoi(str));

    int t = 9999999999999999999999999999999999999;
    memset(str, 0, sizeof(str));
    strcpy(str, "9999999999999999999999999999999999999");
    if (atoi(str) == -1) printf("9999999999999999999999999999999999999 sucess!\n");
    else printf("err:%d\n",atoi(str));

    if (atoi(NULL) == 0) printf("NULL sucess!\n");
    else printf("err:%d\n",atoi(NULL));

    return 0;
}
