/*
ID: duyimin1
PROG: rect1
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

ofstream fout ("rect1.out");
ifstream fin ("rect1.in");
int a , b , n;
struct rect
{
    int x1;
    int y1;
    int x2;
    int y2;
    int color;
};
rect cnt[1001];
int ans[2501];
void dfs(int x1 , int y1 , int x2 , int y2 , int color , int k)
{
    while((x2 <= cnt[k].x1 || x1 >= cnt[k].x2 || y2 <= cnt[k].y1 || y1 >= cnt[k].y2) && k <= n)
        k++;
    if(k > n)
    {
        ans[color] += (y2 - y1) * (x2 - x1);
        return;
    }
    if(x1 == x2 || y1 == y2)
        return;
    if(x1 < cnt[k].x1)
    {
        dfs(x1 , y1 , cnt[k].x1 , y2 , color , k + 1);
        x1 = cnt[k].x1;
    }
    if(x2 > cnt[k].x2)
    {
        dfs(cnt[k].x2 , y1 , x2 , y2 , color , k + 1);
        x2 = cnt[k].x2;
    }
    if(y1 < cnt[k].y1)
    {
        dfs(x1 , y1 , x2 , cnt[k].y1 , color , k + 1);
        y1 = cnt[k].y1;
    }
    if(y2 > cnt[k].y2)
    {
        dfs(x1 , cnt[k].y2 , x2 , y2 , color , k + 1);
        y2 = cnt[k].y2;
    }
}
int main()
{
    fin>>a>>b>>n;
    cnt[0].x1 = cnt[0].y1 = 0;
    cnt[0].x2 = a ;
    cnt[0].y2 = b;
    cnt[0].color = 1;
    for(int i = 1 ; i <= n ;i++)
    {
        fin>>cnt[i].x1>>cnt[i].y1>>cnt[i].x2>>cnt[i].y2>>cnt[i].color;
    }
    memset(ans , 0 , sizeof(ans));
    for(int i = 0 ; i <= n ; i++)
    {
        dfs(cnt[i].x1 , cnt[i].y1 , cnt[i].x2 , cnt[i].y2 , cnt[i].color , i + 1);
    }
    for(int i = 1 ; i <= 2500 ; i++)
    {
        if(ans[i])
            fout<<i<<" "<<ans[i]<<endl;
    }
    return 0;
}

