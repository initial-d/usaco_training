/*
ID: duyimin1
PROG: agrinet
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
ofstream fout ("agrinet.out");
ifstream fin ("agrinet.in");

const int INF = 1<<30;
int n;
int ans;
int Min;
int g[101][101];
bool vis[101];
int dis[101];
void prim(int v)
{
	memset(vis , 0 ,sizeof(vis));
	for(int i = 1 ; i <= n ;i++)
	{
		dis[i] = g[v][i];
	}
	vis[1] = true;
	for(int i = 1 ;  i <= n;i++)
	{		
		Min = INF;
		int k;
		for(int j = 1 ; j <= n;j++)
		{
			if(!vis[j] && dis[j] < Min)
			{
				Min = dis[j];
				k = j;
			}
		}
		if(Min < INF)
		{
			vis[k] = true;
			ans += Min;
		}
		for(int j = 1 ; j <= n;j++)
		{
			if(!vis[j] && dis[j] > g[k][j])
			{
				dis[j] = g[k][j];
			}
		}
	}
}
int main()
{
	fin>>n;
	for(int i = 1; i <= n ;i++)
	{
		for(int j = 1 ;j <= n;j++)
		{
			fin>>g[i][j];			
		}
	}
	ans = 0;
	prim(1);
	fout<<ans<<endl;
	return 0;
}
