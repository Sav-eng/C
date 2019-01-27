#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+2;
int mem[MAXN];
int mem1[MAXN];
int mem2[MAXN];
int point1[MAXN];
int point2[MAXN];
int prakob[MAXN];
int pref[80000][20];
vector<int>prime;
int gcd(int x,int y)
{
    if(y!=0)return gcd(y,x%y);
    return x;
}
main()
{
    int a,b,c,d,t,t2,i,check,n,m;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    t = 2;
    int C = 0;
    n = b-a+1;
    m = d-c+1;
    while(t<=d)
    {
        //printf("mem[%d] = %d\n",t,mem[t]);
        if(mem[t])
        {
            t++;
            continue;
        }
        int t2 = t;
        prime.push_back(t);
        C++;
        while(t2<=d)
        {

            if(t2<=d)mem[t2] = 1;
            t2 +=t;
            //check++;
            //printf("%d\n",t2);
        }
        //printf("t = %d\n",t);
        t++;
    }
    int k=0;
    /*for(i=1;i<=sqrt(d);i++)
    {
        t =  i;
        k=0;
        while(t!=1)
        {
            while(t%prime[k]==0 && t!=1)
            {
                t/=prime[k];
                prakob[i]++;
            }
            k++;
        }
    }*/
    int j,ans=0,ansl=0,ansr=0;
    for(i=0;i<prime.size();i++)
    {
        int cnt = 0;
        for(j=prime[i];j<=MAXN;j*=prime[i])
        {
            pref[i][cnt] = j;
            //printf("pref[%d][%d] = %d\n",i,cnt,j);
            cnt++;
        }
    }
    for(i=a;i<=b;i++)mem1[i] = i;
    for(i=c;i<=d;i++)mem2[i] = i;
    for(i=0;i<prime.size();i++)
    {
        for(j=a;j%prime[i]!=0;j++);
        //printf("start : %d prime :%d\n",j,prime[i]);
        for(j;j<=b;j+=prime[i])
        {
            k = 0;
            //printf("j = %d (%d)\n",j,mem1[j]%j);
            if(mem1[j]!=0)
            {
                //printf("COME");
                while(mem1[j]>=pref[i][k] && mem1[j]%pref[i][k]==0)k++;
                k--;
                //printf("1j = %d k = %d, divideby %d\n",mem1[j],k,pref[i][k]);
                mem1[j] /= pref[i][k];
                point1[j]+= k+1;
            }
        }
        for(j=c;j%prime[i]!=0;j++);
        for(j=c;j<=d;j++)
        {
            k = 0;
            //printf("2j = %d k = %d\n",j,k);
            if(mem2[j]!=0 && mem2[j]%j==0)
            {
                while(mem2[j]%pref[i][k]==0)k++;
                mem2[j] /= pref[i][k];

                point2[j] +=k;
            }
        }

    }
    for(i=a;i<=b;i++)printf("%d ",mem1[i]);
    for(i=b;i>=a;i--)
    {
        if(ans<point1[i])
        {
            ans = point1[i];
            ansl = i;
        }
    }
    ans = 0;
    for(i=d;i>=c;i--)
    {
        if(ans<point2[i])
        {
            ans = point2[i];
            ansr = i;
        }
    }
    //for(i=1;i<=d;i++)printf("prakob[%d] = %d\n",i,prakob[i]);

    /*for(i=a;i<=b;i++)
    {
        for(j=c;j<=d;j++)
        {
            t = prakob[gcd(j,i)];
            //printf("gcd(%d,%d) = %d P[%d]\n",i,j,gcd(i,j),t);
            if(ans < t)
            {
                ans = t;
                ansl = i;
                ansr = j;
            }
            else if(ans==t)
            {
                if(ansl+ansr < i+j)
                {
                    ansl = i;
                    ansr = j;
                }
                else if(ansl+ansr==i+j)
                {
                    if(ansl<i)
                    {
                        ansl = i;
                        ansr = j;
                    }
                }
            }
        }
        //printf("%d\n",i);
    }*/
    printf("%d %d",ansl,ansr);

    //for(i=1;i<=d;i++)printf("mem[%d] = %d\n",i,mem[i]);
}
/*
900000
920000
940000
960000
*/
