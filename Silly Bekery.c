#include<stdio.h>
main()
{
int i,x,a[100],b[100],c[100],d[100],e[100];
float a1=0,b1=0,c1=0,d1=0,e1=0,s1=0.0;
scanf("%d",&x);
for(i=0;i<x;i++)
    {
    scanf("%d",&a[i]);
    scanf("%d",&b[i]);
    scanf("%d",&c[i]);
    scanf("%d",&d[i]);
    scanf("%d",&e[i]);
    }
for(i=0;i<x;i++)
{
    a1 = a1+a[i];
    b1 = b1 + b[i] * 0.75;
    c1 = c1 + c[i] * 0.5;
    d1 = d1 + d[i] * 0.25;
    e1 = e1 + e[i] * 0.125;
}
s1 = b1+c1+d1+e1+a1;
int s = s1;
if(s < s1)s=s+1;
printf("%d",s);
}
