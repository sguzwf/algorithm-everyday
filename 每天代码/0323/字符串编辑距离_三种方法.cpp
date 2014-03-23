#include <iostream>
#include <string>
#include <cstring>
#include <cassert>
using namespace std;

//×Ö·û´®±à¼­¾àÀë
//µİ¹é·¨
int calculateStringDistance1(string str1, int begin1, int end1, string str2, int begin2, int end2)
{
    if (begin1 > end1)
    {
        if (begin2 > end2)  return 0;
        else return end2 - begin2 + 1;
    }
    if (begin2 > end2)
    {
        if (begin1 > end1)  return 0;
        else return end1 - begin1 + 1;
    }
    if (str1[begin1] == str2[begin2])
        return calculateStringDistance1(str1, begin1+1, end1, str2, begin2+1, end2);
    else
    {
        int t1 = calculateStringDistance1(str1, begin1+1, end1, str2, begin2+1, end2);
        int t2 = calculateStringDistance1(str1, begin1+1, end1, str2, begin2, end2);
        int t3 = calculateStringDistance1(str1, begin1, end1, str2, begin2+1, end2);
        return min(min(t1, t2),t3) + 1;
    }
}

//×Ö·û´®±à¼­¾àÀë
//±¸ÍüÂ¼·¨
//d[i][j]±íÊ¾str1[i, end1]Óëstr2[j, end2]µÄ±à¼­¾àÀë
int d[2000][2000];
int calculateStringDistance2(string str1, int begin1, int end1, string str2, int begin2, int end2)
{
    if (begin1 > end1)
    {
        if (begin2 > end2){
            d[begin1][begin2] = 0;
        }
        else{
            d[begin1][begin2] = end2 - begin2 + 1;
        }
    }
    if (begin2 > end2)
    {
        if (begin1 > end1){
            d[begin1][begin2] = 0;
        }
        else{
            d[begin1][begin2] = end2 - begin2 + 1;
        }
    }
    if (d[begin1][begin2] < 0x7f )//ÈôÒÑÔÚ±¸ÍüÂ¼ÖĞ
        return d[begin1][begin2];
    if (str1[begin1] == str2[begin2]){
        d[begin1][begin2] = calculateStringDistance2(str1, begin1+1, end1, str2, begin2+1, end2);
    }
    else
    {
        int t1 = calculateStringDistance2(str1, begin1+1, end1, str2, begin2+1, end2);
        int t2 = calculateStringDistance2(str1, begin1+1, end1, str2, begin2, end2);
        int t3 = calculateStringDistance2(str1, begin1, end1, str2, begin2+1, end2);
        d[begin1][begin2] = min(min(t1, t2),t3) + 1;
    }
    return d[begin1][begin2];
}

//×Ö·û´®±à¼­¾àÀë
//¶¯Ì¬¹æ»®·¨
//d[i][j]±íÊ¾str1[i, len1-1]Óëstr2[j, len2-1]µÄ±à¼­¾àÀë
int calculateStringDistance3(string str1, string str2)
{
    int len1 = str1.length();
    int len2 = str2.length();

    int **d = new int*[len1+1];
    for (int i = 0; i < len1+1; i++)
        d[i] = new int[len2+1];

    for (int i = 0; i < len1; i++)
        d[i][len2] = len1 - i;
    for (int i = 0; i < len2; i++)
        d[len1][i] = len2 - i;
    d[len1][len2] = 0;
    for (int i = len1-1; i >= 0; i--)
    {
        for (int j = len2 - 1; j >= 0; j--)
        {
            if (str1[i] == str2[j])
                d[i][j] = d[i+1][j+1];
            else
                d[i][j] = min(min(d[i+1][j], d[i][j+1]), d[i+1][j+1]) + 1;
        }
    }
    int dis = d[0][0];
    for (int i = 0; i < len1+1; i++)
        delete []d[i];
    delete []d;
    return dis;
}

int main ()
{
    string str1, str2;
    while (cin >> str1 >> str2)
    {
        cout << calculateStringDistance3(str1, str2) << endl;
        //memset(d, 0x7f, sizeof(d));
        //cout << calculateStringDistance2(str1, 0, str1.length()-1, str2, 0, str2.length()-1) << endl;
    }
    return 0;
}
