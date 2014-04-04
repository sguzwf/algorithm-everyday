#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//顺序表的各种操作
#define MAXSIZE 10
typedef struct sequence_list
{
    int data[MAXSIZE];
    int len;
}sequence_list;

void init(sequence_list *list)
{
    list->len = 0;
}
//插入
int insert(sequence_list *list, int value, int loc)
{
    if (loc > list->len || loc < 0)
    {
        printf("insert err!\n");
        return -1;
    }
    int i;
    for (i = list->len - 1; i >= loc; i--)
    {
        list->data[i+1] = list->data[i];
    }
    list->data[loc] = value;
    (list->len)++;
    return loc;
}

void append(sequence_list *list, int value)
{
    if (list->len == MAXSIZE)
    {
        printf("list is full\n");
        return;
    }
    list->data[list->len] = value;
    list->len++;
}
//删除
int del(sequence_list *list, int loc)
{
    if (list->len == 0)
    {
        printf("err:list is empty");
        return -1;
    }
    if (loc > list->len-1 || loc < 0)
    {
        printf("err:loc error\n");
        return -2;
    }
    for (int i = loc; i < list->len-1; i++)
    {
        list->data[i] = list->data[i+1];
    }
    (list->len)--;
    return loc;
}

int display(sequence_list *list)
{
    if (list->len == 0)
    {
        printf("err:list is empty\n");
        return -1;
    }
    for (int i = 0; i < list->len; i++)
    {
        printf("%d ", list->data[i]);
    }
    printf("\n");
    return list->len;
}

int main()
{
    sequence_list list;
    init(&list);
    append(&list, 1);
    append(&list, 2);
    append(&list, 3);
    append(&list, 4);
    display(&list);
    insert(&list, 9, 2);
    display(&list);
    del(&list, 0);
    display(&list);
    return 0;
}
