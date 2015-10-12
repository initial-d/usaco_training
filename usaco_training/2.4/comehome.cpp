/*
ID: duyimin1
PROG: comehome
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
ofstream fout ("comehome.out");
ifstream fin ("comehome.in");

const int INF = 1<<25;
int cnt[55][55];
int dis[55];
bool vis[55];
int n;
void input()
{
	for(int i = 1 ; i <= 52 ;i++){
		for(int j = 1 ; j <= 52 ;j++)
			cnt[i][j] = INF;
	}
	fin>>n;
	char a,b;
	int c , a1, b1;
	for(int i = 0 ;i < n ;i++)
	{
		fin>>a>>b>>c;
		if(isupper(a))
			a1 = a - 'A' + 1;
		else if(islower(a))
			a1 = a - 'a' + 1 + 26;
		if(isupper(b))
			b1 = b - 'A' + 1;
		else if(islower(b))
			b1 = b - 'a' + 1 + 26;
		if(cnt[a1][b1] > c)
			cnt[a1][b1] = cnt[b1][a1]  = c;
	}
	memset(vis , false ,sizeof(vis));
	for(int i = 1 ; i <= 52 ;i++)
		dis[i] = INF;
	dis[26] = 0;
}
void dijstra()
{
	int t = 0;
	while(t++ < 52)
	{
		int Max = INF;
		int pos;
		for(int i = 1 ; i <= 52 ;i++)
		{
			if(!vis[i] && dis[i] <= Max)
			{
				Max = dis[i];
				pos = i;
			}
		}
		vis[pos] = true;
		for(int j = 1 ; j <= 52 ;j++)
		{
			if(dis[pos] + cnt[pos][j] < dis[j])
			{
				dis[j] = dis[pos] + cnt[pos][j];
			}
		}
	}
}
void output()
{
	int Min = INF;
	int pos;
	for(int i = 1 ; i <= 26 ;i++)
	{
		if(i != 26 && dis[i] < Min)
		{
			Min = dis[i];
			pos = i;
		}
	}
	fout<<(char)(pos + 'A' - 1)<<" "<<Min<<endl;
}

int main()
{
	input();
	dijstra();
	output();
}
