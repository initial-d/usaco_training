/*
ID: duyimin1
PROG: snail
LANG: C++
*/
#include<cstdio>
#include<cstring>
#include<cmath>
#include<fstream>
#include<iostream>
using namespace std;
ifstream fin ("snail.in");
ofstream fout ("snail.out");

char cnt[201][201];
bool vis[201][201];
char c;
int r , n , b;
int M = 0;
void dfs(int x , int y , int num , int dre)
{
    vis[x][y] = 1;
    if(num > M)
        M = num;
    if(dre == 0){
        if(x + 1 <= n && cnt[x + 1][y] != '#' && !vis[x + 1][y])
            dfs(x + 1 , y , num + 1 , 1);
        if(y + 1 <= n && cnt[x][y + 1] != '#' && !vis[x][y + 1])
            dfs(x , y + 1, num + 1 , 2);
    }
    else if(dre == 1)
    {
        if(x+1 <= n && vis[x+1][y])
        {
            vis[x][y] = 0;
            return;
        }
        if(x + 1 <= n && cnt[x + 1][y] != '#')
            dfs(x + 1 , y , num + 1 , 1);
        else{
            if(y + 1 <= n && cnt[x][y + 1] != '#' && !vis[x][y + 1])
                dfs(x , y + 1, num + 1 , 2);
      //      if(x - 1 >= 1 && cnt[x - 1][y] != '#' && !vis[x - 1][y])
      //          dfs(x - 1 , y , num + 1 , 3);
            if(y - 1 >= 1 && cnt[x][y - 1] != '#' && !vis[x][y - 1])
                dfs(x , y - 1, num + 1 , 4);
        }

    }
    else if(dre == 2)
    {
        if(y+1 <= n && vis[x][y+1])
        {
            vis[x][y] = 0;
            return;
        }
        if(y + 1 <= n && cnt[x][y+1] != '#')
            dfs(x , y+1 , num + 1 , 2);
        else{
            if(x + 1 <= n && cnt[x+1][y] != '#' && !vis[x+1][y])
                dfs(x+1 , y, num + 1 , 1);
            if(x - 1 >= 1 && cnt[x - 1][y] != '#' && !vis[x - 1][y])
                dfs(x - 1 , y , num + 1 , 3);
        //    if(y - 1 >= 1 && cnt[x][y - 1] != '#' && !vis[x][y - 1])
        //        dfs(x , y - 1, num + 1 , 4);
        }
    }
    else if(dre == 4)
    {
        if(y-1 >= 1 && vis[x][y-1])
        {
            vis[x][y] = 0;
            return;
        }
        if(y - 1 >= 1 && cnt[x][y-1] != '#')
            dfs(x , y-1 , num + 1 , 4);
        else{
            if(x + 1 <= n && cnt[x+1][y] != '#' && !vis[x+1][y])
                dfs(x+1 , y, num + 1 , 1);
            if(x - 1 >= 1 && cnt[x - 1][y] != '#' && !vis[x - 1][y])
                dfs(x - 1 , y , num + 1 , 3);
         //   if(y + 1 <= n && cnt[x][y + 1] != '#' && !vis[x][y + 1])
         //       dfs(x , y + 1, num + 1 , 2);
        }
    }
    else if(dre == 3)
    {
        if(x-1 >= 1 && vis[x-1][y])
        {
            vis[x][y] = 0;
            return;
        }
        if(x - 1 >= 1 && cnt[x - 1][y] != '#')
            dfs(x - 1 , y , num + 1 , 3);
        else{
            if(y + 1 <= n && cnt[x][y + 1] != '#' && !vis[x][y + 1])
                dfs(x , y + 1, num + 1 , 2);
      //      if(x + 1 <= n && cnt[x + 1][y] != '#' && !vis[x + 1][y])
      //          dfs(x + 1 , y , num + 1 , 1);
            if(y - 1 >= 1 && cnt[x][y - 1] != '#' && !vis[x][y - 1])
                dfs(x , y - 1, num + 1 , 4);
        }
    }
    vis[x][y] = 0;
}
int main()
{
    memset(cnt , '.' , sizeof(cnt));
    memset(vis , 0 , sizeof(vis));
    fin>>n>>b;
    for(int i = 0 ; i < b ; i++)
    {
        fin>>c>>r;
        cnt[r][c - 'A' + 1] = '#';
    }
    cnt[1][1] = 'S';
    dfs(1 , 1 , 1 , 0);
    fout<<M<<endl;
    return 0;
}
