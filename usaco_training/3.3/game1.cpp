/*
ID: duyimin1
PROG: game1
LANG: C++
*/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<fstream>
#include<queue>
#define INF 1000000050
using namespace std;
ofstream fout ("game1.out");
ifstream fin ("game1.in");

int n;
int cnt[201];
int dp[201][201];
int sum = 0;
int main()
{
    fin>>n;
    for(int i = 1 ; i <= n; i++)
    {
        fin>>cnt[i];
        sum += cnt[i];
    }
    for(int i = n ; i >= 1 ; i--)
        for(int j = i ; j <= n ;j++)
    {
        if((n - (j - i + 1)) & 1 == 1)
            dp[i][j] = max(dp[i+1][j] + cnt[i], dp[i][j-1] + cnt[j]);
        else
            dp[i][j] = min(dp[i+1][j] , dp[i][j-1]);
    }
    fout<<sum - dp[1][n]<<" "<<dp[1][n]<<endl;
    return 0;
}
