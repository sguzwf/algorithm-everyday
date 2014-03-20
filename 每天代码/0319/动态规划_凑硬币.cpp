#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define COINNUM 3
int coin[COINNUM] = {1,3,5};

//����ֵΪ1Ԫ��3Ԫ��5Ԫ��Ӳ������ö�������ٵ�Ӳ�Ҵչ�nԪ
//��̬�滮��
int MinCoin(int n)
{
    int *mincoins = new int[n+1];
    //��״̬"���������������������Ľ�
    //mincoins[i]����iԪ��Ҫ��Ӳ����
    memset(mincoins, 0x7F, sizeof(mincoins));
    mincoins[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        //״̬ת�Ʒ��̣�mincoins[i] = min{mincoins[i-vj]+1},vj�ǵ�j��Ӳ�ҵ���ֵ
        for (int j = 0; j < COINNUM; j++)
        {
            if (i >= coin[j] && mincoins[i-coin[j]]+1 < mincoins[i])
                mincoins[i] = mincoins[i-coin[j]]+1;
        }
    }
    return mincoins[n];
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        printf("%d\n", MinCoin(n));
    }
    return 0;
}
