/*
ID: duyimin1
PROG: heritage
LANG: C++
*/
#include<iostream>
#include<vector>
#include<fstream>
#include<string.h>
using namespace std;
ofstream fout ("heritage.out");
ifstream fin ("heritage.in");
struct NODE
{
    NODE *pleft;
    NODE *pright;
    char value;
};
void rebuild(char* pre , char* inorder , int nlen , NODE** root)
{
    if(pre == NULL || inorder == NULL)
        return;
    NODE* temp = new NODE;
    temp->value = *pre;
    temp->pleft = NULL;
    temp->pright = NULL;
    if(*root == NULL)
        *root = temp;
    if(nlen == 1)
        return;
    char* pio = inorder;
    char* ple = inorder;
    int ntl = 0;
    while(*pre != *ple)
    {
        if(pre == NULL || ple == NULL)
            return;
        ntl++;
        if(ntl > nlen)
            break;
        ple++;
    }
    int nll = 0;
    nll = (int)(ple - pio);
    int nrl = 0;
    nrl = nlen - nll - 1;
    if(nll > 0)
        rebuild(pre + 1 , inorder , nll , &((*root)->pleft));
    if(nrl > 0)
        rebuild(pre + nll + 1 , inorder + nll + 1, nrl , &((*root)->pright));
}
void posvis(NODE *root)
{
    if(root == NULL)
        return ;
    posvis(root->pleft);
    posvis(root->pright);
    fout<<root->value;
}
int main()
{
    char p[30] , i[30];
    NODE* Root = NULL;
    fin>>i;
    fin>>p;
    rebuild(p , i , strlen(p) , &Root);
    posvis(Root);
    fout<<endl;
    return  0;
}
