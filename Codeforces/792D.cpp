#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,q,i,a,check=0,t,n2,floor;
    scanf("%lld%d",&n,&q);
    t =n;
    n2 = 0;
    i=1;
    while(i<n)
    {
        mul[n2++]; = i;
        i*=2;
    }
    for(i=0;i<q;i++)
    {
        scanf("%d",&a);
        t = n+1;
        while(t!=a)
        {
            if(t>a)t/=2;
            else t+=(t/2);
            check++;
        }
        floor = n2-check;
        //printf("%d",floor);
        scanf("%s",&tab);
        m = strlen(tab);
        for(i=0;i<m;i++)
        {
            if(tab[i]=='L')
            {
                if(floor!=0)a-=mul[floor--];
            }
            else if(tab[i]=='R')
            {
                if(floor!=0)a+=mul[floor--];
            }
            else
            {
                if(floor!=n2)
                {
                    a+=mul[floor];

                }
            }
        }
    }

}
