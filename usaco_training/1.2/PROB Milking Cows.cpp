/*
ID: duyimin1
PROG: milk2
LANG: C++
*/
//区间排序优化，然后穷举
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;


struct interval
{
    int beg;
    int end;
};
bool cmp(interval a , interval b)
{
    return a.beg < b.beg;
}
int n;
int main() {
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    fin>>n;
    interval cowlist[n] , tmp[n];
    for(int i = 0; i < n ;i++)
    {
        fin>>cowlist[i].beg>>cowlist[i].end;
    }
    sort(cowlist , cowlist + n , cmp);
    tmp[0] = cowlist[0];
    int t = 0;
    int tmp1,tmp2;
    for(int i = 1; i < n; i++)
    {
        if((cowlist[i].beg >= tmp[t].beg) && (cowlist[i].beg <= tmp[t].end))
        {
            if(cowlist[i].end > tmp[t].end)
                tmp[t].end = cowlist[i].end;
        }
        else
        {
            tmp[++t] = cowlist[i];
        }
    }
    int max1 = 0 , max2 = 0;
    for(int i = 0; i <= t ; i++)
    {
        tmp1 = tmp[i].end - tmp[i].beg;
        if(tmp1 > max1)
            max1 = tmp1;
        if(i < t)
            tmp2 = tmp[i + 1].beg - tmp[i].end ;
        if((tmp2 > max2) && (i < t))
            max2 = tmp2;
    }
    fout<<max1<<" "<<max2<<endl;
    return 0;
}

