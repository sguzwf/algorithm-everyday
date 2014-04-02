#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* _itoa(int value, char *str, int base)
{
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
    return 0;
}
