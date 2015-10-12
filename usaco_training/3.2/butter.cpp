/*
ID: duyimin1
PROG: butter
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
#include<set>
#include<sstream>
#include<iomanip>
using namespace std;

ofstream fout ("butter.out");
ifstream fin ("butter.in");
#define INF 1000000050
int niu[501];

bool vis[801];
struct no
{
     int u,v,nxt;
}node[10005];
int edge[10005];
int inq[10005];
int n,p,q;
long long sum,dis[10005];
int a,b,d,c;
void init()
{
     for(int i=1;i<=2*c;i++)
     {
          edge[i]=0;
     }
}
void spfa(no node[] ,int edge[] , int sou)
{
     int i;
     for(int j=1;j<=p;j++)
          inq[j]=false;
     queue<int> que;
     que.push(sou);
     inq[sou] = true;
     for (i=1; i<=p; i++)
     {
          dis[i] = INF;
     }
     dis[sou] = 0;
     while (!que.empty())
     {
          int s = que.front();
          que.pop();
          inq[s] = false;
          int p=edge[s];
          while( p!=0)
          {
               int v=node[p].v;
               int u=node[p].u;
               if (dis[v] > dis[s] + u)
               {
                    dis[v] = dis[s] + u;
                    if (!inq[v])
                    {
                         que.push(v);
                         inq[v] = true;
                    }
               }
               p=node[p].nxt;
          }
     }
}
int main()
{
    fin>>n>>p>>c;
    init();
    for(int i = 0 ; i < n ;i++)
        fin>>niu[i];
    for(int i=1; i <= 2 * c;)
    {
        fin>>a>>b>>d;
        node[i].v=b;
        node[i].u=d;
        node[i].nxt=edge[a];
        edge[a]=i++;

        node[i].v=a;
        node[i].u=d;
        node[i].nxt=edge[b];
        edge[b]=i++;
    }
    int Min = INF;
    for(int i = 1; i <= p; i ++)
    {
        sum = 0;
        spfa(node , edge , i);
        for(int j = 0 ; j < n ; j++)
        {
            sum += dis[niu[j]];
        }
        if(Min > sum)
            Min = sum;
    }
    fout<<Min<<endl;
    return 0;
}

