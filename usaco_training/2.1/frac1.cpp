/*
ID: duyimin1
PROG: frac1
LANG: C++
*/
#include<iostream>
#include<algorithm>
#include<fstream>
struct point 
{
	int x;
	int y;
};
point cnt[10000];
using namespace std;

bool cmp(point a , point b)
{
	return a.x * b.y < a.y * b.x;
}
int gcd(int m , int n)
{
	return n == 0 ? m : gcd(n,m%n);
}
int main()
{
	ofstream fout ("frac1.out");
    ifstream fin ("frac1.in");
	int m;
	int t = 0;
	cnt[t].x = 0;
	cnt[t++].y = 1;
	fin>>m;
	for(int i = 1; i <= m ;i++)
	{
		cnt[t].x = 1;
		cnt[t++].y = i;
	}
	for(int i = 2 ; i < m ;i++)
		for(int j = i + 1 ; j <= m ;j++)
		{
			if(j % i != 0 && gcd(i , j) == 1)
			{
				cnt[t].x = i;
				cnt[t++].y = j;
			}
		}
	sort(cnt , cnt + t, cmp);
	for(int i = 0 ; i < t ;i++)
		fout<<cnt[i].x<<"/"<<cnt[i].y<<endl;
 	return 0;
}
