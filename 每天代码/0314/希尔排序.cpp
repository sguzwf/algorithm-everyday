#include <stdio.h>
#include <stdlib.h>

//插入排序
void InsertSort(int a[], int len)
{
    int i,j;
    for (i = 1; i < len; ++i)//从第二个元素开始
    {
        if (a[i] < a[i-1])//注意此处
        {
            int temp = a[i];
            for (j=i-1;temp < a[j] && j>=0;--j)
                a[j+1] = a[j];
            a[j+1] = temp;
        }
    }
}

//希尔缩小增量排序
//时间复杂度约O(n的1.3次方)，不稳定
void ShellSort(int a[], int len)
{
    int i, j;
    int step;
    for (step=len/2; step>=1; step/=2)//步长变化
    {
        for (i = step; i < len; ++i)//从此步长下的第二个元素开始
        {
            if (a[i] < a[i - step])
            {
                int temp = a[i];
                for (j = i - step; temp < a[j] && j >= 0; j-=step)
                    a[j+step] = a[j];
                a[j+step] = temp;
            }
        }
    }
}

int main()
{
    int array[6] = {1,3,6,9,13,1};
    //InsertSort(array, 6);
    ShellSort(array, 6);
    for (int i = 0; i < 6; ++i)
    {
        printf("%d ", array[i]);
    }
    return 0;
}
