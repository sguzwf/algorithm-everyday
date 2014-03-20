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
    for (int i = k*2+1;i < len;i = i*2+1)//j是i的子节点
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

//从M个降序数组中找最大的N个数
//利用堆O(NlogM)
void getMax(int a[][N], int *max)
{
    ElemType *heap = new ElemType[M];//所需的大根堆
    memset(heap, 0, sizeof(ElemType)*M);
    int arrayiter[M];//记录每个数组当前要取的元素
    for (int i = 0; i < M; ++i)
    {
        heap[i].value = a[i][0];
        heap[i].array = i;
        arrayiter[i] = 1;
    }
    BuildHeap(heap, M);
    for (int i = 0; i < N; i++)
    {
        max[i] = heap[0].value;//将堆顶存入数组
        int iter = (arrayiter[heap[0].array]);
        heap[0].value = a[heap[0].array][iter];//将数组下一个放入堆顶
        arrayiter[heap[0].array]++;//对应的数组指针加1
        AdjustDown(heap, 0, M);//调整为大根堆
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
