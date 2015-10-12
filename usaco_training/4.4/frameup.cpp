/*
ID: duyimin1
PROG: frameup
LANG: C++
*/
//Õÿ∆À≈≈–Ú
#include<iostream>
#include <vector>
#include <string.h>
#include <fstream>
#include <map>
using namespace std;
ofstream fout ("frameup.out");
ifstream fin ("frameup.in");

int h , w;
char cnt[35][35];
int way[30][30];
int temp[30][30];
int ans[30];
bool vis[30];
int posion[30];
struct pos
{
    int u , d , l , r;
};
pos tt[30];
int t1 = 0;
void topsort(int pos)
{
    if(pos == t1)
    {
        for(int i = 0 ; i < t1 ;i++)
            fout<<char(ans[i] + 'A');
        fout<<endl;
    }
    for(int i = 0 ; i < 26 ; i++)
    {
        if(!vis[i] && posion[i])
        {
            bool flag = false;
            for(int j = 0 ; j < 26 ; j++)
            {
                if(temp[j][i])
                {
                    flag = true ;
                    break;
                }
            }
            if(!flag)
            {
                ans[pos] = i;
                vis[i] = true;
                for(int k = 0 ; k < 26 ; k++)
                    temp[i][k] = 0;
                topsort(pos + 1);
                vis[i] = false;
                for(int k = 0 ; k < 26 ; k++)
                    temp[i][k] = way[i][k];
            }
        }
    }
}
int main()
{
    fin>>h>>w;
    for(int i = 0 ; i < 26 ; i++)
        tt[i].u = tt[i].l = tt[i].d = tt[i].r = -1;
    memset(posion , 0 , sizeof(posion));
    for(int i = 0 ; i < h ; i++)
    {
        for(int j = 0 ; j < w ; j++)
        {
            fin>>cnt[i][j];
            if(cnt[i][j] != '.')
            {
                posion[cnt[i][j] - 'A'] = 1;
                if(tt[cnt[i][j] - 'A'].u == -1)
                    tt[cnt[i][j] - 'A'].u = i;
                else if(tt[cnt[i][j] - 'A'].u > i)
                    tt[cnt[i][j] - 'A'].u = i;
                if(tt[cnt[i][j] - 'A'].d < i)
                    tt[cnt[i][j] - 'A'].d = i;
                if(tt[cnt[i][j] - 'A'].l == -1)
                    tt[cnt[i][j] - 'A'].l = j;
                else if(tt[cnt[i][j] - 'A'].l > j)
                    tt[cnt[i][j] - 'A'].l = j;
                if(tt[cnt[i][j] - 'A'].r < j)
                    tt[cnt[i][j] - 'A'].r = j;
            }
        }
    }
    //for(int i = 0 ; i < 26 ;i++)
    //    cout<<tt[i].u<<" "<<tt[i].d<<" "<<tt[i].l<<" "<<tt[i].r<<endl;
    memset(way , 0 , sizeof(way));
    for(int t = 0 ; t < 26 ; t++)
    {
        if(tt[t].u == -1)
            continue;
        for(int i = tt[t].u ; i <= tt[t].d ; i++)
        {

            if(i == tt[t].u || i == tt[t].d)
            {
                for(int j = tt[t].l ; j <= tt[t].r ; j++)
                {
                    if(cnt[i][j] != 'A' + t)
                        way[t][cnt[i][j] - 'A'] = 1;
                }
            }
        }
        int j = tt[t].l;
        for(int i = tt[t].u ; i <= tt[t].d ; i++)
        {
            if(cnt[i][j] != 'A' + t)
                way[t][cnt[i][j] - 'A'] = 1;
        }
        j = tt[t].r;
        for(int i = tt[t].u ; i <= tt[t].d ; i++)
        {
            if(cnt[i][j] != 'A' + t)
                way[t][cnt[i][j] - 'A'] = 1;
        }
    }
    /*for(int i = 0 ; i < 26;i++)
    {
        for(int j = 0 ; j < 26 ;j++)
            cout<<way[i][j]<<" ";
        cout<<endl;
    }*/
    for(int i = 0 ; i < 26 ; i++)
        if(posion[i])
            t1++;
    memcpy(temp , way , sizeof(way));
    memset(vis , false ,sizeof(vis));
    topsort(0);
    return 0;
}
