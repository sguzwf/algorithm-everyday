#include <iostream>
#include <string>
#include <cstring>
#include <cassert>
using namespace std;

//��άDP����:
//ƽ������M*N�����ӣ�ÿ�������з���һ��������ƻ����
//������Ͻǵĸ��ӿ�ʼ�� ÿһ��ֻ�������߻��������ߣ�
//ÿ���ߵ�һ�������ϾͰѸ������ƻ���ռ�������
//������ȥ����������ռ������ٸ�ƻ����
//ʱ�临�Ӷȣ�O(M*N)
//�ռ临�Ӷȣ�O(M*N)
#define M 4
#define N 4
int a[M][N] = {{1, 2, 1, 1},
                {1, 1, 3, 1},
                {1, 4, 2, 6},
                {1, 5, 1, 1}};
int apple(int m, int n)
{
    if (m < 0 || n < 0 || m >= M || n >= N)
        return -1;

    int d[M][N];
    d[0][0] = a[0][0];
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int max = 0;
            if (j > 0 && d[i][j-1] > max) max = d[i][j-1];
            if (i > 0 && d[i-1][j] > max) max = d[i-1][j];
            d[i][j] = max + a[i][j];
        }
    }
    return d[m][n];
}


int main ()
{
    cout << "5 5:17:" << apple(3,3) << endl;
    cout << "2 2:4:" << apple(1,1) << endl;
    cout << "3 2:8:" << apple(2,1) << endl;
    return 0;
}
