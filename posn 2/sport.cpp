#include<stdio.h>
int k,a,b;
char ans[1000000];
void f(int x,int y,int z)
{
    int i;
    if(y==k || z==k)
    {
        for(i=a+b;i<x;i++)printf("%c ",ans[i]);
        printf("\n");
        return;
    }
    ans[x]='W';
    f(x+1,y+1,z);
    ans[x]='L';
    f(x+1,y,z+1);
}
main()
{
    int i,j;
    scanf("%d%d%d",&k,&a,&b);
    for(i=0;i<a;i++)ans[i]='W';
    for(j=i-1;j<b;j++)ans[j]='L';
    f(a+b,a,b);
}
