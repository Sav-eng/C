#include<bits/stdc++.h>
using namespace std;
main()
{
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",a);
        power = a;
        for(j=i;j>=0;j--)
        {
            if(j)mem[j] += power;
            else
            {
                if(mem[j-1]==0)
                {

                }
                else
                {
                    if(mem[j]+power >= mem[j-1])
                    {
                        mem[j] = mem[j-1]-1;
                    }
                }
            }
        }
    }
}
