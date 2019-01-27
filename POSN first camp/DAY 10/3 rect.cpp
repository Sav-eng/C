#include<stdio.h>
main()
{
    struct point
    {
        int x;
        int y;
    };
    struct point p1,p2;
    struct rect
    {
        struct point p1;
        struct point p2;
    };
    struct rect x;
    int area;
    scanf("%d %d %d %d",&x.p1.x, &x.p1.y, &x.p2.x, &x.p2.y);
    area = (x.p1.x-x.p2.x)*(x.p1.y-x.p2.y);
    printf("%d",area);
}
