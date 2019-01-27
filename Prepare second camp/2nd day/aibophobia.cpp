#include<stdio.h>
#include<string.h>
int sumout=9999999;
char x[1000];
void f(int i,int j,int sum)
{
     if(i==j)
     { 
           if(sumout>sum)sumout = sum;
           return;
     }
     if(x[i]!=x[j])
     {
          f(i+1,j,sum+1);
          f(i,j-1,sum+1);
     }
     if(x[i]==x[j])
     {
          f(i+1,j-1,sum);
     }
}
main()
{
      int n;
      int sum=0;
      gets(x);
      n = strlen(x);
      f(0,n,0);
      printf("%d",sumout);
}
