#include<stdio.h>
#include<set>
#include<string>
#include<iostream>
using namespace std;
set<string>s;
int mp1;
string a;
string b;
main()
{
    int n,m,i,cnt,check,j;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        cin >> a;
        s.insert(a);
    }
    cnt =0;
    mp1=0;
    for(i=0;i<m;i++)
    {
        cin >> b;
        if(s.find(b)!=s.end())
        {
            mp1++;
        }
    }
    //printf("%d",mp1);
    i =0;j=0;
    cnt =0;check=1;
    while(i<n && j <m)
    {
        if(mp1>0)
        {
            i++;
            j++;
            mp1--;
        }
        else
        {
            if(check)i++;
            else j++;
        }
        if(i==n && j==m)
        {
            if(!check)printf("NO");
            else printf("YES");
            break;
        }
        else if(j==m)
        {
            printf("YES");
            break;
        }
        else if(i==n)
        {
            printf("NO");
            break;
        }
        check = !check;

    }
}

/*

1 1
a
a

*/
