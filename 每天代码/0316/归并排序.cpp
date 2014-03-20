#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int b[6];//辅助数组

void swap(int &a, int &b)
{
    a = a + b; b = a - b; a = a - b;
}

//将两有序数组合并,借助辅助数组
void Merge(int *a, int low, int mid, int high)
{
    for (int i = low; i <= high; ++i)
        b[i] = a[i];//将所有元素先存入辅助数组中
    int i, j, k;
    for (i = low, j = mid+1, k = i; i<=mid&&j<=high;k++)
    {
        if (b[i] <= b[j])
        {
            a[k] = b[i];
            i++;
        }
        else
        {
            a[k] = b[j];
            j++;
        }
    }
    while (i<=mid) a[k++] = b[i++];
    while (j<=high) a[k++] = b[j++];
}

//对长度为n的数组逆序
void reverse(int *a, int n)
{
    int i = 0, j = n-1;
    while (i < j)
    {
        swap(a[i], a[j]);
        ++i;--j;
    }
}

//数组向左移动k位
void MoveLeft(int *a, int n, int k)
{
    reverse(a, k);
    reverse(a+k, n-k);
    reverse(a, n);
}

//原地归并，空间复杂度O(1)
void Merge2(int *a, int low, int mid, int high)
{
    int i = low, j = mid + 1;
    while (i <= mid &&j <= high)
    {
        int step = 0;//j移动的步数
        while (i <= mid && a[i] <= a[j]) i++;
        while (j <= high && a[j] <= a[i]) {j++;step++;}
        MoveLeft(a+i, j-i, j-i-step); //向左移j-i-step步
    }
}

//归并排序
//时间复杂度O(nlogn)
//递归形式，分治思想
void MergeSort(int *a, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high)/2;
        MergeSort(a, low, mid);
        MergeSort(a, mid+1, high);
        Merge2(a, low, mid, high);
    }
}

//两个有序数组a和b，a后可容纳b，将b合并到a中。
void Merge_ab(int *a, int *b, int n, int m)//m是a中元素个数,n是b中元素个数
{
    int k = n+m-1;
    int i = n-1,j = m-1;
    for (;i >= 0&&j >= 0;k--)
    {
        if (a[i] >= b[j])
            a[k] = a[i--];
        else
            a[k] = b[j--];
    }
    while (i >= 0)
        a[k--] = a[i--];
    while (j >= 0)
        a[k--] = b[j--];
}

int main()
{
    int a[6] = {20,18,22,16,30,19};
    MergeSort(a, 0, 5);
    for (int i = 0; i < 6; ++i)
    {
        printf("%d ", a[i]);
    }
    puts("");

    int a1[10] = {1,5,7,9};
    int a2[6] = {2,3,4,6,8,10};
    Merge_ab(a1, a2, 4, 6);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", a1[i]);
    }
    return 0;
}
