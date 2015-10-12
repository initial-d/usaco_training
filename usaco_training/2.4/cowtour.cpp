/*
ID: duyimin1
PROG: cowtour
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
ofstream fout ("cowtour.out");
ifstream fin ("cowtour.in");

double Max = 10000000.0;
double tt =0.0;
struct point
{
	double x;
	double y;
};
point cnt[151];
int foo[151][151];
double dis[151][151];

int parent[151];
int n;

void make_set()
{
    for(int x = 1; x <= n; x++)
    {
        parent[x] = x;
    }
}

int find_set(int x)
{
    if(x != parent[x])
        parent[x] = find_set(parent[x]);
    return parent[x];
}

void union_set(int x, int y)
{
    x = find_set(x);
    y = find_set(y);
    if(x == y) return;
	parent[y] = x;    
}

void input()
{
	fin>>n;
	char str[151][151];
	for(int i = 1 ;i <= n ;i++)
		fin>>cnt[i].x>>cnt[i].y;
	for(int i = 1 ;i <= n;i++)
		fin>>str[i];
	for(int i = 1 ;i <= n;i++)
		for(int j = 0 ; j < n;j++)
			foo[i][j + 1] = str[i][j] - '0';
	for(int i = 1; i <= n;i++)
		for(int j = 1 ;j <= n;j++)
			dis[i][j] = 10000000.0;
}
double cal(point a , point b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
void caldis()
{
	for(int i = 1 ;i <= n;i++)
		for(int j = i ; j <= n;j++)
		{
			if(foo[i][j])
			{	
				dis[i][j] = dis[j][i] = cal(cnt[i] , cnt[j]);
				union_set(i , j);
			}		   
		}
}
void floyd()
{
	for(int k = 1 ;k <= n ;k++)
		for(int i = 1 ;i <= n;i++)
			for(int j = 1 ; j <= n;j++)
				if(foo[i][k] && foo[k][j])
					foo[i][j] = 1;
	for(int k = 1 ;k <= n ;k++)
		for(int i = 1 ;i <= n;i++)
			for(int j = 1 ; j <= n;j++)
				if(foo[i][j] && foo[i][k] && foo[k][j] && dis[i][j] > dis[i][k] + dis[k][j])
					dis[i][j] = dis[i][k] + dis[k][j];
	for(int i = 1 ;i <= n;i++)
		for(int j = 1 ; j <= n;j++)
		{
			if(foo[i][j])			
			{
				if(tt < dis[i][j])
					tt = dis[i][j];
			}

		}
}
void slove()
{
	double maxi , maxj ,temp;
	for(int i = 1 ;i <= n;i++)
		for(int j = 1 ; j <= n;j++)
		{
			if(find_set(i) != find_set(j))
			{
				dis[i][j] = dis[j][i] = cal(cnt[i] , cnt[j]);
				maxi = 0;
				maxj = 0;
				for(int k = 1 ;k <= n; k++)
				{
					if(i != k && find_set(i) == find_set(k))
					{
						if(dis[i][k] > maxi)
							maxi = dis[i][k];
					}
					if(j != k && find_set(j) == find_set(k))
					{
						if(dis[j][k] > maxj)
							maxj = dis[j][k];
					}
				}
				temp = maxi + maxj + dis[i][j];
				if(temp < Max)
				{
					Max = temp;
				}
				dis[i][j] = dis[j][i] = 10000000.0;
			}		
		}
}
void output()
{
	if(tt < Max)
		fout<<fixed<<setprecision(6)<<Max<<endl;
	else
		fout<<fixed<<setprecision(6)<<tt<<endl;
}
int main()
{
	input();
	make_set();
	caldis();
	floyd();
	slove();
	output();
}
