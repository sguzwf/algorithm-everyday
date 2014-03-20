#include <stdio.h>
#include <string.h>

#define M 5
#define N 10

struct ElemType
{
    int value;
    int array;
};

void swap(ElemType a, ElemType b)
{
    ElemType t = a;
    a = b;
    b = t;
}

void AdjustDown(ElemType *heap, int k, int len)
{
    ElemType temp = heap[k];
    for (int i = k*2+1;i < len;i = i*2+1)//j��i���ӽڵ�
    {
        if (i<len-1 && heap[i+1].value > heap[i].value) i++;
        if (heap[i].value <= temp.value) break;
        heap[k] = heap[i];
        k = i;
    }
    heap[k] = temp;
}

void BuildHeap(ElemType *heap, int len)
{
    for (int i = len/2-1; i >= 0; --i)
    {
        AdjustDown(heap, i, len);
    }
}

//��M������������������N����
//���ö�O(NlogM)
void getMax(int a[][N], int *max)
{
    ElemType *heap = new ElemType[M];//����Ĵ����
    memset(heap, 0, sizeof(ElemType)*M);
    int arrayiter[M];//��¼ÿ�����鵱ǰҪȡ��Ԫ��
    for (int i = 0; i < M; ++i)
    {
        heap[i].value = a[i][0];
        heap[i].array = i;
        arrayiter[i] = 1;
    }
    BuildHeap(heap, M);
    for (int i = 0; i < N; i++)
    {
        max[i] = heap[0].value;//���Ѷ���������
        int iter = (arrayiter[heap[0].array]);
        heap[0].value = a[heap[0].array][iter];//��������һ������Ѷ�
        arrayiter[heap[0].array]++;//��Ӧ������ָ���1
        AdjustDown(heap, 0, M);//����Ϊ�����
    }
    delete heap;
}

int main()
{
    int a[M][N] = {{18,14,12,10,8,4,3,2,1,0},
                    {60,25,26,17,13,11,9,8,4,3},
                    {10,9,8,7,6,5,4,3,2,1},
                    {34,21,18,17,12,5,3,2,1,0},
                    {43,24,17,15,14,13,11,9,2,1}};
    int max[N] = {0};
    getMax(a, max);
    for (int i = 0; i < N; ++i)
    {
        printf("%d ", max[i]);
    }
//    ElemType test[6];
//    for (int i = 0; i < 6; i++)
//    {
//        scanf("%d", &test[i].value);
//        test[i].array = i;
//    }
//    BuildHeap(test, 6);
//    for (int i = 0; i < 6; i++)
//    {
//        printf("%d ", test[i].value);
//    }
    return 0;
}
