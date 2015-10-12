/*
ID: duyimin1
PROG: contact
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
typedef pair<string, int> PAIR;
ofstream fout ("contact.out");
ifstream fin ("contact.in");
int a , b, n;
string str;
vector<string> vec;
map<string , int> mm;
string ss;
bool cmp(PAIR a , PAIR b)
{
    if(a.second == b.second)
    {
        if(a.first.size() == b.first.size())
            return a.first < b.first;
        return a.first.size() < b.first.size();
    }
    return a.second > b.second;
}
void input()
{
	fin>>a>>b>>n;
	string ttt;
	while(getline(fin , ttt))
        str += ttt;
	string temp;
	for(int i = a ; i <= b ; i++)
	{
		for(int k = 0 ; k < pow(2 , i) ;k++)
		{
			temp.clear();
			for(int j = 0 ; j < i ; j++)
				temp += '0';
			int t = k;
			for(int j = 0 ; j < i ; j++)
			{
				if((k>>j) & 1)
					temp[i - 1 - j] = '1';
			}
			vec.push_back(temp);
		}
	}
}
int num;
struct node
{
     int next[2];
     int number;
     void init()
     {
          number = -2;
          next[0] = next[1] = -2;
     }
};
node tree[100010];
void insert(string a)
{
     int index = 0;
     int len = a.size();
     for(int i = 0;i < len ; i++)
     {
          if(tree[index].next[a[i]-'0'] == -2)
          {
			  tree[++num].init();
			  tree[index].next[a[i]-'0'] = num;
			  index = num;
          }
          else
          {
               index = tree[index].next[a[i]-'0'];
          }
		  if(i == len - 1)
			  tree[index].number = 0;
     }
}
void dfs(int index)
{
	if(index != -2)
    {
        if(tree[index].number > 0 && tree[index].next[0] != -2 && tree[index].next[1] != -2)
            mm[ss] = tree[index].number;
        if(tree[index].next[0] != -2)
        {
            string temp = ss;
            ss += '0';
            dfs(tree[index].next[0]);
            ss = temp;
        }
        else if(tree[index].number)
            mm[ss] = tree[index].number;
        if(tree[index].next[1] != -2)
        {
            string temp = ss;
            ss += '1';
            dfs(tree[index].next[1]);
            ss = temp;
        }
        else if(tree[index].number)
            mm[ss] = tree[index].number;
    }

}

int main()
{
	input();
	tree[0].init();
	num = 0;
	for(int i = 0 ; i < vec.size() ; i++)
	{
		insert(vec[i]);
	}
	for(int i = 0 ; i < str.size() ;i++)
	{
		int j = i;
		int index = 0;
	    while(index != -2)
		{
	    	if(tree[index].number >= 0)
				tree[index].number++;
            if(str[j] == ' ')
                j++;
            if(j > str.size())
                break;
			index = tree[index].next[str[j]-'0'];
			j++;
			if(j > str.size()) //当j = str.size()时所找到的index无效，退出
                break;
		}
	}
	ss.clear();
	dfs(0);
	vector<PAIR> vec1;
    for(map<string , int>::iterator it = mm.begin(); it != mm.end(); it++)
    {
        if(it->second)
            vec1.push_back(make_pair(it->first, it->second));
    }
    sort(vec1.begin() , vec1.end() , cmp);
    int t = 1;
    int coun = 0;
    bool flag = false;
    fout<<vec1[0].second<<endl;
    fout<<vec1[0].first;
    coun++;
    if(vec1.size() == 1)
    {
        fout<<endl;
        return 0;
    }
    int i;
    for(i = 1 ; i < vec1.size();i++)
    {
        if(vec1[i].second != vec1[i - 1].second)
        {
            flag = false;
            fout<<endl;
            coun = 0;
            t++;
            if(t == n + 1)
                break;
            fout<<vec1[i].second<<endl;
            fout<<vec1[i].first;
            coun++;
        }
        else
        {
            if(flag)
            {
                fout<<endl;
                flag = false;
                fout<<vec1[i].first;
            }
            else
                fout<<" "<<vec1[i].first;
            coun++;
            if(coun == 6)
            {
                coun = 0;
                flag = true;
            }
        }
    }
    if(i == vec1.size())
        fout<<endl;
	return 0;
}
