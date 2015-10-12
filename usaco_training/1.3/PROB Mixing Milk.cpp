/*
ID: duyimin1
PROG: crypt1
LANG: C++
*/
//暴力搜索，注意一定的剪枝条件：数字的位数，还有其他条件可以优化。
#include<iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int n;
int test[10];
bool search1[10];
int a,b,c,d,e;
int ans;
bool check(int m){
  while(m != 0){
	int tmp = m % 10;
	if(!search1[tmp]){
	  return false;
	}
	m = m / 10;
  }
  return true;
}
int main()
{
  ofstream fout ("crypt1.out");
  ifstream fin ("crypt1.in");
  fin>>n;
  for(int i = 0; i < n ;i++){
	fin>>test[i];
	search1[test[i]] = true;
  }
  ans = 0;
  for(int i = 0 ; i < n ; i++)
	 for(int j = 0 ; j < n ; j++)
	    for(int k = 0 ; k < n ; k++)
		   for(int l = 0 ; l < n ; l++)
			 for(int h = 0 ; h < n ; h++){
			   int tmp1, tmp2 ,tmp3;
			   tmp1 = test[i] * 100 + test[j] * 10 + test[k];
			   tmp2 = test[l] * 10 + test[h];
			   if(check(tmp1 * test[h]) && (tmp1 * test[h] <= 999)){
				 if(check(tmp1 * test[l]) && (tmp1 * test[l] <= 999)){
				   tmp3 = tmp2 * tmp1;
				   if(check(tmp3) && (tmp3 <= 9999) ){
					 ans++;
					 //	 cout<<tmp3<<endl;
				   }
				 }
			   }
			 }			  
  fout<<ans<<endl;
  return 0;
}