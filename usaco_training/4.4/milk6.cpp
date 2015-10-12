/*
ID: duyimin1
PROG: milk6
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
#define MAX_V 2005
ofstream fout ("milk6.out");
ifstream fin ("milk6.in");

int N , M;
struct edge {long long to ,cap ,rev ,id;};
struct input {long long c , t , f , id;};
input iii[MAX_V];
vector<edge> G[MAX_V];
vector<edge> H[MAX_V];
bool used[MAX_V];
int level[MAX_V];
int iter[MAX_V];
long long ans[2001];
bool cmp(input a , input b)
{
    if(a.c == b.c)
        return a.id < b.id;
    return a.c > b.c;
}
void add_edge(long long from , long long to , long long cap ,long long id)
{
        G[from].push_back((edge){to , cap , G[to].size() ,id});
        G[to].push_back((edge){from , 0 , G[from].size() - 1 , id});
        H[from].push_back((edge){to , cap , H[to].size() , id});
        H[to].push_back((edge){from , 0 , H[from].size() - 1 ,id});
}
void bfs(int s)
{
    memset(level , -1 , sizeof(level));
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while(!que.empty())
    {
        int v = que.front();
        que.pop();
        for(int i = 0 ; i < (int)G[v].size() ; i++)
        {
            edge &e = G[v][i];
            if(e.cap > 0 && level[e.to] < 0)
            {
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
}
long long dfs(long long v , long long t , long long f)
{
    if(v == t)
        return f;
    for(int &i = iter[v] ; i < (int)G[v].size() ; i++)
    {
        edge &e = G[v][i];
        if(level[v] < level[e.to] && e.cap > 0)
        {
            long long d = dfs(e.to , t , min(f , e.cap));
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

long long max_flow(int s , int t)
{
    long long flow = 0;
    for(;;)
    {
        bfs(s);
        if(level[t] <0)
            return flow;
        memset(iter , 0 , sizeof(iter));
        long long f;
        while((f = dfs(s , t , INF)) > 0)
            flow += f;
    }
}

int main()
{
    fin>>N>>M;
    int f , t , c;
    for(int i = 0 ; i < M ; i++)
    {
        fin>>f>>t>>c;
        iii[i].f = f;
        iii[i].t = t;
        iii[i].c = c;
        iii[i].id = i;
        add_edge(f , t , c , i);
    }
    long long MM = max_flow(1 , N);
    fout<<MM<<" ";
    memset(ans , 0 , sizeof(ans));
    for(int i = 0 ; i < N * 2 ; i++)
        G[i] = H[i];
    sort(iii , iii + M , cmp);
    for(int k = 0 ; k < M; k++)
    {
        int i;
        for(i = 0 ; i < (int)G[iii[k].f].size() ;i++)
        {
 //           cout<<mm[iii[k].f]<<endl;
            if(G[iii[k].f][i].to == iii[k].t && G[iii[k].f][i].id == iii[k].id)
            {
                //cout<<"hi "<<iii[k].f<<" "<<i<<endl;
                G[iii[k].f][i].cap -= iii[k].c ;
                break;
            }
        }
        for(int i = 0 ; i < N * 2 ; i++)
                H[i] = G[i];
        long long now = max_flow(1 , N);
        for(int i = 0 ; i < N * 2 ; i++)
                G[i] = H[i];
        //cout<<now + iii[k].c<<" "<<MM<<endl;
        if(now + iii[k].c == MM)
        {
            MM -= iii[k].c;
            ans[0]++;
            ans[ans[0]] = iii[k].id + 1;
        }
        else
            G[iii[k].f][i].cap += iii[k].c;
    }
    sort(ans + 1 , ans + ans[0] + 1);
    fout<<ans[0]<<endl;
    for(long long i = 1 ; i <= ans[0] ; i++)
        fout<<ans[i]<<endl;
    return 0;
}
