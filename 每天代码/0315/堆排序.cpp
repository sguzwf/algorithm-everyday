#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void swap(int &a, int &b)
{
    a=a+b; b=a-b; a=a-b;
}

//向下调整
void AdjustDown(int *a, int k, int len)
{
    int top = a[k];
    for (int i = k*2+1; i < len; i = i*2+1)
    {
        if (i+1 < len && a[i+1] > a[i]) i++;//i取子节点中较大的一个
        if (a[i] <= top) break;//若父节点比子节点都大，不用再调整
        else
        {
            a[k] = a[i];//较大的子节点上移
            k = i;//遍历较大的子节点
        }
    }
    a[k] = top;
}

//向上调整
void AdjustUp(int *a, int k)
{
    int i = (k-1)/2;
    while (i >= 0 && a[i] < a[k])
    {
        swap(a[i], a[k]);
        k = i;
        i = (k-1)/2;
    }
}

//建大根堆,向下调整法
void BuildMaxHeap(int *a, int len)
{
    for (int i = len/2 - 1; i >= 0; --i)
    {
        AdjustDown(a, i, len);
    }
    #ifdef DEBUG
    printf("build:\n");
    for (int i = 0; i < 6; ++i)
    {
        printf("%d ", a[i]);
    }
    printf("build end\n");
    #endif
}

//建大根堆,向上调整法
void BuildMaxHeap2(int *a, int len)
{
    for (int i = 1; i < len; ++i)
    {
        AdjustUp(a, i);
    }
    printf("build:\n");
    for (int i = 0; i < 6; ++i)
    {
        printf("%d ", a[i]);
    }
    printf("build end\n");
}

//堆排序
//时间复杂度O(nlogn)
//建堆时用向下调整、插入时用向上调整
void HeapSort(int *a, int low, int high)
{
    BuildMaxHeap2(a, high-low+1);
    int len = high - low + 1;
    for (int i = len - 1; i > 0; --i)
    {
        swap(a[i], a[0]);//将堆底与堆顶交换
        AdjustDown(a, 0, i);//向下调整为大根堆
    }
}

//利用堆排序求最小的k个数
void GetMixk(int *a, int k, int len)
{
    if (k >= len || k <= 0) return ;
    BuildMaxHeap(a, k);
    for (int i = k; i < len; ++i)
    {
        if (a[i] < a[0])
            swap(a[i], a[0]);
        AdjustDown(a, 0, k);
    }
}

int main()
{
    int a[6] = {20,18,22,16,30,19};
    HeapSort(a, 0, 5);
    for (int i = 0; i < 6; ++i)
    {
        printf("%d ", a[i]);
    }
    printf("\nmixk:");
    int b[6] = {20,18,22,16,30,19};
    int k = 3;
    GetMixk(b, k, 6);
    for (int i = 0; i < k; ++i)
    {
        printf("%d ", b[i]);
    }
}
