/*
ID: duyimin1
PROG: sprime
LANG: C++
*/
//这个代码有点又臭又长，重复代码太多，sicp白看了吗?
//注意最高位必为2 3 5 7，其他位必为1 3 7 9，然后枚举即可，这里重复用的队列进行枚举。
#include<iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <math.h>
#include<string.h>
#include<algorithm>
#include<bitset>
#include<queue>
using namespace std;
int n;
int k;
queue <int> q;
bool isp(int x)
{
	if((x%5==0&&x!=5)||x%3==0)
		return false;
	if(x%11==0&&x!=11)
		return false;
	if(x%2==0)
		return false;
	int m=sqrt(x);
	for(int i=2;i<=m;i++)
		if(x%i==0)
			return false;
	return true;
}
void func(int num)
{
  while(num--){
	if(isp(q.front() * 10 + 1))	{
	  q.push(q.front() * 10 + 1);
	  k++;
	}
	if(isp(q.front() * 10 + 3))	{
	  q.push(q.front() * 10 + 3);
	  k++;
	}
	if(isp(q.front() * 10 + 7))	{
	  q.push(q.front() * 10 + 7);
	  k++;
	}
	if(isp(q.front() * 10 + 9))	{
	  q.push(q.front() * 10 + 9);
	  k++;
	}
	q.pop();
  }
}
void findsp(int n){
  k = 0;
  func(4);
  if(n == 2)
	return ;
  int h = k;
  k = 0;
  func(h);
  if(n == 3)
	return ;
  h = k;
  k = 0;
  func(h);
  if(n == 4)
	return ;
  h = k;
  k = 0;
  func(h);
  if(n == 5)
	return ;
  h = k;
  k = 0;
  func(h);
  if(n == 6)
	return ;
  h = k;
  k = 0;
  func(h);
  if(n == 7)
	return ;
  h = k;
  k = 0;
  func(h);
  if(n == 8)
	return ;
}
int main(){
  ofstream fout ("sprime.out");
  ifstream fin ("sprime.in");
  fin>>n;
  if(n == 1){
	fout<<2<<endl;
	fout<<3<<endl;
	fout<<5<<endl;
	fout<<7<<endl; 
  }
  else{
	q.push(2);
	q.push(3);
	q.push(5);
	q.push(7);
	findsp(n);
  }
  while(!q.empty()){
	fout<<q.front()<<endl;
	q.pop();
  }
  return 0;
}
