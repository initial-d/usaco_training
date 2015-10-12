/*
ID: duyimin1
PROG: maze1
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
using namespace std;
ofstream fout ("maze1.out");
ifstream fin ("maze1.in");

int w , h;
struct point
{
	int x;
	int y;
};
vector<point> door;
bool cnt[101][40];
int ans[101][40];
char foo[210][80];
void input()
{
	fin>>w>>h;
	for(int i = 0 ; i <= 2 * h + 1; i++)
	{
		fin.getline(foo[i] , 79);
	}
	for(int i = 1 ; i <= 2 * h + 1; i++)
	{
		for(int j = 0 ; j < 2 * w + 1; j++)
		{
			if(i == 1)
				if(foo[i][j] == ' ')
				{
					point temp;
					temp.x = i;
					temp.y = (j+1) / 2;
					door.push_back(temp);
				}
			if(i == 2 * h + 1)
				if(foo[i][j] == ' ')
				{
					point temp;
					temp.x = i / 2;
					temp.y = (j + 1) / 2;
					door.push_back(temp);
				}
			if(j == 0)
				if(foo[i][j] == ' ')
				{
					point temp;
					temp.x = i / 2;
					temp.y = j + 1;
					door.push_back(temp);
				}
			if(j == 2 * w)
				if(foo[i][j] == ' ')
				{
					point temp;
					temp.x = i / 2;
					temp.y = (j + 1) / 2;
					door.push_back(temp);
				}
		}
	}
}
void bfs(point a)
{
	queue<point> que;
	que.push(a);
	ans[a.x][a.y] = 1;
	while(!que.empty())
	{
		point t = que.front();
		que.pop();
		int i = t.x;
		int j = t.y;
		cnt[i][j] = true;
		int dis = ans[i][j];
		if(2 * i - 1 > 1 && foo[2 * i - 1][2 * j - 1] == ' ' && cnt[i - 1][j] == false)
		{
			t.x = i - 1;
			t.y = j;
			cnt[i - 1][j] = true;
			ans[i - 1][j] = dis + 1;
			que.push(t);
		}
		if(2 * j < 2 * w  && foo[2 * i][2 * j] == ' ' && cnt[i][j + 1] == false)
		{
			t.x = i;
			t.y = j + 1;
			cnt[i][j + 1] = true;
			ans[i][j + 1] = dis + 1;
			que.push(t);
		}
		if(2 * i + 1 < 2 * h + 1 && foo[2 * i + 1][2 * j - 1] == ' ' && cnt[i + 1][j] == false)
		{
			t.x = i + 1;
			t.y = j;
			cnt[i + 1][j] = true;
			ans[i + 1][j] = dis + 1;
			que.push(t);
		}
		if(2 * j - 2 > 0 && foo[2 * i][2 * j - 2] == ' ' && cnt[i][j - 1] == false)
		{
			t.x = i;
			t.y = j - 1;
			cnt[i][j - 1] = true;
			ans[i][j - 1] = dis + 1;
			que.push(t);
		}
	}
}
int main()
{
	input();
	memset(cnt , false , sizeof(cnt));
	memset(ans , 0 , sizeof(ans));
	bfs(door[0]);
	int ans1[101][40];
	int Max = 0;
	for(int i = 1 ; i <= h ;i++)
		for(int j = 1 ; j <= w ;j++)
		{
			ans1[i][j] = ans[i][j];
		}
	memset(cnt , false , sizeof(cnt));
	memset(ans , 0 , sizeof(ans));
	bfs(door[1]);
	for(int i = 1 ; i <= h ;i++)
		for(int j = 1 ; j <= w ;j++)
		{
			ans[i][j] = min(ans[i][j] , ans1[i][j]);
			if(ans[i][j] > Max)
				Max = ans[i][j];
		}
	fout<<Max<<endl;
}
