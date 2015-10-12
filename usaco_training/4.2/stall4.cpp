/*
ID: duyimin1
PROG: stall4
LANG: C++
*/
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <ctime>
using namespace std;
typedef long long ll;
#define clr(x,a) memset(x,a,sizeof(x))
#define sz(x) (int)x.size()
#define see(x) cerr<<#x<<" "<<x<<endl
#define se(x) cerr<<" "<<x
#define pb push_back
#define mp make_pair
#define INF 1<<30
#define MAX_V 410
ofstream fout ("stall4.out");
ifstream fin ("stall4.in");

int N , K;
bool can[MAX_V][MAX_V];
struct edge {int to ,cap ,rev ;};

vector<edge> G[MAX_V];
bool used[MAX_V];
void add_edge(int from , int to , int cap)
{
    G[from].push_back((edge){to , cap , G[to].size()});
    G[to].push_back((edge){from , 0 , G[from].size() - 1});
}

int dfs(int v , int t , int f)
{
    if(v == t)
        return f;
    used[v] = true;
    for(int i = 0 ; i < G[v].size() ; i++)
    {
        edge &e = G[v][i];
        if(!used[e.to] && e.cap > 0)
        {
            int d = dfs(e.to , t , min(f , e.cap));
            if(d > 0)
            {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s , int t)
{
    int flow = 0;
    for(;;)
    {
        memset(used , 0 , sizeof(used));
        int f = dfs(s , t ,INF);
        if(f == 0)
            return flow;
        flow += f;
    }
}
void solve()
{
    int s = N + K;
    int t = s + 1;
    for(int i = 0 ; i < N ; i++)
        add_edge(s , i , 1);
    for(int i = 0 ; i < K ; i++)
        add_edge(N + i , t  , 1);
    for(int i = 0 ; i < N ; i++)
    {
        for(int j = 0 ; j < K ; j++)
        {
            if(can[i][j])
                add_edge(i , N + j , 1);
        }
    }
    fout<<max_flow(s , t)<<endl;
}
int main()
{
    fin>>N>>K;
    int temp , tt;
    memset(can , false , sizeof(can));
    for(int i = 0 ; i < N ; i++)
    {
        fin>>temp;
        for(int j = 0 ; j < temp ; j++)
        {
            fin>>tt;
            can[i][tt - 1] = true;
        }
    }
    solve();
    return 0;
}
