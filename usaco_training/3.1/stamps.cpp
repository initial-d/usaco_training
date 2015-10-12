/*
ID: duyimin1
PROG: stamps
LANG: C++
*/
#include<iostream>
#include<algorithm>
#include<fstream>
#include<map>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<cmath>
#include<set>
#include<iomanip>
using namespace std;

ofstream fout ("stamps.out");
ifstream fin ("stamps.in");
int k , n ;
int cnt[51];
int ans[2000010];
int main()
{
    fin>>k>>n;
    int m = 0;
    for(int i = 0 ; i < n ; i++)
    {
        fin>>cnt[i];
        if(cnt[i] > m)
            m = cnt[i];
    }
    sort(cnt , cnt + n);
    memset(ans , 1<<30 , sizeof(ans));
    ans[0] = 0;
    for(int i = 1 ; i <= k * m + 1;i++)
    {
        int Min = 1<<30;
        for(int j = 0 ; j < n ; j++)
        {
            if(i - cnt[j] >= 0)
            {
                int temp = ans[i - cnt[j]] + 1;
                if(Min > temp)
                    Min = temp;
            }
            else
                break;
        }
        ans[i] = Min;
        if(Min > k)
        {
            fout<<i - 1<<endl;
            break;
        }
    }
    return 0;
}
