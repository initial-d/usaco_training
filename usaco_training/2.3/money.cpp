/*
ID: duyimin1
PROG: money
LANG: C++
*/
求将整数N用给定的v个数进行划分的种类数，划分中的数可以重复。
解法：动态规划
cnt[i][j]表示将i拆分的数中最大为j的种类数，要么没有j,即为cnt[i][j - 1];要么至少有一个j，则为cnt[i-j][j];所以
动态规划在转移方程为：cnt[i][j] = cnt[i][j-1] + cnt[i-j][j]

#include<iostream>
#include<algorithm>
#include<fstream>
#include<map>
#include<vector>
using namespace std;
int n,v;
int tar[26];
long long cnt[10001][26];
int main()
{
	ofstream fout ("money.out");
    ifstream fin ("money.in");
	fin>>v>>n;
	for(int i =0 ; i< v; i++)
		fin>>tar[i];
	for(int i = 0; i < 10001 ; i++)
		for(int j = 0 ; j < 26 ;j++)
			cnt[i][j] = 0;
	for(int i = 1 ; i <= n; i++)
	{
		if(i % tar[0] == 0)
			cnt[i][0] = 1;
		else
			cnt[i][0] = 0;
	}
	for(int i = 0 ; i < v ;i++)
		cnt[0][i] = 1;
	for(int i = 1; i <= n ; i++)
		for(int j = 1 ; j < v ;j++)
		{
			if(i - tar[j] >= 0)
			{
				cnt[i][j] = cnt[i - tar[j]][j] + cnt[i][j - 1];
			}
			else
				cnt[i][j] = cnt[i][j - 1];
		}
	fout<<cnt[n][v - 1]<<endl;
}
