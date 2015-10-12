/*
ID: duyimin1
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

//×Ö·û´®¶ÁÈ¡£¬×Ö·û´®±È½Ï

int main() {
    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in");
    ifstream fin1 ("dict.txt");
    string str;
    int len;
    string num;
    bool flag = false;
    fin>>num;
    while(fin1>>str)
    {
        string tmp;
        len = str.size();
        for(int i = 0; i < len; i++)
        {
            if((str[i] == 'A') || (str[i] == 'B') || (str[i] == 'C'))
            {
                tmp += "2";
            }
            else if((str[i] == 'D') || (str[i] == 'E') || (str[i] == 'F'))
            {
                tmp += "3";
            }
            else if((str[i] == 'G') || (str[i] == 'H') || (str[i] == 'I'))
            {
                tmp += "4";
            }
            else if((str[i] == 'J') || (str[i] == 'K') || (str[i] == 'L'))
            {
                tmp += "5";
            }
            else if((str[i] == 'M') || (str[i] == 'N') || (str[i] == 'O'))
            {
                tmp += "6";
            }
            else if((str[i] == 'P') || (str[i] == 'R') || (str[i] == 'S'))
            {
                tmp += "7";
            }
            else if((str[i] == 'T') || (str[i] == 'U') || (str[i] == 'V'))
            {
                tmp += "8";
            }
            else if((str[i] == 'W') || (str[i] == 'X') || (str[i] == 'Y'))
            {
                tmp += "9";
            }
        }
        if(num == tmp)
        {
            fout<<str<<endl;
            flag = true;
        }
    }
    if(!flag)
        fout<<"NONE"<<endl;
    return 0;
}

