/*
ID: duyimin1
PROG: nuggets
LANG: C++
*/
//优化：最小公倍数缩小问题规模。
#include<iostream>
#include<set>
#include<math.h>
#include<vector>
#include<fstream>
#include<algorithm>
#include<stdio.h>
using namespace std;
ofstream fout ("nuggets.out");
ifstream fin ("nuggets.in");

int cnt[11];
bool vis[1000000];
int N;
int gcd(int a , int b)
{
    if(a > b)
        return b == 0 ? a : gcd(b , a % b);
    else
        return a == 0 ? b : gcd(a , b % a);
}
int main()
{
    fin>>N;
    for(int i = 0 ;  i < N ; i++)
        fin>>cnt[i];
    if(N == 1)
    {
        fout<<0<<endl;
        return 0;
    }
    sort(cnt , cnt + N);
    int temp  = cnt[0];
    for(int i = 1 ; i < N ; i++)
    {
        temp = gcd(temp , cnt[i]);
    }
    if(temp != 1)
    {
        fout<<0<<endl;
        return 0;
    }
    vis[0] = true;
    int tar = cnt[N - 1] * cnt[N - 2] * gcd(cnt[N - 1] , cnt[N - 2]);
    for(int i = 0 ; i < N ; i++)
    {
        for(int j = cnt[i] ; j <= tar ; j++)
            if(vis[j - cnt[i]])
                vis[j] = true;
    }
    int i;
    for(i = tar ; i > 0 ; i--)
    {
        if(!vis[i])
            break;
    }
    fout<<i<<endl;
    return 0;
}
