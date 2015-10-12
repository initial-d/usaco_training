/*
ID: duyimin1
PROG: theme
LANG: C++
*/
#include<iostream>
#include<stdio.h>
#include<fstream>
#include<string>
#include<string.h>
#include<iomanip>
#include<math.h>
#include<algorithm>
#define PI acos(double(-1))
#define INF  999999999

using namespace std;
ifstream fin("theme.in");
ofstream fout("theme.out");

const int maxn=5002;
short int v[maxn];
int ans,n;
void doit()
{
    ans=0;
    for (int i=5; i<n; i++)
    {
        int len=0, dis=100;
        for (int j=1; j+i<=n; j++)
            if (v[j]-v[j+i]==dis)
            {
                if (len==i) break;
                len++;
                if (len>=5) ans=max(ans,len);
            }
            else
            {
                len=1;
                dis=v[j]-v[i+j];
            }
    }
}

int main()
{
    fin>>n;
    for (int i=1; i<=n; i++)
        fin>>v[i];
    doit();
    fout<<ans<<endl;
    return 0;
}
