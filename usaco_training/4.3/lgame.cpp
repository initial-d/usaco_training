/*
ID: duyimin1
PROG: lgame
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
#define MAX_V 410
ofstream fout ("lgame.out");
ifstream fin ("lgame.in");
ifstream ff ("lgame.dict");
string src , str;
int len;
map<char , int> rule;
map<char , int> coun;
map<string , int> cnt;
vector<string> mm;
void init()
{
    rule['q'] = rule['j'] = rule['z'] = rule['x'] = 7;
    rule['w'] = rule['f'] = rule['k'] = rule['v'] = 6;
    rule['e'] = rule['i'] = rule['s'] = 1;
    rule['r'] = rule['t'] = rule['a'] = rule['n'] = 2;
    rule['y'] = rule['p'] = rule['g'] = rule['h'] = rule['b'] = rule['m'] = 5;
    rule['u'] = rule['d'] = rule['c'] = 4;
    rule['o'] = rule['l'] = 3;
}
bool check(string s)
{
    if((int)s.size() > len) return false;
    map<char , int> vis;
    for(int i = 0 ; i < (int)s.size() ; i++)
    {
        if(!coun[s[i]])
            return false;
        vis[s[i]]++;
    }
    for(int i = 0 ; i < (int)s.size() ; i++)
    {
        if(vis[s[i]] > coun[s[i]])
            return false;
    }
    return true;
}
int cal(string str)
{
    int res = 0;
    for(int i = 0 ; i < (int)str.size() ;i++)
        res += rule[str[i]];
    return res;
}
int main()
{
    fin>>src;
    len = src.size();
    for(int i = 0 ; i < len ;i++)
        coun[src[i]]++;
    init();
    int M = 0;
    int temp;
    while(ff>>str && str != ".")
    {
        if(check(str))
        {
            temp = cal(str);
            if(temp > M)
                M = temp;
            cnt[str] = temp;
        }
    }
    if(len >= 6){
        for(map<string , int>::iterator it = cnt.begin(); it != cnt.end() ;it++)
        {
            string r1 = it->first;
            int ll = r1.size();
            if( ll >= 3 && ll <= 4)
                mm.push_back(it->first);
        }
        for(int i = 0 ; i < (int)mm.size() ; i++)
        {
            for(int j = i ; j < (int)mm.size() ; j++)
            {
                string sss = mm[i]+mm[j];
                if(check(sss))
                {
                    temp = cal(sss);
                    if(temp >= M)
                        M = temp;
                    cnt[mm[i] + " " + mm[j]] = temp;
                }
            }
        }
    }
    fout<<M<<endl;
    for(map<string , int>::iterator it = cnt.begin(); it != cnt.end() ;it++)
        if(it->second == M)
            fout<<it->first<<endl;
    return 0;
}
