/*
ID: duyimin1
PROG: runround
LANG: C++
*/

#include<iostream>
#include<algorithm>
#include<fstream>
#include<map>
#include<vector>
using namespace std;

long long number;
vector<int> vec;
map<int ,int> Count;
map<int ,int> filter;
long long find()
{
	while(true)
	{
		long long temp = number + 1;
		vec.clear();
		Count.clear();
		filter.clear();
		while(temp)
		{
			vec.insert(vec.begin() , temp % 10);
			filter[temp % 10]++;
			temp /= 10;
		}
		temp = number + 1;
		bool fflag = true;
		for(map<int ,int>::iterator it = filter.begin() ; it != filter.end() ; it++)
			if(it->second > 1)
			{
				number++;
				fflag = false;
				break;
			}
		if(!fflag)
			continue;
		int t = 0;
		while(true)
		{
			t = (vec[t] + t) % vec.size();
			Count[vec[t]]++;
			bool flag = false; 
			bool flag1 = false;
			for(map<int ,int>::iterator it = Count.begin() ; it != Count.end() ; it++)
				{
					if(it->second >= 2)
					{
						flag1 = true;
						break;
					}
				}
			if(flag1)
			{
				number++;
				break;
			}
			if(t == 0)
			{
				for(int i = 0 ; i < vec.size() ;i++)
				{
					if(Count[vec[i]] != 1)
					{			 
						flag = true;
						break;
					}
				}
				if(!flag)
					return temp;
				else
				{
					number++;
					break;
				}
			}
		}
	}
}	
int main()
{
	ofstream fout ("runround.out");
	ifstream fin ("runround.in");
	fin>>number;
	fout<<find()<<endl;
 	return 0;
}
