#include<stdio.h>
int i,p[1000000],k[1000000],Min=100000000,x,y;
void function(int i,int prew,int kom,int check)
{
    if(i == x)
    {
        if(check == 1)
        {
            if(prew>kom) y = prew-kom;
            else y = kom - prew;
            if(Min>y)Min = y;
        }
    }
    else
    {
        function(i+1,prew*p[i],kom+k[i],1);
        function(i+1,prew,kom,check);
    }
}
main()
{

    scanf("%d",&x);
    for(i=0;i<x;i++)
    {
        scanf("%d",&p[i]);
        scanf("%d",&k[i]);
    }
    function(0,1,0,0);
    printf("%d",Min);

}
