#include<stdio.h>
#include<string.h>
char so[30005];
char sn[30005];
char ans[30005];
main()
{
    bool checka=0;
    int n,m,i,j,check;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%s",sn);
        check=0;
        for(j=0;j<n;j++)
        {
            if(i!=0)
            {
                if(so[j]!=sn[j])check++;
                if(check>2 && checka==0)
                {
                    checka=1;
                    strcpy(ans,so);
                }
            }
        }
        strcpy(so,sn);
    }
    if(checka==1) printf("%s",ans);
    else printf("%s",so);
}
/*
4
12
HEAD
HEAP
LEAP
TEAR
REAR
BAER
BAET
BEEP
JEEP
JOIP
JEIP
AEIO
*/

