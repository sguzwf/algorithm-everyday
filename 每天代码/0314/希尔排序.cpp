#include <stdio.h>
#include <stdlib.h>

//��������
void InsertSort(int a[], int len)
{
    int i,j;
    for (i = 1; i < len; ++i)//�ӵڶ���Ԫ�ؿ�ʼ
    {
        if (a[i] < a[i-1])//ע��˴�
        {
            int temp = a[i];
            for (j=i-1;temp < a[j] && j>=0;--j)
                a[j+1] = a[j];
            a[j+1] = temp;
        }
    }
}

//ϣ����С��������
//ʱ�临�Ӷ�ԼO(n��1.3�η�)�����ȶ�
void ShellSort(int a[], int len)
{
    int i, j;
    int step;
    for (step=len/2; step>=1; step/=2)//�����仯
    {
        for (i = step; i < len; ++i)//�Ӵ˲����µĵڶ���Ԫ�ؿ�ʼ
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
