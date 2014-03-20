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

//ð������
void BubbleSort(int a[], int n)
{
    int i,j;
    for (i = 0; i < n - 1; ++i)//ð�ݵõ���ֵ����i��λ��
    {
        int flag = false;//���ñ�־����һ�˱���û�з��������������Ѿ�����
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

//��������,���ֻ��ַ���
//ʱ�临�Ӷ�O(nlogn)
//�ռ临�Ӷ�O(logn)
//���ȶ�
int Partition1(int a[], int low, int high)//����λ���м�ɨ��
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

int Partition2(int a[], int low, int high)//�����ɨ��
{
    int pivot = a[high];
    int i = low;//������С��Ԫ��Ҫ��������λ��
    int j;//�����ҵ�������С��Ԫ��
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
    if (low < high)//�ݹ���������
    {
        int pivotloc = Partition2(a, low, high);
        QuickSort(a, low, pivotloc - 1);
        QuickSort(a, pivotloc + 1, high);
    }
}

//��Сд�ֿ�
void func1(char a[], int low, int high)
{
    while (low < high)
    {
        while (isUpper(a[high]) && low < high) high--;
        while (isLower(a[low]) && low < high) low++;
        swap(a[low], a[high]);
    }
}

//��0���ڷ�0Ԫ��ǰ��,��˳�򲻸ı�
//���� 0 3 0 2 1 0 0
//��� 0 0 0 0 3 2 1
void move1(int a[], int low, int high)//�Ӻ���ǰɨ��
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
//��0���ڷ�0Ԫ�غ���,��˳�򲻸ı�
void move2(int a[], int low, int high)//��ǰ����ɨ��
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

//������������
//���룺0 1 2 1 1 2 0 2 1 0
//�����0 0 0 1 1 1 1 2 2 2
void helan(int a[], int low, int high)//����ɨ��һ��
{
    int begin = low;//beginǰ��ȫ��0
    int current = low;
    int end = high;//end����ȫ��2
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

void helan_my(int a[], int low, int high)//�Լ��ķ�������ɨ������
{
    int i = low;
    int j;
    //�Ȱ�0������ǰ��
    for (j = low; j <= high; ++j)
    {
        if (a[j] == 0)
        {
            swap(a[j], a[i]);
            ++i;
        }
    }
    //�ٰ�1������ǰ��
    for (j = i; j <= high; ++j)
    {
        if (a[j] == 1)
        {
            swap(a[j], a[i]);
            ++i;
        }
    }
}

//����С��k����
//ʱ�临�Ӷ�O(n)
void findMixk(int in[], int low, int high, int k, int out[])
{
    int index = Partition1(in, low, high);
    while (index != k-1)//�����ڵ�kС������λ��
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
    printf("�����");
    for (int i = 0; i < 6; ++i)
    {
        printf("%d ", array[i]);
    }

    printf("\n��Сд�ֿ�:");
    char str[7] = {'a','A','Z','d','B','s','b'};
    func1(str, 0, 6);
    for (int i = 0; i < 7; ++i)
    {
        printf("%c ", str[i]);
    }

    printf("\n0���0�ֿ���");
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

    printf("\n�����������⣺");
    int b[10] = {0,1,2,1,1,2,0,2,1,0};
    helan(b, 0, 9);
    for (int i = 0; i < 10; ++i)
    {
        printf("%d ", b[i]);
    }

    printf("\n����С��k������");
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
