/*
ID: duyimin1
PROG: shopping
LANG: C++
*/
#include<iostream>
#include<map>
#include<string>
#include<fstream>
#include<algorithm>
#include<string.h>
using namespace std;
ofstream fout ("shopping.out");
ifstream fin ("shopping.in");

int s , n;
struct special
{
    int p;
    int ck[1000];
};
special offer[106];
struct pur
{
    int c,k,p;
};
pur bb[6];
int b;
int f[6][6][6][6][6];
void dp()
{
    int i1,i2,i3,i4,i5;
    int j1,j2,j3,j4,j5;
    for(i1 = 0 ; i1 <= bb[0].k ;i1++)
            for(i2 = 0 ; i2 <= bb[1].k ;i2++)
                for(i3 = 0 ; i3 <= bb[2].k ;i3++)
                    for(i4 = 0 ; i4 <= bb[3].k ;i4++)
                        for(i5 = 0 ; i5 <= bb[4].k ;i5++)
                        {
                            f[i1][i2][i3][i4][i5] = i1*bb[0].p+i2*bb[1].p+i3*bb[2].p+i4*bb[3].p+i5*bb[4].p;
                        }
    f[0][0][0][0][0] = 0;
    for(int i = 0 ; i < s ; i++)
    {
        j1 = offer[i].ck[bb[0].c];
        j2 = offer[i].ck[bb[1].c];
        j3 = offer[i].ck[bb[2].c];
        j4 = offer[i].ck[bb[3].c];
        j5 = offer[i].ck[bb[4].c];
        for(i1 = j1 ; i1 <= bb[0].k ;i1++)
            for(i2 = j2 ; i2 <= bb[1].k ;i2++)
                for(i3 = j3 ; i3 <= bb[2].k ;i3++)
                    for(i4 = j4 ; i4 <= bb[3].k ;i4++)
                        for(i5 = j5 ; i5 <= bb[4].k ;i5++)
                        {
                            f[i1][i2][i3][i4][i5] = min(f[i1][i2][i3][i4][i5] ,
                                                        f[i1 - j1][i2-j2][i3-j3][i4-j4][i5-j5] + offer[i].p);

                        }
    }
}
int main()
{
    fin>>s;
    int a , b;
    for(int i = 0 ; i < s ; i++)
    {
        fin>>n;
        for(int j = 0 ; j < n ;j++)
        {
            fin>>a>>b;
            offer[i].ck[a] = b;
        }
        fin>>offer[i].p;
    }
    fin>>b;
    for(int i = 0 ; i < b ;i++)
    {
        fin>>bb[i].c>>bb[i].k>>bb[i].p;
        offer[s].p = bb[i].p;
        offer[s].ck[bb[i].c] = 1;
        s++;
    }
    dp();
    fout<<f[bb[0].k][bb[1].k][bb[2].k][bb[3].k][bb[4].k]<<endl;
    return 0;
}
