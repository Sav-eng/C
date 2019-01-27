#include <stdio.h>
#include <algorithm>

unsigned int as[100000],temp[100001];
int ac[100000];

int n;

int issort()
{
    int i;
    for(i=0;i<n-1;i++) if(temp[i]>temp[i+1]) break;
    if(i==n-1) return 1; else return 0;
}

int bsi()
{
    unsigned int l=0,u=2147483648,mid;
    int i;
    while(l<u)
    {
        mid=(l+u)/2;
        for(i=0;i<n;i++)
        {
            if(as[i]>mid) temp[i+1]=as[i]; else temp[i+1]=temp[i];
        }
        if(issort()) u=mid; else l=mid+1;
    }
    return l;
}

int bsw()
{
    unsigned int l=0,u=2147483648,mid;
    int i;
    while(l<u-1)
    {
        mid=(l+u)/2;
        for(i=0;i<n;i++)
        {
            if(as[i]>mid||ac[i]) temp[i+1]=as[i]; else temp[i+1]=temp[i];
        }
        if(issort()) u=mid; else l=mid+1;
    }
    return l;
}

int main()
{
    scanf("%d",&n);
    int i;
    int lac=0,cat=1;
    for(i=0;i<n;i++)
    {
        scanf("%u%d",&as[i],&ac[i]);
        if(ac[i]) if(lac>as[i]) cat=0; else lac=as[i];
    }
    printf("%d ",cat);
    if(!cat)//iron
    {
        printf("%u\n",bsi());
    }
    else//wood
    {
        printf("%u\n",bsw());
    }
}
