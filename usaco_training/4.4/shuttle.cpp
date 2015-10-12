/*
ID: duyimin1
PROG: shuttle
LANG: C++
*/
/*������bfs,���Ǻ������˫����ܹ�������Ļ�Ҫ��һЩ��֦�����Ǵ�ţֱ�Ӱ����⵱�������ֹ�����*/
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <ctime>
using namespace std;
typedef long long ll;
#define clr(x,a) memset(x,a,sizeof(x))
#define sz(x) (int)x.size()
#define see(x) cerr<<#x<<" "<<x<<endl
#define se(x) cerr<<" "<<x
#define pb push_back
#define mp make_pair
#define INF 1<<30
#define MAX_V 410
ofstream fout ("shuttle.out");
ifstream fin ("shuttle.in");

int main()
{
    int n,t,s,res[500],tt=0;
    memset(res,0,sizeof(res));
    fin>>n;
    for (int i=2; i<=n+1; i++)
    {
        if (i%2==1) t=-2;
        else t=2;
        if (i%2==1) s=n+i;
        else s=n-i+2;
        res[++tt]=s;
        for (int j=2; j<=i; j++)
        {
            s+=t;
            res[++tt]=s;
        }
    }
    for (int i=n; i>=2; i--)
    {
        if (i%2==1) t=-2;
        else t=2;
        if (i%2==1) s=n+i;
        else s=n-i+2;
        res[++tt]=s;
        for (int j=2; j<=i; j++)
        {
            s+=t;
            res[++tt]=s;
        }
    }
    res[++tt]=n+1;
    for (int i=1; i<=tt; i++)
    {
        fout<<res[i];
        if ((i%20==0)||(i==tt)) fout<<endl;
        else fout<<" ";
    }
    return 0;
}
