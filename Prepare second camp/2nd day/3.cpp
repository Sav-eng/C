#include<stdio.h>
#include<conio.h>
int min = 999999;
int y;
int a[1000],b[1000],c[1000];
int n;
void f(char x,int sum)
{
     if(x==y)
     {                   
             printf("check%d ",sum); 
             if(min>sum)min=sum;
             return;
     }
     else
     {
         int i;
         for(i=0;i<n;i++)
         {
              if(a[i]==x)
              {
                   x = b[i];
                   sum += c[i];
                   //printf("%c",x);
                   f(x,sum);
              }
         }
     }
}
main()
{
      int i;
      char x,y;
      scanf("%d",&n);
      for(i=0;i<n;i++)
      {
          scanf(" %c %c %d",&a[i],&b[i],&c[i]);
      }
      scanf(" %c %c",&x,&y);
      //printf("%c",y);
      f(x,0);
      printf("%d",min);
      getch();
}
