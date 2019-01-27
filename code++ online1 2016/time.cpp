#include<stdio.h>
double radh;
double n;
double ans[1000][100];
double abs(double x)
{
    if(x>0)return x;
    return -x;
}
main()
{
    int radm,i=0,j;
    int h=0,m=-1;
    scanf("%lf",&n);
    while(h!=11 || m!= 59)
    {
        m++;
        if(m==60)
        {
            m = 0;
            h++;
        }
        radm = m*6;
        radh = h*30;
        radh += 0.5*m;
        if(abs(radh-radm)==n)
        {
            ans[i][0]= h;
            ans[i][1] = m;
            i++;
        }
        //printf("%lf %d\t",radh,radm);
        //printf("%d %d\n",h,m);

    }
    if(i==0)printf("NONE\n");
    for(j=0;j<i;j++)
    {
        if(ans[j][0]<10)printf("0%.0lf:",ans[j][0]);
        else printf("%.0lf:",ans[j][0]);
        if(ans[j][1]<10)printf("0%.0lf\n",ans[j][1]);
        else printf("%.0lf\n",ans[j][1]);
    }
    for(j=0;j<i;j++)
    {
        printf("%.0lf:",ans[j][0]+12);
        if(ans[j][1]<10)printf("0%.0lf\n",ans[j][1]);
        else printf("%.0lf\n",ans[j][1]);
    }
}
