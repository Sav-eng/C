#include<stdio.h>
bool nug[1000];
void f(int x)
{
    if(x>100)return ;
    f(x+6);
    nug[x]=1;
    f(x+9);
    nug[x]=1;
    f(x+20);
    nug[x]=1;
}
main()
{

    int n,i;
    f(0);
    scanf("%d",&n);
    if(n<=5)
    {
        printf("no");
        return 0;
    }
    for(i=1;i<=n;i++)
    {
        //printf("nug[%d] = %d\n",i,nug[i]);
        if(nug[i]==1)printf("%d\n",i);
    }
}

