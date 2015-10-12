/*
ID: duyimin1
PROG: ariprog
LANG: C++
*/
//先打表，然后暴力枚举，加一个关键性的剪枝，见如下标记。
#include<iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <math.h>
#include<string.h>
#include<algorithm>
#include<bitset>

using namespace std;
struct q
{
  int a;
  int b;
}ans[100000];
bool cmp(q x , q y)
{
  if(x.b == y.b)
	return x.a < y.a;
  else
	return x.b < y.b;
}
int t = 0;
int M , N;
int main()
{
   ofstream fout ("ariprog.out");
   ifstream fin ("ariprog.in");
   fin>>N;
   fin>>M;
   bool test[M * M * 2 + 200000] ;
   memset(test , false , sizeof(test));
   for(int i =0 ;i <= M ;i++){
	 for(int j = 0; j <= M ;j++){
	   test[i * i + j * j] = true;
	 }
   }
   for(int i = 0; i <= M * M * 2;i++){
	 if(test[i])
	   for(int j = i + 1; j <= M * M * 2 ; j++){
		 if(test[j]){
		   int cha = j - i;
		   int k = N - 2;
		   if((k * cha + j) > M * M * 2)//剪枝操作。！！！！@@
			 break;
		   int l;
		   for(l = 1; l <= k; l++){
			 if(!test[j + cha * l] || ((j + cha * k) > M * M * 2))
			   break;
		   }
		   if(l <= k || ((j + cha * k) > M * M * 2))
			 continue;
		   else{
			 ans[t].a = i ;
			 ans[t++].b = cha;
		   }
		 }
	   }
   }
   sort(ans , ans + t , cmp);
   if(t == 0)
	 fout<<"NONE"<<endl;
   else
	 for(int i = 0;i < t; i++ ){
	   fout<<ans[i].a<<" "<<ans[i].b<<endl;
	 }
   return 0;
} 
