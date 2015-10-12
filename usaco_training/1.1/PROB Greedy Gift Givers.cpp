/*
ID: duyimin1
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
int np;

struct per
{
    string name;
    int num;
    int s;
    int ans;
}gift[10];
int find(string tmp)
{
    for(int i = 0; i < np; i++)
    {
        if(gift[i].name == tmp)
            return i;
    }
}

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    string mem,giver,reciver;
    fin>>np;
    for(int i = 0; i < np ;i++ )
    {
        fin>>mem;
        gift[i].name = mem;
        gift[i].num = 0;
    }
    int ini,n;
    for(int i = 0; i < np; i++)
    {
        fin>>giver;
        fin>>ini>>n;
        gift[find(giver)].s = ini;
        if(n != 0)
        {
            int ava = ini/n;
            for(int j = 0; j < n; j++)
            {
                fin>>reciver;
                gift[find(reciver)].num += ava;
            }
            gift[find(giver)].num += (ini - ava * n);
        }
    }
    for(int i = 0; i < np; i++)
    {
         gift[i].ans = gift[i].num - gift[i].s;
    }
    for(int i = 0; i < np; i++)
    {
        fout<<gift[i].name<<" "<<gift[i].ans<<endl;
    }

    return 0;
}

