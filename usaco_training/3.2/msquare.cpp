/*
ID: duyimin1
PROG: msquare
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
#include<cmath>
#include<set>
#include<sstream>
#include<iomanip>
using namespace std;

ofstream fout ("msquare.out");
ifstream fin ("msquare.in");

struct q
{
    string temp;
    string op;
};
queue<q> que;
set<string> ss;
string str;
string A(string str)
{
    string t(str);
    for(int i = 0 ; i < 8 ; i++)
    {
        t[i] = str[7 - i];
    }
    return t;
}
string B(string str)
{
    string t;
    t = str[3] + str.substr(0 , 3) + str.substr(5 , 3) + str[4];
    return t;
}
string C(string str)
{
    string t(str);
    char c1 = t[2];
    t[2] = t[1];
    char c2 = t[5];
    t[5] = c1;
    char c3 = t[6];
    t[6] = c2;
    t[1] = c3;
    return t;
}
void bfs(string str)
{
    string be = "12345678";
    q b;
    b.temp = be;
    que.push(b);
    ss.insert(be);
    while(!que.empty())
    {
        q s = que.front();
        que.pop();
        if(s.temp == str)
        {
            fout<<s.op.size()<<endl;
            fout<<s.op<<endl;
            return;
        }
        q s1 = s;
        s1.temp = A(s1.temp);
        if(ss.find(s1.temp) == ss.end())
        {
            s1.op += 'A';
            que.push(s1);
            ss.insert(s1.temp);
        }
        s1 = s;
        s1.temp = B(s1.temp);
        if(ss.find(s1.temp) == ss.end())
        {
            s1.op += 'B';
            que.push(s1);
            ss.insert(s1.temp);
        }
        s1 = s;
        s1.temp = C(s1.temp);
        if(ss.find(s1.temp) == ss.end())
        {
            s1.op += 'C';
            que.push(s1);
            ss.insert(s1.temp);
        }
    }
}
string input()
{
    int i = 0;
    int cc;
    string s;
    stringstream sss(s);
    while(i++ < 8)
    {
        fin>>cc;
        sss<<cc;
    }
    return sss.str();
}
int main()
{
    str = input();
    bfs(str);
    return 0;
}
