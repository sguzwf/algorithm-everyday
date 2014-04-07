#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}node;

node *insert(node *head, int value, int loc)
{
    if (head == NULL && loc > 0) return NULL;
    if (loc == 0){
        node *a = (node*)malloc(sizeof(node));
        a->data = value;
        a->next = head;
        head = a;
        return head;
    }
    node *p = head;
    for (int i = 0; i < loc-1 && p!=NULL; i++){
        p = p->next;
    }
    if (p == NULL) return NULL;
    node *b = (node*)malloc(sizeof(node));
    b->data = value;
    b->next = p->next;
    p->next = b;
    return head;
}

void display(node *head)
{
    node *p = head;
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}

//�������÷ǵݹ��㷨
//����pre��cur����ָ�룬ʹcur��nextָ��pre��Ȼ�����������ƶ�֪��curΪ�ա�
node* reverse(node *head)
{
    if (head == NULL) return NULL;
    node *pre = head;
    node *cur = head->next;
    node *next;
    while (cur != NULL)
    {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    head->next = NULL;
    head = pre;
    return head;
}

int main()
{
    node *head = NULL;

    head = insert(head, 1, 0);
    insert(head, 2, 1);
    insert(head, 3, 2);
    insert(head, 4, 3);
    display(head);
    printf("\n");

    head = reverse(head);
    display(head);
    printf("\n");
    return 0;
}
