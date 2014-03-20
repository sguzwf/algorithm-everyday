#include <stdio.h>
#include <stdlib.h>

void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}
void swap(char &a, char &b)
{
    char t = a;
    a = b;
    b = t;
}
bool isUpper(char c)
{
    if (c >= 'A' && c <= 'Z') return true;
    else return false;
}
bool isLower(char c)
{
    if (c >= 'a' && c <= 'z') return true;
    else return false;
}

//冒泡排序
void BubbleSort(int a[], int n)
{
    int i,j;
    for (i = 0; i < n - 1; ++i)//冒泡得到的值放在i的位置
    {
        int flag = false;//设置标志，若一趟遍历没有发生交换，表明已经有序
        for (j = n-1; j > i; --j)
        {
            if (a[j] < a[j-1])
            {
                swap(a[j], a[j-1]);
                flag = true;
            }
        }
        if (flag == false) return ;
    }
}

//快速排序,两种划分方法
//时间复杂度O(nlogn)
//空间复杂度O(logn)
//不稳定
int Partition1(int a[], int low, int high)//从首位向中间扫描
{
    int pivot = a[low];
    while (low < high)
    {
        while (a[high] >= pivot && low < high) high--;
        a[low] = a[high];
        while (a[low] <= pivot && low < high) low++;
        a[high] = a[low];
    }
    a[low] = pivot;
    return low;
}

int Partition2(int a[], int low, int high)//逐步向后扫描
{
    int pivot = a[high];
    int i = low;//比枢轴小的元素要交换到的位置
    int j;//遍历找到比枢轴小的元素
    for (j = low; j <= high; ++j)
    {
        if (a[j] <= pivot)
        {
            swap(a[j],a[i]);
            ++i;
        }
    }
    return i-1;
}

void QuickSort(int a[], int low, int high)
{
    if (low < high)//递归跳出条件
    {
        int pivotloc = Partition2(a, low, high);
        QuickSort(a, low, pivotloc - 1);
        QuickSort(a, pivotloc + 1, high);
    }
}

//大小写分开
void func1(char a[], int low, int high)
{
    while (low < high)
    {
        while (isUpper(a[high]) && low < high) high--;
        while (isLower(a[low]) && low < high) low++;
        swap(a[low], a[high]);
    }
}

//将0放在非0元素前面,且顺序不改变
//输入 0 3 0 2 1 0 0
//输出 0 0 0 0 3 2 1
void move1(int a[], int low, int high)//从后往前扫描
{
    int i = high;
    int j;
    for (j = high; j >= low; --j)
    {
        if (a[j] != 0)
        {
            swap(a[j], a[i]);
            --i;
        }
    }
}
//将0放在非0元素后面,且顺序不改变
void move2(int a[], int low, int high)//从前往后扫描
{
    int i = low;
    int j;
    for (j = low; j <= high; ++j)
    {
        if (a[j] != 0)
        {
            swap(a[j], a[i]);
            ++i;
        }
    }
}

//荷兰国旗问题
//输入：0 1 2 1 1 2 0 2 1 0
//输出：0 0 0 1 1 1 1 2 2 2
void helan(int a[], int low, int high)//仅需扫描一次
{
    int begin = low;//begin前面全是0
    int current = low;
    int end = high;//end后面全是2
    while (current <= end)
    {
        if (a[current] == 0)
        {
            swap(a[current], a[begin]);
            current++;
            begin++;
        }
        else if (a[current] == 1)
            current++;
        else
        {
            swap(a[current], a[end]);
            end--;
        }
    }
}

void helan_my(int a[], int low, int high)//自己的方法，需扫描两次
{
    int i = low;
    int j;
    //先把0调整到前面
    for (j = low; j <= high; ++j)
    {
        if (a[j] == 0)
        {
            swap(a[j], a[i]);
            ++i;
        }
    }
    //再把1调整到前面
    for (j = i; j <= high; ++j)
    {
        if (a[j] == 1)
        {
            swap(a[j], a[i]);
            ++i;
        }
    }
}

//找最小的k个数
//时间复杂度O(n)
void findMixk(int in[], int low, int high, int k, int out[])
{
    int index = Partition1(in, low, high);
    while (index != k-1)//枢轴在第k小的数的位置
    {
        if (index > k-1)
        {
            high = index - 1;
            index = Partition1(in, low, high);
        }
        else
        {
            low = index + 1;
            index = Partition1(in, low, high);
        }
    }

    for (int i = 0; i < k; i++)
        out[i] = in[i];
}

int main()
{
    int array[6] = {1,3,6,9,13,1};
    //BubbleSort(array, 6);
    QuickSort(array, 0, 5);
    printf("排序后：");
    for (int i = 0; i < 6; ++i)
    {
        printf("%d ", array[i]);
    }

    printf("\n大小写分开:");
    char str[7] = {'a','A','Z','d','B','s','b'};
    func1(str, 0, 6);
    for (int i = 0; i < 7; ++i)
    {
        printf("%c ", str[i]);
    }

    printf("\n0与非0分开：");
    int a[7] = {0,3,0,2,1,0,0};
    move1(a, 0, 6);
    for (int i = 0; i < 7; ++i)
    {
        printf("%d ", a[i]);
    }
    puts("");
    move2(a, 0, 6);
    for (int i = 0; i < 7; ++i)
    {
        printf("%d ", a[i]);
    }

    printf("\n荷兰国旗问题：");
    int b[10] = {0,1,2,1,1,2,0,2,1,0};
    helan(b, 0, 9);
    for (int i = 0; i < 10; ++i)
    {
        printf("%d ", b[i]);
    }

    printf("\n找最小的k个数：");
    int c[10] = {1,87,4,5,7,5,4,98,5,0};
    int k = 4;
    int out[4] = {0};
    findMixk(c, 0, 9, 4, out);
    for (int i = 0; i < k; ++i)
    {
        printf("%d ", out[i]);
    }
    return 0;
}
