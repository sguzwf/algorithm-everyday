#include <iostream>
#include <string>
#include <cstring>
using namespace std;

//N的阶乘末尾0的数量

//逐个判断
int func1(int n)
{
    int count = 0;
    for (; n > 4; n--)
    {
        int i = n;
        while (i % 5 == 0 && i != 0)
        {
            i /= 5;
            count++;
        }
    }
    return count;
}
//找5的个数
int func2(int n)
{
    int count = 0;
    while (n/5 != 0)
    {
        count += n/5;
        n /= 5;
    }
    return count;
}

int main ()
{
    int n;
    while (cin >> n)
    {
        cout << func1(n) << endl;
        cout << func2(n) << endl;
    }
    return 0;
}
