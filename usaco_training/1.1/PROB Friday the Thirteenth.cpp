/*
ID: duyimin1
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int n;
int cusor;
int hash[7] = {0};
bool isleap(int m)
{
    if((m % 400) == 0)
        return true;
    else if(((m % 4) == 0) && ((m % 100) != 0))
        return true;
    else
        return false;//不要忘记缺省情况，否则会出错。
}
int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    cusor = 6;
    hash[cusor]++;
    fin>>n;
    for(int i = 2; i <= n * 12; i++ )
    {
        int tmp = (i - 1) % 12;
        if(tmp == 2)
        {
            if(isleap(1900 + (i - 1)/12))
            {
                cusor = (29 + cusor) % 7;
                hash[cusor]++;
            }
            else
            {
                cusor = (28 + cusor) % 7;
                hash[cusor]++;
            }
        }
        else if((tmp == 0) || (tmp == 1) ||( tmp == 3) ||(tmp == 5) ||(tmp == 7) || (tmp == 8) ||(tmp == 10))
        {
            cusor = (31 + cusor) % 7;
            hash[cusor]++;
        }
        else
        {
            cusor = (30 + cusor) % 7;
            hash[cusor]++;
        }
    }
    fout<<hash[6]<<" "<<hash[0]<<" "<<hash[1]<<" "<<hash[2]<<" "<<hash[3]<<" "<<hash[4]<<" "<<hash[5]<<endl;
    return 0;
}

