/*
ID: duyimin1
PROG: barn1
LANG: C++
*/
//贪心，注意输入数据的无序性，注意细节（m=1）
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int m , s ,c;
int ans[200];
struct sep
{
    int dis;
    int num;
};
bool cmp(sep a , sep b)
{
    return a.dis > b.dis;
}
bool cmp1(sep a , sep b)
{
    return  a.num < b.num;
}
bool cmp2(int a,int b)
{
    return a < b;
}
int main() {
    ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");
    fin>>m>>s>>c;
    if(m >= c)
    {
        fout<<c<<endl;
    }
    else
    {
        sep tmp[200];
        sep tmp1[200];
        int totall = 0;
        int t = 0;
        int s = 0;
        for(int i = 0; i < c; i++)
        {
            fin>>ans[i];
        }
        sort(ans , ans + c ,cmp2);
        for(int i = 0; i < c;i++)
        {
            if(i > 0)
            {
                tmp[t].dis = ans[i] - ans[i-1];
                tmp[t++].num = i;
            }
        }
        sort(tmp , tmp + t, cmp);
        if(m == 1)
            tmp1[s++] = tmp[t - 1];
        else
        {
            while(m-- > 1)
            {
                tmp1[s] = tmp[s];
                s++;
            }
        }
        sort(tmp1 , tmp1 , cmp1);
        for(int i = 0 ; i < s ;i++)
        {
            if(m == 1)
                totall += ans[c-1] - ans[0];
            else if(i == 0)
            {
                totall += ans[tmp1[i].num - 1] - ans[0] + 1;
            }
            else
                totall += ans[tmp1[i].num - 1] - ans[tmp1[i - 1].num] + 1;
        }
        totall += ans[c - 1] - ans[tmp1[s - 1].num] + 1;
        fout<<totall<<endl;
    }
    return 0;
}

