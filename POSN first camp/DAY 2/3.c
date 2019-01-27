#include<stdio.h>
#include<math.h>
main()
{
    double a,b,c,x,q,y,z,x1,x2;
    scanf("%lf %lf %lf",&a,&b,&c);
    q = b*b-4*a*c;
    if(a==0)
    {
        if(b==0)printf("%lf",-c);
        else
        {
            x = -c/b;
            printf("%lf",x);
        }
    }
    else if(b==0)
    {
        x = -c/a*a;
        y = c/a;
        if(x<0)printf("%lfi",y);
        x = sqrt(x);
        printf("%lf",x);
    }
    else if(q<0)
    {
        y = q/2*a;
        z = -b/2*a;
        printf("%lf+%lfi",z,y);
    }
    else
    {
        x1 = (-b+sqrt(q))/2*a;
        x2 = (-b-sqrt(q))/2*a;
        printf("%lf\n%lf",x1,x2);
    }

}
