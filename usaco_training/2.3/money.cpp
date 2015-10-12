/*
ID: duyimin1
PROG: money
LANG: C++
*/
������N�ø�����v�������л��ֵ��������������е��������ظ���
�ⷨ����̬�滮
cnt[i][j]��ʾ��i��ֵ��������Ϊj����������Ҫôû��j,��Ϊcnt[i][j - 1];Ҫô������һ��j����Ϊcnt[i-j][j];����
��̬�滮��ת�Ʒ���Ϊ��cnt[i][j] = cnt[i][j-1] + cnt[i-j][j]

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
