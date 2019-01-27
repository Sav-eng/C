 #include<stdio.h>
 #include<math.h>
 main()
 {
     int n;
     double x1,x2,y1,y2,m;
     scanf("%d",&n);
     x1 = n+0.000000000001;
     x2 = n-0.000000000001;
     y1 = pow(x1,2);
     y2 = pow(x2,2);
     m = (y2-y1)/(x2-x1);
     printf("%lf",m);
 }
