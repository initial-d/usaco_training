/*
ID: duyimin1
PROG: hamming
LANG: C++
*/

#include<iostream>
#include<algorithm>
#include<fstream>
#include<vector>
#include<map>
using namespace std;

int n,b,d;
map<int , vector<bool> > bit;
void calbit(int val)
{
	int tmp = val;
	while(val)
	{
		bit[tmp].push_back(val%2);
		val /= 2;
	}
	while(bit[tmp].size() < 7)
		bit[tmp].push_back(0);
}
bool cal_dis(int i , int j)
{
	int num = 0;
	for(int k = 0 ; k < b; k++)
	{
		if(bit[i][k] != bit[j][k])
			num++;
	}
	if(num >= d)
		return true;
	else
		return false;
}
int main()
{
	ofstream fout ("hamming.out");
    ifstream fin ("hamming.in");
	vector<int> ans;
	fin>>n>>b>>d;
	calbit(0);
	ans.push_back(0);
	bool flag;
	int foo = 0;
	for(int i = 1 ; i < 2 << b ;i++)
	{
		calbit(i);
		flag = true;
		for(int j = 0 ; j < ans.size() ; j++)
		{
			if(!cal_dis(i , ans[j]))
			{
				flag = false;
				break;
			}
		}
		if(flag)
		{
			foo++;
			ans.push_back(i);
			if(foo == n)
				break;
		}
	}
	for(int i = 0 ; i < ans.size()&&i < n; i++)
	{
			if(i % 10 == 0 && i != 0)
				fout<<endl;
			if(i % 10 == 0)
				fout<<ans[i];
			else
				fout<<" "<<ans[i];
	}
	fout<<endl;
 	return 0;
}
