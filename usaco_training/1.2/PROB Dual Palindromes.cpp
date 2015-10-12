/*
ID: duyimin1
PROG: dualpal
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

string change(int a , int b)
{
    char tmp[20];
    string hi;
    int t = 0;
    int ans[20];
    while(1)
    {
        ans[t++] = a % b;
        a = a / b;
        if(a == 0)
            break;
    }
    for(int i = t - 1; i >= 0;i--)
    {
        if(ans[i] <= 9)
            tmp[t - 1 -i] =  ans[i] + '0';
        else
        {
            tmp[t - 1 -i] = 'A' + ans[i] - 10;
        }
    }
    tmp[t] = '\0';
    hi = string(tmp);
    return hi;
}
bool isp(string a)
{
    int len = a.size();
    for(int i = 0; i < len; i++)
    {
        if(a[i] != a[len - i -1])
            return false;
    }
    return true;
}
int main() {
    ofstream fout ("dualpal.out");
    ifstream fin ("dualpal.in");
    int n,m;
    fin>>n>>m;
    int o;
    bool flag;
    int r = 0;
    for(int i = m+1 ; ;i++ )
    {
        o = 0;
        flag =false;
        for(int j = 2; j <= 10 ;j++)
        {
            if(isp(change(i , j)))
            {
                o++;
                if(o >= 2)
                {
                    flag = true;
                    break;
                }
            }
        }
        if(flag)
        {
            fout<<i<<endl;
            r++;
        }
        if(r >= n)
            break;
    }
    return 0;
}

