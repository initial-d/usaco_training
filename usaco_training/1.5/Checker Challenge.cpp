/*
ID: duyimin1
PROG: checker
LANG: C++
*/
//回溯法求前三种解的情况；
//位操作法求总的步数。详解见matrix67.
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;
ofstream fout ("checker.out");
ifstream fin ("checker.in");
int a[20]={0};
int num = 0;
int sum = 0;
int upperlim ;
bool flag = true;
bool fit(int i)
{
    for(int k=i-1;k>=1;k--)
    {
        if(a[k]==a[i]||abs(a[i]-a[k])==i-k)
            return false;
    }
    return true;
}
void queen(int i,int n)
{
  if(i>n)
    {
	   num++;
	   if(num <= 3){
		 fout<<a[1];
		 for(int j=2;j<=n;j++)
		   {
			 fout<<" "<<a[j];
		   }
		 fout<<endl;
	   }
	   else 
		 flag = false;
    }
    else
    {
	  for(int j=1;j<=n;j++)
        {
		  a[i]=j;
		  if(flag && fit(i))
			queen(i+1,n);
		  a[i]=0;
        }
    }
}
void test(int row , int ld , int rd){
  int pos , p;
  if(row != upperlim){
	pos = upperlim & ~(row | ld | rd);
	while(pos){
	  p = pos & -pos;
	  pos -= p;
	  test(row + p , (ld + p)<<1 , (rd + p)>>1);
	}
  }
  else
	sum++;
}
int main()
{
  int n ;
  fin>>n;
  queen(1,n);
  upperlim = (1 << n) - 1;
  test(0 , 0 , 0);
  fout<<sum<<endl;
  return 0;
}

