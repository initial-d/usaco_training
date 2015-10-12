/*
ID: duyimin1
PROG: subset
LANG: C++
*/
/*�Ѵ�1��N (1 <= N <= 39) �������������ϻ��ֳ������Ӽ��ϣ��ұ�֤ÿ�����ϵ����ֺ�����ȵġ�
�ⷨ���������ϵĺ���ͬ������1~N�ĺ͵�һ������������֣������͵�һ�������ɲ�ͬ���ĺͣ�����1~N�ĺ�Ϊ���������޽⡣
��̬�滮��״̬����Ϊ��ans[N][sum] = ans[N - 1][sum - N] + ans[N - 1][sum];
ans[N][sum]��ʾǰN�������sum�����з�������ans[N-1][sum - N]��ʾ����N�ķ�������ans[N-1][sum]��ʾ������N�ķ�������
*/
#include<iostream>
#include<algorithm>
#include<fstream>
#include<vector>
#include<map>
using namespace std;

int n , sum ,t;
long long ans[40][800];
void dp(int sum)
{
	for(int i = 0; i <= n ; i++)
		ans[i][0] = 1;
	for(int i = 1; i <= sum ; i++)
		ans[0][i] = 0;
	ans[1][1] = 1;
	for(int i = 2; i <= n ;i++)
		for(int j = 1 ; j <= sum ; j++)
		{
			if(i > j)
				ans[i][j] = ans[j][j];
			else
				ans[i][j] = ans[i - 1][j - i] + ans[i - 1][j];
		}
}
int main()
{
	ofstream fout ("subset.out");
	ifstream fin ("subset.in");
	fin>>n;
	sum = 0; 
	t = 0;
	for(int i = 0; i < 40; i++)
		for(int j = 0 ; j < 800 ;j++)
			ans[i][j] = 0;
	for(int i = 1; i <= n; i++)
		sum += i;
	if(sum % 2 == 1)
		fout<<0<<endl;
	else
	{
		dp(sum / 2);
		fout<<ans[n][sum/2] / 2<<endl;
	}
 	return 0;
}
