/*
ID: duyimin1
PROG: beads
LANG: C++
*/
//切项链，见名知义，三段枚举
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

string a,str;
int max1,max2,num1 = 0,num2 = 0,num3 = 0,num4 = 0,len;
int n1,n2,n3,n4;
int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    fin>>len;
    fin>>a;
    str = a + a + a;
    max1 = 0;
    max2 = 0;
    for(int i = len; i < 2 * len; i++)
    {
        int j = i;
        n1 = 0;
        n2 = 0;
        n3 = 0;
        n4 = 0;
        num1 = 0;
        num2 = 0;
        num3 = 0;
        num4 = 0;
        if(str[j] == 'r')
        {
            while((str[j] != 'b') && (j >= 0) && (j < 3 * len))
            {
                n1++;
                j++;
            }
            while((str[j] != 'r') && (j >= 0) && (j < 3 * len))
            {
                num1++;
                j++;
            }
            j = i;
            while((str[j] != 'b') && (j >= 0) && (j < 3 * len))
            {
                n2++;
                j--;
            }
            while((str[j] != 'r') && (j >= 0) && (j < 3 * len))
            {
                num2++;
                j--;
            }
            max1 = max(num1 + n1 + n2 - 1, num2 + n1 + n2 - 1);
        }
        else if(str[j] == 'b')
        {
            while((str[j] != 'r') && (j >= 0) && (j < 3 * len))
            {
                n1++;
                j++;
            }
            while((str[j] != 'b') && (j >= 0) && (j < 3 * len))
            {
                num1++;
                j++;
            }
            j = i;
            while((str[j] != 'r') && (j >= 0) && (j < 3 * len))
            {
                n2++;
                j--;
            }
            while((str[j] != 'b') && (j >= 0) && (j < 3 * len))
            {
                num2++;
                j--;
            }
            max1 = max(num1 + n1 + n2 - 1, num2 + n1 + n2 - 1);
        }
        else if(str[j] == 'w')
        {
            while((str[j] == 'w') && (j >= 0) && (j < 3 * len))
            {
                n3++;
                j++;
            }
            if(str[j] == 'r')
            {
                while((str[j] != 'b') && (j >= 0) && (j < 3 * len))
                {
                    num3++;
                    j++;
                }
                while((str[j] != 'r') && (j >= 0) && (j < 3 * len))
                {
                    num3++;
                    j++;
                }
            }
            else if(str[j] == 'b')
            {
                while((str[j] != 'r') && (j >= 0) && (j < 3 * len))
                {
                    num3++;
                    j++;
                }
                while((str[j] != 'b') && (j >= 0) && (j < 3 * len))
                {
                    num3++;
                    j++;
                }
            }
            j = i;
            while((str[j] == 'w') && (j >= 0) && (j < 3 * len))
            {
                n4++;
                j--;
            }
            if(str[j] == 'r')
            {
                while((str[j] != 'b') && (j >= 0) && (j < 3 * len))
                {
                    num4++;
                    j--;
                }
                while((str[j] != 'r') && (j >= 0) && (j < 3 * len))
                {
                    num4++;
                    j--;
                }
            }
            else if(str[j] == 'b')
            {
                while((str[j] != 'r') && (j >= 0) && (j < 3 * len))
                {
                    num4++;
                    j--;
                }
                while((str[j] != 'b') && (j >= 0) && (j < 3 * len))
                {
                    num4++;
                    j--;
                }
            }
            max1 = max(num3 + n3 + n4 - 1, num4 + n3 + n4 - 1);
        }
        if(max2 < max1)
            max2 = max1;
        if(max2 > len)
            max2 = len;
    }
    fout<<max2<<endl;
    return 0;
}

