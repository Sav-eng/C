#include<stdio.h>
#include<math.h>
#include<string.h>
struct node
{
    double x,y;
};
node ans;
main()
{
    ans.y = 0.000000;
    ans.x = 0.000000;
    double z;
    int b;
    char a[5];
    while(scanf("%d%s",&b,&a))
    {
        if(strlen(a)==1)
        {
            if(a[0]=='N')ans.y+=b;
            if(a[0]=='S')ans.y-=b;
            if(a[0]=='E')ans.x+=b;
            if(a[0]=='W')ans.x-=b;
        }
        else
        {
            if(a[0]=='N' && a[1]=='E')
            {
                ans.x+=sqrt((b*b)/2);
                ans.y+=sqrt((b*b)/2);
            }
            if(a[0]=='S' && a[1]=='W')
            {
                ans.x-=sqrt((b*b)/2);
                ans.y-=sqrt((b*b)/2);
            }
            if(a[0]=='N' && a[1]=='W')
            {
                ans.x-=sqrt((b*b)/2);
                ans.y+=sqrt((b*b)/2);
            }
            if(a[0]=='S' && a[1]=='E')
            {
                ans.x+=sqrt((b*b)/2);
                ans.y-=sqrt((b*b)/2);
            }
        }

    }
    z = sqrt((ans.x*ans.x)+(ans.y*ans.y));
    printf("%.3lf %.3lf\n%.3lf",ans.x,ans.y,z);
}
