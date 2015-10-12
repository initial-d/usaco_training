/*
ID: duyimin1
PROG: palsquare
LANG: C++
*/
//×Ö·û´®×ª»»
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
    ofstream fout ("palsquare.out");
    ifstream fin ("palsquare.in");
    int n;
    fin>>n;
    for(int i = 1 ;i <= 300 ;i++ )
    {
        if(isp(change(i * i , n)))
            fout<<change(i , n)<<" "<<change(i * i , n)<<endl;
    }
    return 0;
}

