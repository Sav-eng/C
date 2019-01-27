#include<stdio.h>
#include<string>
#include<queue>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;
map<string,int>check;
map<string,string>ans;
string x,t,temp2,finda;
int c[] = {1,-1,3,-3};
queue<string>q;
main()
{
    int temp,i,n,j;
    int next,now,chek=0;
    x = "12345678x";
    ans[x] = "";
    q.push(x);
    char a;
    while(!q.empty())
    {

        x = q.front();
        q.pop();
        for(i=0;i<9;i++)if(x[i]=='x')temp = i;
        for(i=0;i<4;i++)
        {
            if(temp==0)
            {
                if(i != 1 && i!= 3)
                {
                    t = x;
                    swap(t[temp],t[c[i]+temp]);
                    if(!check[t])
                    {
                        check[t] = 1;
                        q.push(t);
                        if(i==2)
                        {
                            //printf("a");
                            ans[t] = 'u' + ans[x];
                        }
                        else if(i==0)ans[t] = 'l' + ans[x];
                    }
                    swap(t[temp],t[c[i]+temp]);
                }
            }
            else if(temp==1)
            {
                if(i!= 3)
                {
                    t = x;
                    swap(t[temp],t[c[i]+temp]);
                    if(!check[t])
                    {
                        check[t] = 1;
                        q.push(t);
                        if(i==0)ans[t] = 'l' + ans[x];
                        else if(i==1)ans[t] = 'r' + ans[x];
                        else if(i==2)ans[t] = 'u' + ans[x];
                    }
                    swap(t[temp],t[c[i]+temp]);
                }
            }
            else if(temp==2)
            {
                if( i!= 0&&i!= 3)
                {
                    t = x;
                    swap(t[temp],t[c[i]+temp]);
                    if(!check[t])
                    {
                        check[t] = 1;
                        q.push(t);
                        if(i==1)ans[t] = 'r' + ans[x];
                        else if(i==2)ans[t] = 'u' + ans[x];
                    }
                    swap(t[temp],t[c[i]+temp]);
                }
            }
            else if(temp==3)
            {
                if( i!= 1)
                {
                    t = x;
                    swap(t[temp],t[c[i]+temp]);
                    if(!check[t])
                    {
                        check[t] = 1;
                        q.push(t);
                        if(i==0)ans[t] = 'l' +ans[x];
                        else if(i==2)ans[t] = 'u' + ans[x];
                        else if(i==3)ans[t] = 'd' + ans[x];
                    }
                    swap(t[temp],t[c[i]+temp]);
                }
            }
            else if(temp==4)
            {
                t = x;
                swap(t[temp],t[c[i]+temp]);
                if(!check[t])
                {
                    check[t] = 1;
                    q.push(t);
                    if(i==0)ans[t] = 'l' + ans[x];
                    else if(i==1)ans[t] = 'r' + ans[x];
                    else if(i==2)ans[t] = 'u' + ans[x];
                    else if(i==3)ans[t] = 'd' + ans[x];
                }
                swap(t[temp],t[c[i]+temp]);
            }
            else if(temp==5)
            {
                if(i!=0)
                {
                    t = x;
                    swap(t[temp],t[c[i]+temp]);
                    if(!check[t])
                    {
                        if(i==1)ans[t] = 'r' +ans[x];
                        else if(i==2)ans[t] = 'u' +ans[x];
                        else if(i==3)ans[t] = 'd' +ans[x];
                        check[t] = 1;
                        q.push(t);
                    }
                    swap(t[temp],t[c[i]+temp]);
                }
            }
            else if(temp==6)
            {
                if( i!= 1&&i!= 2)
                {

                    t = x;
                    swap(t[temp],t[c[i]+temp]);
                    if(!check[t])
                    {
                        if(i==0)ans[t] = 'l' + ans[x];
                        else if(i==3)ans[t] = 'd' + ans[x];
                        check[t] = 1;
                        q.push(t);
                    }
                    swap(t[temp],t[c[i]+temp]);
                }
            }
            else if(temp==7)
            {
                if( i!= 2)
                {

                    t = x;
                    swap(t[temp],t[c[i]+temp]);
                    if(!check[t])
                    {
                        if(i==0)ans[t] = 'l' + ans[x];
                        else if(i==1)ans[t] = 'r' +ans[x];
                        else if(i==3)ans[t] = 'd' +ans[x];
                        check[t] = 1;
                        q.push(t);
                    }
                    swap(t[temp],t[c[i]+temp]);
                }
            }
            else if(temp==8)
            {
                if( i!= 0&&i!= 2)
                {
                    t = x;
                    swap(t[temp],t[c[i]+temp]);
                    if(!check[t])
                    {
                        if(i==1)ans[t] = 'r' +ans[x];
                        else if(i==3)ans[t] = 'd' + ans[x];
                        check[t] = 1;
                        q.push(t);
                    }
                    swap(t[temp],t[c[i]+temp]);
                }
            }
        }
    }
    scanf("%d",&n);
    for(j=0;j<n;j++)
    {
        finda.clear();
        for(i=0;i<9;i++)
        {
            scanf(" %c",&a);
            finda += a;
        }
        if(ans.find(finda)==ans.end())printf("unsolvable\n");
        else cout << ans[finda] << endl;
        if(j!=n-1)printf("\n");
    }




}
