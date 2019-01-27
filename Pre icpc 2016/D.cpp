#include<stdio.h>
#include<set>
#include<algorithm>
#include<string.h>
using namespace std;
set<char> s;
int m;
char x[1000];
char x1[1000];
char ansdown[1000];
char ansup[1000];
void minu(int i,int mode,int tod)
{
    x[i] =9;
    if(x[i-1]-->=0)
    {
        x[i-1]--;
        recurdown(i,mode)
    }
    else
    {

    }
}
void pls(int i,int mode)
{
    if(x[i-1]++<=9)
    {
        x[i] = 0;
        x[i-1]++;
        recorup(i,mode);
    }
    else
    {

    }
}
void recurdown(int i,bool mode)
{
    if(i==m)
    {
        strcpy(ansdown,x);
        return ;
    }
    else if(s.find(x[i]) != s.end())
    {
        if(x[i]-->=0)x[i]--;
        else
        {
            minu(i,mode,0)
        }
        mode =0;
        recurdown(i,mode);
    }
    else if(s.find(x[i]) == s.end())
    {
        if(!mode && i+1 < m)x[i+1] = '9';
        recurdown(i+1,mode);
    }
}
void recurup(int i,bool mode)
{
    if(i==m)
    {
        strcpy(ansup,x);
        return ;
    }
    else if(s.find(x[i]) != s.end())
    {
        if(x[i]++<=9)x[i]++;
        else
        {
            pls(i,mode,0);
        }
        recurup(i,mode);
    }
    else if(s.find(x[i]) == s.end())
    {
        if(!mode)x[i+1] = '0';
        recurup(i+1,mode);
    }
}
main()
{
    int n,i,a;
    scanf("%s",x);
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf(" %c",&a);
        s.insert(a);
    }
    //printf("PASS\n");
    m = strlen(x);
    //printf("m = %d\n",m);
    strcpy(x1,x);
    recurdown(0,1);
    strcpy(x,x1);
    recurup(0,1);
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    i=0;
    while(ansdown[i]== '0')
    {
        i++;
    }
    if(ansdown[i]=='\0')printf("impossible");
    while(ansdown[i]!='\0')
    {
        printf("%c",ansdown[i]);
        i++;
    }
    printf("\n");
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    i=0;
    while(ansup[i]== '0')
    {
        //printf("%d ",i);
        i++;
    }
    if(ansup[i]=='\0')printf("impossible");
    while(ansup[i]!='\0')
    {
        printf("%c",ansup[i]);
        i++;
    }
}
