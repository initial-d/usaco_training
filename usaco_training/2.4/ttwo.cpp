/*
ID: duyimin1
PROG: ttwo
LANG: C++
*/
#include<iostream>
#include<algorithm>
#include<fstream>
#include<map>
#include<vector>
using namespace std;

char cnt[11][11];
int n;
int time1 = 0;
int cowx , cowy , farmerx , farmery , dreC , dreF;
bool flag = true;
int main()
{
	ofstream fout ("ttwo.out");
    ifstream fin ("ttwo.in");
	int temp1x ,temp1y ,temp2x ,temp2y; 
	for(int i = 1 ; i < 11 ;i++)
	{
		for(int j = 1 ; j < 11 ;j++)
		{
			fin>>cnt[i][j];
			if(cnt[i][j] == 'C')
			{
				cowx = i;
				cowy = j;				
			}
			if(cnt[i][j] == 'F')
			{
				farmerx = i;
				farmery = j;
			}
		}
	}
	dreC = 0;
	dreF = 0;
	while(1)
	{
		if(cowx == farmerx && cowy == farmery)
			break;
		time1++;
		if(dreC == 0)
		{
			if(cowx - 1 > 0 && cnt[cowx - 1][cowy] != '*')
			{
				cowx--;
			}
			else
			{
				dreC++;
				dreC %= 4;
			}	
		}
		else if(dreC == 1)
		{
			if(cowy + 1 <= 10 && cnt[cowx][cowy + 1] != '*')
			{
				cowy++;
			}
			else
			{
				dreC++;
				dreC %= 4;
			}	
		}
		else if(dreC == 2)
		{
			if(cowx + 1 <= 10 && cnt[cowx + 1][cowy] != '*')
			{
				cowx++;
			}
			else
			{
				dreC++;
				dreC %= 4;
			}	
		}
		else if(dreC == 3)
		{
			if(cowy - 1 > 0 && cnt[cowx][cowy - 1] != '*')
			{
				cowy--;
			}
			else
			{
				dreC++;
				dreC %= 4;
			}	
		}

		if(dreF == 0)
		{
			if(farmerx - 1 > 0 && cnt[farmerx - 1][farmery] != '*')
			{
				farmerx--;
			}
			else
			{
				dreF++;
				dreF %= 4;
			}	
		}
		else if(dreF == 1)
		{
			if(farmery + 1 <= 10 && cnt[farmerx][farmery + 1] != '*')
			{
				farmery++;
			}
			else
			{
				dreF++;
				dreF %= 4;
			}	
		}
		else if(dreF == 2)
		{
			if(farmerx + 1 <= 10 && cnt[farmerx + 1][farmery] != '*')
			{
				farmerx++;
			}
			else
			{
				dreF++;
				dreF %= 4;
			}	
		}
		else if(dreF == 3)
		{
			if(farmery - 1 > 0 && cnt[farmerx][farmery - 1] != '*')
			{
				farmery--;
			}
			else
			{
				dreF++;
				dreF %= 4;
			}	
		}
		if(time1 > 160000)
		{
			flag = false;
			break;
		}
	}
	if(flag)
		fout<<time1<<endl;
	else
		fout<<0<<endl;
}
