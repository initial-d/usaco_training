/*
ID: duyimin1
PROG: numtri
LANG: C++
*/

#include<iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <math.h>
#include<string.h>
#include<algorithm>
#include<bitset>

using namespace std;

int r;
int foo[1001][1001];
int ans[1001][1001];
int main()
{
  ofstream fout ("numtri.out");
  ifstream fin ("numtri.in");
  fin>>r;
  for(int i = 0; i < r; i++)
	for(int j = 0; j < i + 1 ; j++){
	  fin>>foo[i][j];
	}
  for(int i = r - 1 ; i >= 0 ; i-- )
	for(int j = 0; j < i + 1 ; j++){
	  if(i == (r - 1)){
		ans[i][j] = foo[i][j];
	  }
	  else{
		ans[i][j] = max(ans[i + 1][j] , ans[i + 1][j + 1]) + foo[i][j];
	   }
	}
  fout<<ans[0][0]<<endl;
  return 0;
}