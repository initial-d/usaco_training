/*
ID: duyimin1
PROG: fracdec
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
ofstream fout ("fracdec.out");
ifstream fin ("fracdec.in");

int n,d ,z ,r;
map<int , int> bt;
int ans[1000000];
int s = 1;
bool flag = false;
int pos;
void div()
{
	bt[r] = s;
	while(r / d == 0)
	{
		r *= 10;
		if(bt[r])
		{
			flag = true;
			ans[s++] = 0;
			pos = bt[r];
			return;
		}
		ans[s++] = 0;
	}
	ans[s-1] = r / d;
	r = r % d;
	if(r == 0)
		return;
	if(bt[r])
	{
		flag = true;
		pos = bt[r];
		return;
	}
	else
		div();
}
void output()
{
	fout<<z<<".";
	int count = 0;
	if(z == 0)
		count = 1;
	while(z)
	{
		count++;
		z /= 10;
	}
	count++;
	if(flag)
	{
		for(int i = 1 ; i < s; i++)
		{
			if(i == pos)
			{
				fout<<"(";
				count++;
				if(count > 75)
				{
					fout<<endl;
					count = 0;
				}
			}
			fout<<ans[i];
			count++;
			if(count > 75)
			{
				fout<<endl;
				count = 0;
			}
		}
		fout<<")"<<endl;
	}
	else{	
		for(int i = 1 ; i < s; i++)
			fout<<ans[i];
		fout<<endl;}
}
int main()
{
	fin>>n>>d;
	z = n / d;
	r = n % d;
	if(r != 0)
	{
		div();
		output();
	}
	else
		fout<<z<<"."<<0<<endl;
}
