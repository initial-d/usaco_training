/*
ID: duyimin1
PROG: fact4
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
#include<iomanip>
using namespace std;

ofstream fout ("fact4.out");
ifstream fin ("fact4.in");

int n;
int main()
{
    fin>>n;
    int t = 1;
    for(int i = 2 ; i <= n ; i++)
    {
        t = t * i;
        while(t % 10 == 0)
            t /= 10;
        t %= 10000;
    }
    fout<<t%10<<endl;
    return 0;
}
