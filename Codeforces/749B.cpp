#include<stdio.h>
#include<map>
using namespace std;
map<int,int>mem;
int a[5];
int b[5];
int cx[]={0,1,2};
int cy[]={1,2,0};
int cz[]={2,0,1};
int ansx[5];
int ansy[5];
int abs(int x)
{
    if(x<0)return -x;
    return x;
}
int d(int x,int y)
{
    return x-y;
}
int m(int x1,int x2,int y1,int y2)
{
    return d(y1,y2)/d(x1,x2);
}
main()
{
    int i,check=0;
    for(i=0;i<3;i++)
    {
        scanf("%d%d",&a[i],&b[i]);
    }
    for(i=0;i<3;i++)
    {
        if(d(a[cx[i]],a[cy[i]])!=0)
        {
            //printf("%d",m(a[cx[i]],a[cy[i]],b[cx[i]],b[cy[i]]));
            if(m(a[cx[i]],a[cy[i]],b[cx[i]],b[cy[i]])>0)
            {
                //printf("a");
                if(mem.find(a[cz[i]]+abs(d(a[cx[i]],a[cy[i]])))== mem.end() && mem.find(b[cz[i]]+ abs(d(b[cx[i]],b[cy[i]]))) == mem.end())
                {

                    ansx[check] = a[cz[i]]+abs(d(a[cx[i]],a[cy[i]]));
                    ansy[check] = b[cz[i]]+abs(d(b[cx[i]],b[cy[i]]));
                    mem[a[cz[i]]+ abs(d(a[cx[i]],a[cy[i]]))] = 1;
                    mem[b[cz[i]]+ abs(d(b[cx[i]],b[cy[i]]))] = 1;
                    check++;
                }
                if(mem.find(a[cz[i]]-abs(abs(d(a[cx[i]],a[cy[i]]))))== mem.end() && mem.find(b[cz[i]]-abs(d(b[cx[i]],b[cy[i]])))== mem.end())
                {
                    printf("a");
                    ansx[check] = a[cz[i]]-abs(d(a[cx[i]],a[cy[i]]));
                    ansy[check] = b[cz[i]]-abs(d(b[cx[i]],b[cy[i]]));
                    mem[a[cz[i]]- abs(d(a[cx[i]],a[cy[i]]))] = 1;
                    mem[b[cz[i]]- abs(d(b[cx[i]],b[cy[i]]))] = 1;
                    check++;
                }
            }
            else if(m(a[cx[i]],a[cy[i]],b[cx[i]],b[cy[i]])<0)
            {
                //printf("a");
                if(mem.find(a[cz[i]]+abs(abs(d(a[cx[i]],a[cy[i]]))))!= mem.end() && mem.find(b[cz[i]]-abs(d(b[cx[i]],b[cy[i]]))) != mem.end())
                {

                    ansx[check] = a[cz[i]]+abs(d(a[cx[i]],a[cy[i]]));
                    ansy[check] = b[cz[i]]-abs(d(b[cx[i]],b[cy[i]]));
                    mem[a[cz[i]]+ abs(d(a[cx[i]],a[cy[i]]))] = 1;
                    mem[b[cz[i]]- abs(d(b[cx[i]],b[cy[i]]))] = 1;
                    check++;
                }
                if(mem.find(a[cz[i]]-abs(abs(d(a[cx[i]],a[cy[i]]))))!= mem.end() && mem.find(b[cz[i]]-abs(d(b[cx[i]],b[cy[i]]))) != mem.end())
                {
                    printf("a");
                    ansx[check] = a[cz[i]]-d(a[cx[i]],a[cy[i]]);
                    ansy[check] = b[cz[i]]+abs(d(b[cx[i]],b[cy[i]]));
                    mem[a[cz[i]]-d(a[cx[i]],a[cy[i]])] = 1;
                    mem[b[cz[i]]+ abs(d(b[cx[i]],b[cy[i]]))] = 1;
                    check++;
                }
            }
        }
        else
        {
            if(mem.find(a[cz[i]]-abs(abs(d(a[cx[i]],a[cy[i]]))))!= mem.end() && mem.find(b[cz[i]]-abs(d(b[cx[i]],b[cy[i]]))) != mem.end())
            {
                printf("a");
                ansx[check] = a[cz[i]]-d(a[cx[i]],a[cy[i]]);
                ansy[check] = b[cz[i]]+abs(d(b[cx[i]],b[cy[i]]));
                mem[a[cz[i]]-d(a[cx[i]],a[cy[i]])] = 1;
                mem[b[cz[i]]+ abs(d(b[cx[i]],b[cy[i]]))] = 1;
                check++;
            }
        }
    }
    printf("3\n");
    for(i=0;i<3;i++)
    {
        printf("%d %d\n",ansx[i],ansy[i]);
    }
}
/*
0 0
1 0
0 1
*/
