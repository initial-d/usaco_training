/*
ID: duyimin1
PROG: fence9
LANG: C++
*/
#include<iostream>
#include<set>
#include<math.h>
#include<vector>
#include<fstream>
#include<algorithm>
#include<stdio.h>
using namespace std;
ofstream fout ("fence9.out");
ifstream fin ("fence9.in");

int n , m , p;
int gcd(int x , int y)
{
    if(x > y)
        return y == 0 ? x : gcd(y , x%y);
    else
        return x == 0 ? y : gcd(x , y%x);
}

int main(int argc, char *argv[])
{
    fin>>n>>m>>p;
    fout<<((p * m)/2 + 1 - ((gcd(n , m) + 1) + (gcd(abs(n - p) , m)+1) + p - 2)/2)<<endl;
    return 0;
}
