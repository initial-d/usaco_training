/*
ID: duyimin1
PROG: kimbits
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

ofstream fout ("kimbits.out");
ifstream fin ("kimbits.in");

int ans[33][33];
unsigned int n , l , i;
int dfs(int n , int l)
{
    if(n == 0 || l == 0)
        return 1;
    if(ans[n][l])
        return ans[n][l];
    ans[n][l] = dfs(n - 1 , l) + dfs(n - 1 , l - 1);
    return ans[n][l];
}
int main()
{
    fin>>n>>l>>i;
    i--;
    for(int j = n ; j >= 1 ;j--)
    {
        if(i && dfs(j - 1 , l) <= i)
        {
            fout<<1;
            i -= dfs(j - 1 , l);
            l--;
        }
        else{
            fout<<0;
        }
    }
    fout<<endl;
    return 0;
}
