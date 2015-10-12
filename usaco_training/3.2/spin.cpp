/*
ID: duyimin1
PROG: spin
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
#include<sstream>
#include<iomanip>
using namespace std;

ofstream fout ("spin.out");
ifstream fin ("spin.in");
struct wheel
{
    int v;
    int w;
    int start[6];
    int ext[6];
    int num;
};
wheel cnt[5];
bool vis[361];
vector<int> vec;
int ans;
bool flag = false;
int main()
{
    for(int i = 0; i < 5 ; i++)
    {
        fin>>cnt[i].v>>cnt[i].num;
        for(int j = 0 ; j < cnt[i].num ; j++)
            fin>>cnt[i].start[j]>>cnt[i].ext[j];
    }
    for(int t = 0 ; t < 360 ; t++)
    {
        if(flag)
            break;
        memset(vis , false , sizeof(vis));
        for(int i = 0 ; i < 5 ; i++)
        {
            vec.clear();
            for(int k = 0 ; k < cnt[i].num ; k++)
            {
                int temp = cnt[i].start[k];
                temp += cnt[i].v * t;
                for(int m = 0; m <= cnt[i].ext[k]; m++)
                {
                    if(i == 0)
                        vis[(temp + m) % 360] = true;
                    else
                    {
                        if(vis[(temp + m) % 360] == true)
                            vec.push_back((temp + m) % 360);
                    }
                }
            }
            if(i != 0)
            {
                memset(vis , false , sizeof(vis));
                for(int k = 0 ; k < vec.size() ; k++)
                {
                    vis[vec[k]] = true;
                }
            }
        }
        for(int i = 0 ; i <= 360 ; i++)
        {
            if(vis[i])
            {
                ans = t;
                flag = true;
                break;
            }
        }
    }
    if(!flag)
        fout<<"none"<<endl;
    else
        fout<<ans<<endl;
    return 0;
}
