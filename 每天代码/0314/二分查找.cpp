#include <stdio.h>
#include <stdlib.h>

int binary_search(int a[], int len, int value)
{
    int left = 0, right = len -1;
    while (left <= right)
    {
        int mid = left + ((right - left)>>1);//防止溢出、使用位运算
        if (value > a[mid])
            left = mid + 1;
        else if (value < a[mid])
            right = mid - 1;
        else
            return mid;
    }
    return -1;
}

int main()
{
    int array[5] = {1,3,6,9,13};
    int value;
    while(1)
    {
        scanf("%d", &value);
        printf("%d\n", binary_search(array, 5, value));
    }
    return 0;
}
