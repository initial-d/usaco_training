/*
ID: duyimin1
PROG: starry
LANG: C++
*/
#include<cstdio>
#include<cstring>
#include<cmath>
#include<fstream>
#include<iostream>
using namespace std;
#define ok(a,b) (0<=(a) && (a)<h && 0<=(b) && (b)<w)
#define pf(a) ((a)*(a))
#define abs(a) ((a)>0?(a):-(a))
ifstream fin ("starry.in");
ofstream fout ("starry.out");
const int MAXn=100+9;
const double EPS=1e-2;
const int walk[8][2]= {{1,1},{1,0},{1,-1},{0,1},{0,-1},{-1,1},{-1,0},{-1,-1}};
char c[MAXn][MAXn];
int w,h,tot=-1,np;
double hash[26];
struct node
{
    int x,y;
} p[MAXn*MAXn];
bool mark[MAXn][MAXn];
double fill(int x,int y)
{
    memset(mark,0,sizeof(mark));
    mark[x][y]=1;
    p[np=1]=(node)
    {
        x,y
    };
    int i,j;
    double ans=0.0;
    for(i=1; i<=np; ++i)
        for(j=0; j<8; ++j)
        {
            node t=p[i];
            t.x+=walk[j][0],t.y+=walk[j][1];
            if(c[t.x][t.y]=='1' && !mark[t.x][t.y] && ok(t.x,t.y))
                p[++np]=t,mark[t.x][t.y]=1;
        }
    for(i=1; i<np; ++i)
        for(j=i+1; j<=np; ++j)
            ans+=sqrt(pf(p[i].x-p[j].x)+pf(p[i].y-p[j].y));
    return ans;
}
int main()
{
    int i,j,k,t,l;
    double nowhash;
    fin>>w>>h;
    for(i=0; i<h; ++i)
        fin>>c[i];
    for(i=0; i<h; ++i)
        for(j=0; j<w; ++j)
            if(c[i][j]=='1')
            {
                bool flag = false;
                nowhash=fill(i,j);
                for(k=0; k<=tot; ++k)
                    if(abs(nowhash-hash[k])<EPS)
                    {
                        flag = true;
                        t=k;
                        for(l=1; l<=np; ++l)
                            c[p[l].x][p[l].y]=t+'a';
                    }
                if(!flag){
                hash[++tot]=nowhash;
                for(k=1; k<=np; ++k)
                    c[p[k].x][p[k].y]=tot+'a';
                }
            }
    for(i=0; i<h; ++i)
    {
        for(j=0; j<w; ++j)
            fout<<c[i][j];
        fout<<endl;
    }
    return 0;
}
