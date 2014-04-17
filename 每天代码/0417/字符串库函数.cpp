#include <stdio.h>
#include <assert.h>
#include <string.h>

int strlen(char *str)
{
    assert(str != NULL);
    int len = 0;
    while ((*str++)!='\0')
        len++;
    return len;
}

int strcmp(char *str1, char *str2)
{
    assert(str1!=NULL && str2!=NULL);
    while ((*str1)!='\0' && (*str2)!='\0')
    {
        if ((*str1++) != (*str2++))
            return 1;
    }
    if (*str1!='\0' || *str2!='\0')
        return 1;
    return 0;
}

char* strcat(char *str1, char *str2)
{
    assert(str1 != NULL && str2 != NULL);
    char *temp = str1;
    while (*str1) str1++;
    while ((*str1++) = (*str2++));
    return temp;
}

char* strcpy(char *str1, char *str2)
{
    assert(str1 != NULL && str2 != NULL);
    char *temp = str1;
    while ((*str1++)=(*str2++));
    return temp;
}

char *strstr(char *str1, char *str2)
{
    assert(str1 != NULL && str2 != NULL);
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if (len1 < len2)
        return NULL;
    for (int i = 0; i < len1-len2; i++)
    {
        int j;
        for (j = 0; j < len2; j++)
        {
            if (str1[i+j] != str2[j]) break;
        }
        if (j == len2) return str1+i;
    }
    return NULL;
}

int main()
{
    char *str1 = "renbao";
    printf("%d\n", strlen(str1));

    //char *str2 = "renbin";
    //char *str2 = "renb";
    //char *str2 = "renbaoo";
    char *str2 = "renbao";
    if (!strcmp(str1, str2))
        printf("equal!\n");
    else
        printf("not equal!\n");

    char strA[10] = "str1";
    char strB[5] = "str2";
    strcat(strA, strB);
    printf("%s\n", strA);

    strcpy(strA, strB);
    printf("%s\n", strA);

    char *str3 = "ren bao bin";
    char *str4 = "bao";
    char * i;
    if ((i = strstr(str3, str4)) == NULL)
        printf("no substring\n");
    else
        printf("have substring:%s\n", i);
    return 0;
}
