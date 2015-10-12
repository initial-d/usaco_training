/*
ID: duyimin1
PROG: fence4
LANG: C++
*/
#include<iostream>
#include<set>
#include<math.h>
#include<vector>
#include<fstream>
#include<algorithm>
#include<stdio.h>
using namespace std;
ofstream fout ("fence4.out");
ifstream fin ("fence4.in");
int now,n,m,sum;
double expn = 1e-6;
struct p
{
    double x, y;
} point[201],ansb[201],anse[201],person;
bool cross(p a,p b,p c,p d)
{
    double x1,x2,x3,y1,y2,y3,t1,t2;
    if (min(a.x,b.x)>max(c.x,d.x)) return 0;
    if (min(c.x,d.x)>max(a.x,b.x)) return 0;
    if (min(a.y,b.y)>max(c.y,d.y)) return 0;
    if (min(c.y,d.y)>max(a.y,b.y)) return 0;
    x1=b.x-a.x;
    y1=b.y-a.y;
    x2=d.x-a.x;
    y2=d.y-a.y;
    x3=c.x-a.x;
    y3=c.y-a.y;

    t1=x1*y2-x2*y1;
    t2=x1*y3-x3*y1;
    if (t1*t2>0) return 0;

    x1=d.x-c.x;
    y1=d.y-c.y;
    x2=a.x-c.x;
    y2=a.y-c.y;
    x3=b.x-c.x;
    y3=b.y-c.y;

    t1=x1*y2-x2*y1;
    t2=x1*y3-x3*y1;
    if (t1*t2>0) return 0;

    return 1;
}
bool can(int t)
{
    int i;
    for (i=t+2; i<=n-1; i++)
        if (cross(point[t],point[t+1],point[i],point[i+1]))
        {
            return 0;
        }
    return 1;
}
bool same(p a,p b)
{
    if ((fabs(a.x-b.x)<=expn)&&(fabs(a.y-b.y)<=expn)) return 1;
    return 0;
}
bool check(p a,p b)
{
    int i;
    p mid;
    bool b1,b2,b3;
    for (i=1; i<=n; i++)
        if ((i!=now)&&(cross(person,a,point[i],point[i+1]))&&(cross(person,b,point[i],point[i+1])))
        {
            return 0;
        }
    b1=b2=b3=1;
    mid.x=(a.x+b.x)/2;
    mid.y=(a.y+b.y)/2;
    for (i=1; i<=n; i++)
        if (i!=now)
        {
            if (cross(person,a,point[i],point[i+1])) b1=0;
            if (cross(person,b,point[i],point[i+1])) b2=0;
            if (cross(person,mid,point[i],point[i+1])) b3=0;
        }
    if (b1||b2||b3) return 1;
    if (same(a,b)) return 0;
    if (check(a,mid)) return 1;
    if (check(mid,b)) return 1;
    return 0;
}
void solve()
{
    int i;
    sum=0;
    now=1;

    for (i=1; i<=n - 2; i++)
    {
        now=i;
        if (check(point[i],point[i+1]))
        {
            ansb[++sum]=point[i];
            anse[sum]=point[i+1];
        }
    }
    now=n;
    if (check(point[1],point[n]))
    {
        ansb[++sum]=point[1];
        anse[sum]=point[n];
    }
    now=n-1;
    if (check(point[n-1],point[n]))
    {
        ansb[++sum]=point[n-1];
        anse[sum]=point[n];
    }
    fout<<sum<<endl;
    for (i=1; i<=sum; i++)
        fout<<ansb[i].x<<" "<<ansb[i].y<<" "<<anse[i].x<<" "<<anse[i].y<<endl;
}
void readdata()
{
    int i;
    fin>>n;
    fin>>person.x>>person.y;
    for (i=1; i<=n; i++)
    {
        fin>>point[i].x>>point[i].y;
    }
    point[n+1]=point[1];
    for (i=1; i<=n-1; i++)
        if (!can(i))
        {
            fout<<"NOFENCE"<<endl;
            return;
        }
    solve();
}
int main(int argc, char *argv[])
{
    readdata();
    return 0;
}
