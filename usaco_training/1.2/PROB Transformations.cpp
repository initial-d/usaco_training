/*
ID: duyimin1
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;


int n;
void roate(char tmp[11][11] , char s[11][11])
{
    for(int i = 0;i < n; i++)
        for(int j = 0;j < n; j++)
        {
            tmp[j][n - 1 - i] = s[i][j];
        }
}
void mirror(char tmp[11][11] , char s[11][11])
{
    for(int i = 0;i < n; i++)
        for(int j = 0;j < n; j++)
        {
            tmp[j][i] = s[j][n - 1 - i];
        }
}
bool same(char tmp[11][11] , char s[11][11])
{
    for(int i = 0;i < n; i++)
        for(int j = 0;j < n; j++)
        {
            if(tmp[i][j] != s[i][j])
                return false;
        }
    return true;
}
int main() {
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");
    fin>>n;
    char s[11][11],tmp[11][11],s1[11][11],tmp1[11][11];
    for(int i = 0;i < n; i++)
        for(int j = 0;j < n; j++)
        {
            fin>>s[i][j];
        }
    for(int i = 0;i < n; i++)
        for(int j = 0;j < n; j++)
            fin>>s1[i][j];
    if(1 == 2)
        fout<<"hello"<<endl;
    else
    {
        roate(tmp , s);
        if(same(tmp , s1))
            fout<<'1'<<endl;
        else
        {
            roate(tmp1 , tmp);
            if(same(tmp1 , s1))
                fout<<'2'<<endl;
            else
            {
                roate(tmp , tmp1);
                if(same(tmp , s1))
                    fout<<'3'<<endl;
                else
                {
                    mirror(tmp , s);
                    if(same(tmp  , s1))
                        fout<<'4'<<endl;
                    else
                    {
                        roate(tmp1 , tmp);
                        if(same(tmp1 , s1))
                            fout<<'5'<<endl;
                        else
                        {
                            roate(tmp , tmp1);
                            if(same(tmp , s1))
                                fout<<'5'<<endl;
                            else
                            {
                                roate(tmp1 , tmp);
                                if(same(tmp1 , s1))
                                    fout<<'5'<<endl;
                                else if(same(s , s1))
                                    fout<<'6'<<endl;
                                else
                                    fout<<'7'<<endl;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

