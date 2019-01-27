#include<stdio.h>

main()
{
int n;
scanf("%d",&n);
int i = 0,j=0;
for(i = 1;i <= n;i++)
{
for(j = 1;j <= n;j++)
{
if(i == j || i == n-j+1)
{
printf("%d",i);
}
else
{
printf(" ");
}
}
for(j = 1;j <= n;j++)
{
if(i == j || i == n-j+1)
{
printf("*");
}
else
{
printf(" ");
}
}
printf("\n");
}
}
