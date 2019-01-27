#include<stdio.h>
main()
{

int c[1000],i,Count=0;

for(i=0;i<3;i++)
{
    scanf("%d",&c[i]);
}
    if(c[0]%2!=0&&c[0]!=1) c[0]--;
    if(c[1]%2!=0&&c[1]!=1) c[1]--;
    if(c[2]%2!=0&&c[2]!=1) c[2]--;
while(c[0]%2==0)
{
    c[0] = c[0]/2;
    if(c[0]%2!=0&&c[0]!=1) c[0]--;
    Count++;
}
while(c[1]%2==0)
{
    c[1] = c[1]/2;
    if(c[1]%2!=0&&c[1]!=1) c[1]--;
    Count++;
}
while(c[2]%2==0)
{
    c[2] = c[2]/2;
    if(c[2]%2!=0&&c[2]!=1) c[2]--;
    Count++;
}
printf("%d",Count);
}
