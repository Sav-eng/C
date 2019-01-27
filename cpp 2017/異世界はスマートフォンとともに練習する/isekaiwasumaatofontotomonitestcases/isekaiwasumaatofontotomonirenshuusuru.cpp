#include <stdio.h>
#include <fstream>
#include <iostream>
#include <algorithm>

unsigned int as[1000000],temp[1000001];
int ac[1000000];

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
    std::ifstream ifs;
    std::ofstream ofs;
    ifs.open("6.in",std::ifstream::in);
    ofs.open("6.out",std::ofstream::out);
    ifs>>n;
    //scanf("%d",&n);
    int i;
    int lac=0,cat=1;
    for(i=0;i<n;i++)
    {
        ifs>>as[i];
        ifs>>ac[i];
        //scanf("%u%d",&as[i],&ac[i]);
        if(ac[i]) if(lac>as[i]) cat=0; else lac=as[i];
    }
    ofs<<cat<<" ";
    if(!cat)//iron
    {
        ofs<<bsi()<<std::endl;
    }
    else//wood
    {
        ofs<<bsw()<<std::endl;
    }
}
