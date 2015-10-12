/*
ID: duyimin1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

long long work(string tmp)
{
    int i = 0;
    long long ans = 1;
    int len = tmp.size();
    while(i < len)
    {
        ans = ans * (tmp[i] - 'A' + 1);
        i++;
    }
    return ans;
}
int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string a,b;
    fin>>a;
    fin>>b;
    if((work(a)%47) == (work(b)%47))
        fout<<"GO"<<endl;
    else
        fout<<"STAY"<<endl;
    return 0;
}

