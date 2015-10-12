/*
ID: duyimin1
PROG: rockers
LANG: C++
*/
#include<iostream>
#include<algorithm>
#include<fstream>
#include<string.h>
using namespace std;
ofstream fout ("rockers.out");
ifstream fin ("rockers.in");
const int nMax = 10001;
const int mMax = 10001;

int o[mMax];
int main()
{
    int n,m,t,i,w,dp[21][21];
    fin>>n>>t>>m;
    for(i = 1; i <= n; i++)
    {
        fin>>o[i];
    }
    memset(dp , 0 , sizeof(dp));
    for(int k = 1 ; k <= n ; k++)
    {
        for(i = m; i > 0; i--)
        {
            for(w = t; w >= o[k] ; w--)
            {
                if(dp[i][w] < dp[i - 1][t] + 1)
                    dp[i][w] = dp[i - 1][t] + 1;
                if(dp[i][w] < dp[i][w-o[k]] + 1)
                {
                    dp[i][w] = dp[i][w-o[k]] + 1;
                }
            }
        }
    }
    fout<<dp[m][t]<<endl;
    return 0;
}
