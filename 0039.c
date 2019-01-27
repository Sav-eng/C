#include<stdio.h>
int n; int m; int bad[1000]; int dish[1000];
void recipe(int count)
  {
      int i,check = 1,x;
      if(count < n)
        {
            for(i=1;i<=n;i++)
            {
                for(x=0;x<count;x++)
                {
                    if(dish[x] == i)
                    {
                        check = 0;
                    }
                }
                if(check == 1)
                    {
                        dish[count] = i; recipe(count+1);
                }
                check = 1;
                }
                }
                else
                    {
                        for(i=0;i<n;i++)
                        {
                            printf("%d ",dish[i]);
                }
                printf("\n");
                }
                }
 main()
 {
     int check = 1,i,x;
     scanf("%d%d",&n,&m);
     for(i=0;i<m;i++)
     {
             scanf("%d",&bad[i]);
     }
     for(i=1;i<=n;i++)
        {
             for(x=0;x<m;x++)
              {
                   if(bad[x]==i)
                   {
                        check = 0;
                    }
            }
      if(check == 1)
        {
            dish[0] = i; recipe(1);
      }
      check = 1;
      }
}
