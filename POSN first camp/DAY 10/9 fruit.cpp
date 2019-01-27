  #include<stdio.h>
  main()
  {
      int n,i=0,j=0,k=0,m=0,a[100]={};
      scanf("%d",&n);
      if(n<=3)printf("Not Delicious");
      for(i=0;i<n;i+=4)
      {
          for(j=0;j<n;j+=6)
          {
              for(k=0;k<n;k+=9)
              {
                  for(m=0;m<n;m+=20)
                  {
                      if(i+j+k+m<n) a[i+j+k+m] = i+j+k+m;
                  }
              }
          }
      }
      for(i=0;i<100;i++)
      {
          if(a[i]!=0)printf("%d\n",a[i]);
      }
  }
