#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;
int n,num;
int cnt[1001],ans[1001];
int main()
{
	ofstream fout ("sort3.out");
         ifstream fin ("sort3.in");
	fin>>n;
	for(int i = 0 ; i < n ;i++)
	{
		fin>>ans[i];
		cnt[i] = ans[i];
	}
	sort(ans , ans + n);
	num = 0;
	int temp;
	for(int i = 0 ; i < n; i++)
	{
		if(ans[i] == cnt[i])
			continue;
		else
		{
			bool flag = true;
			for(int j = i + 1; j < n ; j++)
			{
				if(ans[j] != cnt[j] && cnt[j] == ans[i] && cnt[i] == ans[j])
				{
					temp = cnt[i];
					cnt[i] = cnt[j];
					cnt[j] = temp;
					num++;
					flag = false;
					break;
				}
			}
			if(flag)
				for(int j = i + 1; j < n ; j++)
				{
					if(ans[j] != cnt[j] && cnt[j] == ans[i])
					{
						temp = cnt[i];
						cnt[i] = cnt[j];
						cnt[j] = temp;
						num++;
						break;
					}
				}
		}
	}
	fout<<num<<endl;
 	return 0;
}
