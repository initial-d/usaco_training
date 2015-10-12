/*
ID: duyimin1
PROG: fence
LANG: C++
*/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<fstream>
#include<queue>
#define INF 1000000050
using namespace std;
ofstream fout ("fence.out");
ifstream fin ("fence.in");
int cnt[501][501];
int du[501];
int ans[501];
int F;
int tt;
void euler(int s)
{
    for(int k = 1 ; k <= 500 ; k++)
    {
        if(cnt[s][k] > 0)
        {
            cnt[s][k]--;
            cnt[k][s]--;
            euler(k);
        }
    }
    tt++;
    ans[tt] = s;

}
int main()
{
    memset(cnt , 0 , sizeof(cnt));
    memset(du , 0 , sizeof(du));
    memset(ans , 0 , sizeof(ans));
    fin>>F;
    int a , b;
    for(int i = 0 ; i < F; i++)
    {
        fin>>a>>b;
        cnt[a][b]++;
        cnt[b][a]++;
        du[a]++;
        du[b]++;
    }
    int i , j;
    tt = 0;
    for(i = 0 ; i <= 500 ; i++)
        if(du[i] % 2 == 1)
            break;
    if(i == 501)
    {
        for(j = 0 ; j <= 500 ;j++)
            if(du[j])
                break;
        euler(j);
    }
    else
        euler(i);
    for(i = tt ; i > 0 ; i--)
        fout<<ans[i]<<endl;
    return 0;
}
