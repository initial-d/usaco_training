/*
ID: duyimin1
PROG: range
LANG: C++
*/
#include<iostream>
#include<map>
#include<string>
#include<fstream>
#include<algorithm>
#include<string.h>
using namespace std;
ofstream fout ("range.out");
ifstream fin ("range.in");
int cnt[251][251];
int f[251][251];
string str;
int n , M;
int ans[251];
int main()
{
    fin>>n;
    memset(ans , 0 ,sizeof(ans));
    memset(f , 0 , sizeof(f));
    for(int i = 1 ; i <= n; i++)
    {
        fin>>str;
        int len = str.size();
        for(int j = 1 ; j <= len ; j++)
        {
            if(str[j - 1] == '0')
                cnt[i][j] = 0;
            else if(str[j - 1] == '1')
                cnt[i][j] = 1;
        }
    }
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1; j <= n ; j++)
        {
            if(cnt[i][j] == 1)
                f[i][j] = min(f[i - 1][j] , min(f[i][j - 1] , f[i-1][j-1])) + 1;
        }
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1; j <= n ; j++)
            for(int k = 2 ; k <= f[i][j] ; k++)
                ans[k]++;
    for(int i = 1 ; i <= n ; i++)
        if(ans[i] != 0)
            fout<<i<<" "<<ans[i]<<endl;
    return 0;
}
