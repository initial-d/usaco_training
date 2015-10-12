/*
ID: duyimin1
PROG: fc
LANG: C++
*/
#include<iostream>
#include<stdio.h>
#include<fstream>
#include<string>
#include<string.h>
#include<iomanip>
#include<math.h>
#include<algorithm>
#define PI acos(double(-1))
#define INF  999999999

using namespace std;
ofstream fout ("fc.out");
ifstream fin ("fc.in");
#define maxn 10005

struct point
{
    double x, y;
} pnt[maxn], res[maxn];

int n, l ,top;

bool mult(point sp, point ep, point op)
{
    return (sp.x - op.x) * (ep.y - op.y) >= (ep.x - op.x) * (sp.y - op.y);
}

bool operator<(const point &l, const point &r)
{
    return l.y < r.y || (l.y == r.y && l.x < r.x);
}

void graham()
{
    int i, len;
    top =1;
    sort(pnt, pnt + n);
    if (n ==0)
        return;
    res[0] = pnt[0];
    if (n ==1)
        return;
    res[1] = pnt[1];
    if (n ==2)
        return;
    res[2] = pnt[2];
    for (i =2; i < n; i++)
    {
        while (top && mult(pnt[i], res[top], res[top -1]))
            top--;
        res[++top] = pnt[i];
    }
    len = top;
    res[++top] = pnt[n -2];
    for (i = n -3; i >=0; i--)
    {
        while (top != len && mult(pnt[i], res[top], res[top -1]))
            top--;
        res[++top] = pnt[i];
    }
}

double dis(point &p, point &q)
{
    double x1 = p.x - q.x, y1 = p.y - q.y;
    return sqrt(x1 * x1 + y1 * y1);
}
int main()
{
    double sum=0.0;
    fin>>n;
    for(int u=0; u<n; u++)
    {
        fin>>pnt[u].x>>pnt[u].y;
    }
    graham();
    for(int u=0; u<top; u++)
    {
        sum+=dis(res[u+1],res[u]);
    }
    sum+=dis(res[top],res[0]);
    fout<<showpoint<<fixed<<setprecision(2)<<sum<<endl;
    return 0;
}
