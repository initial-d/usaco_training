/*
ID: duyimin1
PROG: inflate
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
#include<iomanip>
using namespace std;
ofstream fout ("inflate.out");
ifstream fin ("inflate.in");

const int nMax = 10001;
const int mMax = 10001;

struct point
{
    int val;
    int wei;
}o[mMax];
int main()
{
    int n,m,i,w,dp[nMax];
    fin>>m>>n;
    for(i=1;i<=n;i++)
        fin>>o[i].val>>o[i].wei;
    memset(dp,0,sizeof(dp));
    for(i=1;i<=n;i++)
        for(w=o[i].wei;w<=m;w++)
        if(dp[w]<dp[w-o[i].wei]+o[i].val)
            dp[w]=dp[w-o[i].wei]+o[i].val;
    fout<<dp[m]<<endl;
    return 0;
}
