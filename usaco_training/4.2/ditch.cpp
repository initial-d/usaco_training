/*
ID: duyimin1
PROG: ditch
LANG: C++
*/
//朴素的网络最大流，邻接表实现可以天然的解决重边问题
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
#define MAX_V 205
ofstream fout ("ditch.out");
ifstream fin ("ditch.in");

int N , M;
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
int main()
{
    fin>>N>>M;
    int f , t , c;
    for(int i = 0 ; i < N ; i++)
    {
        fin>>f>>t>>c;
        add_edge(f , t , c);
    }
    fout<<max_flow(1 , M)<<endl;
    return 0;
}
