/*
ID: duyimin1
PROG: camelot
LANG: C++
*/
#include<iostream>
#include<queue>
#include<fstream>
using namespace std;
#define MAXR 32
#define MAXC 27
ofstream fout ("camelot.out");
ifstream fin ("camelot.in");
int kstep[MAXR][MAXC][MAXR][MAXC];
bool vis[MAXR][MAXC];
int path[8][2] = {{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2}};
struct point
{
    int r;
    int c;
};
point king , knight[MAXR * MAXC];
int R,C,cnt;
int ans = 1<<30;
void init()
{
    for(int i=1; i<=R; i++)
        for(int j=1; j<=C; j++)
            for(int i1=1; i1<=R; i1++)
                for(int j1=1; j1<=C; j1++)
                    kstep[i][j][i1][j1]=1<<25;
}
void restore()
{
    for(int i=1; i<=R; i++)
        for(int j=1; j<=C; j++)
            vis[i][j]=false;
}
int KingWay(int r1 , int c1)
{
    int row = king.r - r1;
    if(row<0)row =- row;
    int column = king.c - c1;
    if(column<0)column=-column;
    return row > column ? row : column;
}
void BFS()
{
    int cR,cC;
    point tt , tt1 , tt2;
    init();
    for(int r1=1; r1<=R; r1++)
        for(int c1=1; c1<=C; c1++)
        {
            queue<point> que;
            restore();
            tt.c = c1;
            tt.r = r1;
            que.push(tt);
            vis[r1][c1]=true;
            kstep[r1][c1][r1][c1]=0;
            while(!que.empty())
            {
                tt1 = que.front();
                que.pop();
                for(int k=0; k<8; k++)
                {
                    cR=tt1.r + path[k][0];
                    cC=tt1.c + path[k][1];
                    if(cR>0&&cR<=R&&cC>0&&cC<=C&&
                            !vis[cR][cC])
                    {
                        tt2.c = cC;
                        tt2.r = cR;
                        que.push(tt2);
                        kstep[r1][c1][cR][cC]=kstep[r1][c1][tt1.r][tt1.c] + 1;
                        vis[cR][cC]=true;
                    }
                }
            }
        }
}
void input()
{
    char str;
    int input;
    fin>>R>>C;
    fin>>str>>input;
    king.r = input;
    king.c = str-'A'+1;
    while(fin>>str)
    {
        fin>>input;
        knight[cnt].r = input;
        knight[cnt++].c = str-'A'+1;
    }
}
void solve()
{
    int total,diff,kr,kc,tmp;
    bool cut;
    BFS();
    for(int i=1; i<=R; i++)
        for(int j=1; j<=C; j++)
        {
            total=0;
            cut=false;
            for(int k=0; k<cnt; k++)
                if(kstep[knight[k].r][knight[k].c][i][j]>=(1<<25))
                {
                    cut=true;
                    break;
                }
                else total+=kstep[knight[k].r][knight[k].c][i][j];
            if(cut||total>ans)continue;
            diff=KingWay(i,j);
            for(int r=-2; r<=2; r++)
                for(int c=-2; c<=2; c++)
                {
                    kr=king.r+r;
                    kc=king.c+c;
                    if(kr>0&&kr<=R&&kc>0&&kc<=C)
                        for(int k=0; k<cnt; k++)
                        {
                            tmp=kstep[knight[k].r][knight[k].c][kr][kc]+
                                kstep[kr][kc][i][j]+KingWay(kr,kc)-
                                kstep[knight[k].r][knight[k].c][i][j];
                            if(diff>tmp)
                                diff=tmp;
                        }
                }
            total+=diff;
            if(ans>total)
                ans=total;
        }
    fout<<ans<<endl;
}
int main()
{
    input();
    solve();
    return 0;
}
