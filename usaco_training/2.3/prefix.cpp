/*
ID: duyimin1
PROG: prefix
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<string.h>
#include<string>
#include<fstream>
using namespace std;
bool ok=true;
string a;
string cnt;
int num;
int dp[200005];
struct node
{
     int next[26];
     int number;
     void init()
     {
          number=0;
          memset(next,0,sizeof(next));
     }
};
node tree[100010];
void insert(string a)
{
     int index=0;
     int len=a.size();
     for(int i=0;i<len;i++)
     {
          if(tree[index].next[a[i]-'A']==0)
          {
               tree[++num].init();
               tree[index].next[a[i]-'A']=num;
               index=num;
          }
          else
          {
               index=tree[index].next[a[i]-'A'];
          }
		  if(i == len - 1)
			  tree[index].number = 1;
     }
}

int main()
{
	ofstream fout ("prefix.out");
    ifstream fin ("prefix.in");
	tree[0].init();
	num=0;
	while(1)
	{
		fin>>a;
		if(a[0] == '.')
			break;
		insert(a);
	}
	string temp;
	while(fin>>temp)
	{
		cnt += temp;
	}
	int count;
	memset(dp , 0 , sizeof(dp));
	for(int i = cnt.size()- 1 ; i >= 0 ; i-- )
	{
		int index=0;
		count = 0;
		int Max = 0;
		for(int j = i; j < cnt.size() ; j++)
		{
			index=tree[index].next[cnt[j]-'A'];
			if(index == 0)
				break;
			if(tree[index].number == 1)
			{
				count++;
				if(Max < count + dp[j + 1])
					Max = count + dp[j + 1];					  
			}
			else
			{
				count++;
			}
		}
		dp[i] = Max;
	}
	fout<<dp[0]<<endl;
	return 0;
}
