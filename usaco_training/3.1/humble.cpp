/*
ID: duyimin1
PROG: humble
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
#include<set>
#include<iomanip>
using namespace std;
ofstream fout ("humble.out");
ifstream fin ("humble.in");

int k,n,temp;
vector<int> prim;
vector<int> cosor;
vector<long long> vec;
map<long , long> ss;
long long a[100003];
int main()
{
	fin>>k>>n;
	for(int i = 0 ;i < k ;i++)
	{
		fin>>temp;
		prim.push_back(temp);
		cosor.push_back(1);
		vec.push_back(0);
	}
	a[1]=1;
	for(int i = 2;i <= n+1;)
	{
		int t;
		for(int j = 0 ; j < k ; j++)
		{
			vec[j] = a[cosor[j]] * prim[j];
		}
		long long Min = 9223372036854775807;
		t = 0;
		for(int j = 0; j < k ;j++)
		{
			if(vec[j] <  Min)
			{
				Min = vec[j];
				t = j;
			}		 
		}
		if(ss[Min])
		{
			cosor[t]++;
			continue;
		}
		ss[Min] = Min;
		a[i] = Min;
		cosor[t]++;
		i++;
	}
	fout<<a[n+1]<<endl;
	return 0;
}
