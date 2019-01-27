#include<stdio.h>
int a[1000][1000];
int sum=0;
int max=0;
void f(int i,int j)
{
     if(a[i+1][j]==0 && a[i-1][j]==0 && a[i][j+1] == 0 && a[i][j-1]==0) return;
     if(a[i+1][j]==1)
     {
         a[i+1][j]==0;
         sum++;
         if(max<sum)max=sum;
         f(i+1,j);
     }
     if(a[i-1][j]==1)
     {
         a[i-1][j]==0;
         sum++;
         if(max<sum)max=sum;
         f(i-1,j);
     }
     if(a[i][j+1]==1)
     {
         a[i][j+1]==0;
         sum++;
         if(max<sum)max=sum;
         f(i,j+1);
     }
     if(a[i][j-1]==1)
     {
         a[i][j-1]==0;
         sum++;
         if(max<sum)max=sum;
         f(i,j-1);
     }
}
main()
{
      int n,i,j;
      scanf("%d",&n);
      for(i=0;i<n;i++)
      {
            for(j=0;j<n;j++)
            {
                 scanf("%d",&a[i][j]);
            }
      }
      for(i=0;i<n;i++)
      {
              for(j=0;j<n;j++) 
              {
                     sum = 0;
                     //printf("a");
                     if(a[i][j]==1)f(i,j);
              }
      }
      printf("%d",max);
}


