/*
ID: duyimin1
PROG: ratios
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
#include<set>
#include<sstream>
#include<iomanip>
using namespace std;

ofstream fout ("ratios.out");
ifstream fin ("ratios.in");

int a , b , c;
int x1 , y1 , z1;
int x2 , y2 , z2;
int x3 , y3 , z3;
int main()
{
    fin>>a>>b>>c;
    fin>>x1>>y1>>z1;
    fin>>x2>>y2>>z2;
    fin>>x3>>y3>>z3;
    bool flag = false;
    for(int i = 0 ; i < 100 && !flag; i++)
    {
        for(int j = 0 ; j < 100 && !flag;j++)
        {
            for(int k = 0 ; k < 100 && !flag;k++)
            {
                int t1 = x1 * i + x2 *j + x3 * k;
                int t2 = y1 * i + y2 *j + y3 * k;
                int t3 = z1 * i + z2 *j + z3 * k;
                int r;
                if(a && t1 && t1 % a == 0)
                {
                    r = t1 / a;
                    if(r * b == t2 && r * c == t3)
                    {
                        flag = true;
                        fout<<i<<" "<<j<<" "<<k<<" "<<r<<endl;
                        break;
                    }
                }
                else if(b && t2 && t2 % b == 0)
                {
                    r = t2 / b;
                    if(r * a == t1 && r * c == t3)
                    {
                        flag = true;
                        fout<<i<<" "<<j<<" "<<k<<" "<<r<<endl;
                        break;
                    }
                }
                else if(c && t3 && t3 % c == 0)
                {
                    r = t3 / c;
                    if(r * b == t2 && r * a == t1)
                    {
                        flag = true;
                        fout<<i<<" "<<j<<" "<<k<<" "<<r<<endl;
                        break;
                    }
                }
            }
        }
    }
    if(!flag)
        fout<<"NONE"<<endl;
    return 0;
}
