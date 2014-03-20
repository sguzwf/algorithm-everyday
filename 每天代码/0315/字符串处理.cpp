#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//×Ö·û´®×ª»»ÎªÊý×Ö
int atoi(const char *a)
{
    assert(a != NULL);
    int flag = 0;
    int result = 0;
    int i = 0;
    if (a[i] == '-')
    {
        flag = 1;
        i++;
    }
    while (a[i])
    {
        result = result * 10 + (a[i]-'0');
        i++;
    }
    return (flag ? -result : result);
}

int main()
{
    char str[] = "-165";
    printf("%d\n", atoi(str));
    return 0;
}
