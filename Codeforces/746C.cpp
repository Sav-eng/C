#include<stdio.h>

main()
{
    int s,p,d,t1,t2;
    double pt,x,y;
    int time=1,ans;
    scanf("%d%lf%lf%d%d%d%d",&s,&x,&y,&t1,&t2,&p,&d);
    pt = p;
    //printf("%lf",x);
    //printf("%d",p);
    if(x<y)
    {
        while(x!=y)
        {
            if(pt==x && d==1)
            {
                x++;
                pt++;
                time+=t1;
            }
            else
            {
                if(d==1)pt += 1/t1;
                else if(d==-1)pt -= 1/t1;
                x += 1/t1;
                if(pt==0 || pt == s) d = !d;
                time++;
            }
            printf("time = %d \t pt = %d \t x = %d\n",time,pt,x);
        }
    }
    else if(x>y)
    {
        while(x!=y)
        {
            if(pt==x && d==-1)
            {
                x++;
                pt++;
                time+=t1;
            }
            else
            {


            }
        }
    }
    printf("%d",time);
}
