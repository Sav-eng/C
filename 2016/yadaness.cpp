#include<stdio.h>
#include<map>
#include<iostream>
#include<string>
using namespace std;
map<string,int>mp;
string txt[100000],txt2[100000];
int a[100000];
int n;
int t[100000];
int ans=0;
void mergesort(int l,int r)
{
    int mid = (l+r)/2;
    if(l==r)return ;
    mergesort(0,mid);
    mergesort(mid+1,r);
    int i=l,j=mid+1,cnt=l;
    while(i<=mid && j<=r)
    {
        if(a[i]<=a[j])t[cnt++] = a[i++];
        else
        {
            t[cnt++] = a[j++];
            ans += mid-i+1;
        }
    }
    while(j<=r)t[cnt++] = a[j++];
    while(i<=mid)t[cnt++] = a[i++];
    for(i=l;i<=r;i++)a[i] = t[i];
}
main()
{
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        cin >> txt[i];
    }
    for(i=0;i<n;i++)
    {
        cin >> txt2[i];
    }
    for(i=0;i<n;i++)
    {
        mp[txt2[i]]=i;
    }
    for(i=0;i<n;i++)
    {
        a[i] = mp[txt[i]];
    }
    //for(i=0;i<n;i++)printf("%d ",a[i]);
    //printf("a");
    mergesort(0,n-1);
    //for(i=0;i<n;i++)printf("%d",a[i]);
    printf("%d",ans);
}
