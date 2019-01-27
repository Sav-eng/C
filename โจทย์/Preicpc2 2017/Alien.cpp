#include<bits/stdc++.h>
using namespace std;
char x[10001],y[10001];
//string x,y;
main()
{
    int T,n,i,j,m,ti;
    scanf("%d",&T);
    while(T--)
    {
        scanf(" %s %s",x,y);
        n = strlen(x);
        m = strlen(y);
        i=0;
        j=0;
        int now;
        while(i<n || j<m)
        {
            if(i<n && j==m && !((x[i-1]=='+' || x[i-1]=='*') && x[i]==y[now]))
            {
                if(x[i+1]=='*')while(x[i+1]=='*')i+=2;
                else
                {
                    printf("NO\n");
                    break;
                }
            }
            else if(x[i+1]=='*')
            {
                now = j;
                if(x[i]==y[j])
                {
                    while(x[i]==y[j])j++;
                }
                i+=2;
            }
            else if(x[i+1]=='+')
            {
                now = j;
                if(x[i]==y[j])
                {
                    while(x[i]==y[j])j++;
                }
                else
                {
                    printf("NO\n");
                    break;
                }
                i+=2;
            }
            else
            {
                if(x[i-1]=='*'&& x[i]==y[now])
                {
                    //printf(" i = %d now = %d\n",i,now);
                    ti = i;
                    while(x[ti]==y[now] && x[ti+1] != '*' && x[ti+1] != '+' && ti<n && now <m)ti++,now++;
                    i = ti;
                    j = max(now,j);
                    //printf("%d %d\n",i,now);
                }
                else if(x[i-1]=='+'&& x[i]==y[now])
                {
                    //printf(" i = %d now = %d\n",i,now);
                    ti = i;
                    now++;
                    while(x[ti]==y[now] && x[ti+1] != '*' && x[ti+1] != '+' && ti<n && now <m)ti++,now++;
                    i = ti;
                    j = max(now,j);
                    //printf("%d %d\n",i,now);
                }
                else if(x[i]!=y[j])
                {
                    printf("NO\n");
                    break;
                }
                else
                {
                    now = j;
                    i++,j++;
                }
            }
            //printf("%d %d\n",i,j);
        }
        //printf("\tafterrun %d %d\n",i,j);
        if(i==n && j==m)printf("YES\n");
    }
}
/*
1
A+S+E+D+DD ASSSEEDDD
*/
