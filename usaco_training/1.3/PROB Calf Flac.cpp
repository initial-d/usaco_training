/*
ID: duyimin1
PROG: calfflac
LANG: C++
*/
//注意输入输出，C格式的输入输出。连续大段带空格的输入如何处理
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
struct posi
{
    int n;
    char a;
}hi[20001];
int main()
{
    FILE *fin = fopen ("calfflac.in", "r");
    FILE *fout = fopen ("calfflac.out", "w");
    char str[20001];
    char str1[20001];
    char tmp[81];
    char c;
    while( fgets (tmp, 80, fin) != NULL)
    {
       strcat(str, tmp);
    }
    int len = strlen(str);
    str[len] = '\0';
    int t =0 ;
    for(int i = 0; i < len ;i++)
    {
        if((isupper(str[i])) || (islower(str[i])))
        {
            hi[t].a = tolower(str[i]);
            hi[t].n = i;
            str1[t++] = tolower(str[i]);
        }
    }
    str1[t] = '\0';
    int num  = 1,tem;
    int maxn = 0;
    for(int i = 0; i < t - 1 ; i++)
    {
        int r;
        if(str1[i] == str1[i + 1])
        {
            num = 2;
            r = 1;
            while((i - r >= 0) && (i + 1 + r < t))
            {
                if(str1[i - r] == str1[i + 1 + r])
                {
                    num += 2;
                    r++;
                }
                else
                {
                    break;
                }
            }
        }
        if(num > maxn)
        {
            maxn = num;
            tem = i;
        }
        num = 1;
        int r1 = 1;
        while((i - r1 >= 0) && (i + r1 < t))
        {
            if(str1[i - r1] == str1[i + r1])
            {
                num += 2;
                r1++;
            }
            else
            {
                break;
            }
        }
        if(num > maxn)
        {
            maxn = num;
            tem = i;
        }
    }
    fprintf(fout,"%d\n" , maxn);
    if(maxn % 2 == 0)
    {
        int s = hi[tem - (maxn / 2 ) + 1].n;
        int e = hi[tem + (maxn / 2)].n;
        for(int i = s;i <= e; i++)
        {
            fprintf(fout,"%c", str[i]);
        }
    }
    else
    {
        int s = hi[tem - (maxn / 2 )].n;
        int e = hi[tem + (maxn /2)].n;
        for(int i = s;i <= e; i++)
        {
            fprintf(fout,"%c", str[i]);
        }
    }
    fprintf(fout,"\n");
    fclose(fin);
    fclose(fout);
    return 0;
}
