/*
ID: duyimin1
PROG: nocows
LANG: C++    
*/
/*
二叉树总共有N个节点(3 <= N < 200)。有如下性质:每一个节点的度是0或2。树的高度等于K(1 < K <100)。高度是从根到最远的那个叶子所需要经过的结点数;叶子是指没有孩子的节点。有多少不同的结构
*/
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<fstream>
using namespace std;
int n , k;
int f[201];
int high ;
int matrix[100][200];
int  dfs(int m)
{
	if(m == 1)
		return 1;
	if(m == 2)
		return 0;
	int temp = high;
	f[m] = 0;
	if(matrix[k - high][m])
		return matrix[k - high][m];
	if(m % 2 == 1)
	{
		for(int j = 1 ; j <= (m - 2) / 2 ;j++)
		{
			if(high + 1 < k)
			{
				high++;
				if(!matrix[k - high][j] && j % 2 != 0)
					matrix[k - high][j] = dfs(j);
				if(!matrix[k - high][m - j - 1] && (m - j - 1) % 2 != 0)
					matrix[k - high][m - j - 1] = dfs(m - j - 1);
				f[m] += matrix[k - high][j] * matrix[k - high][m - j - 1] % 9901;
			}
			else
				break;
			high = temp;
		}
		f[m] *= 2;
		if(high + 1 < k)
		{
			high++;
			if(!matrix[k - high][(m - 2) / 2 + 1] && ((m - 2) / 2 + 1) % 2 != 0)
				matrix[k - high][(m - 2) / 2 + 1] = dfs((m - 2) / 2 + 1);
			f[m] += matrix[k - high][(m - 2) / 2 + 1] * matrix[k - high][(m - 2) / 2 + 1] % 9901;
		}
		high = temp;
		matrix[k - high][m] = f[m];
	}
	return f[m] % 9901;
}
int main()
{
	ofstream fout("nocows.out");
	ifstream fin("nocows.in");
	fin>>n>>k;
	for(int i = 0; i < 201 ; i++)
		f[i] = 0;
	f[1] = 1;
	f[2] = 0;
	high = 0;
	int t1 = dfs(n);
	for(int i = 0; i < 201 ; i++)
		f[i] = 0;
	f[1] = 1;
	f[2] = 0;
	high = 0;
	k--;
	int t2 = dfs(n);
	fout<<(t1 + 9901 - t2) % 9901<<endl;
}
