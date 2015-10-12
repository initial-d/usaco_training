/*
ID: duyimin1
PROG: preface
LANG: C++
*/

#include<iostream>
#include<algorithm>
#include<fstream>
#include<vector>
#include<map>
using namespace std;
typedef pair<char, int> PAIR; 
int n;
string thousand[4] = {"", "M" , "MM" ,"MMM"};
string hundred[10] = {"","C" , "CC" , "CCC" ,"CD" , "D" , "DC","DCC", "DCCC" , "CM"};
string decade[10] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
string unit[10] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
string preface(int i)
{
	string str;
	if(i / 1000 != 0)
	{
		str += thousand[i / 1000];
		i %= 1000;
	}
	if(i / 100 != 0)
	{
		str += hundred[i / 100];
		i %= 100;
	}
	if(i / 10 != 0)
	{
		str += decade[i / 10];
		i %= 10;
	}
	if(i / 1 != 0)
		str += unit[i / 1];
	return str;
}
map<char , int> ans;
void cal(string str)
{
	for(int i = 0 ; i < str.size(); i++)
		ans[str[i]]++;
}
int cmp(const PAIR& x, const PAIR& y)
{
	return x.second > y.second; 
}
int main()
{
	ofstream fout ("preface.out");
	ifstream fin ("preface.in");
	fin>>n;
	char cnt[8] = "IVXLCDM";
	for(int i = 1 ; i <= n ; i++)
		cal(preface(i));
	for(int i = 0 ; i < 7 ; i++)
	{
		if(ans[cnt[i]])
			fout<<cnt[i]<<" "<<ans[cnt[i]]<<endl;
	}
 	return 0;
}
