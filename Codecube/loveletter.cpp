#include<bits/stdc++.h>
using namespace std;
struct node
{
    char x;
    int val;
};
string ss,text;
char ans[1000001];
stack<node>s;
int tab[1000001];
node t;
main()
{
    int time,i,j,k;
    scanf("%d",&time);
    while(time--)
    {
        cin >> text;
        cin >> ss;
        j=1;
        for(i=0;i<ss.size();i++)
        {
            if(ss[i]==ss[j])
            {
                tab[i] = j+1;
                j++;
            }
            else
            {
                while(j!=0 && ss[i]!=ss[j])
                {
                    j = tab[j-1];
                    //printf("%d ",j);
                }
                if(j==0)tab[i] = 0;
                else
                {
                    tab[i] = j+1;
                    j++;
                }
            }
        }
        //for(i=0;i<ss.size();i++)printf("%d ",tab[i]);
        j=0;
        for(i=0;i<text.size();i++)
        {
            if(text[i]==ss[j])
            {
                s.push({text[i],j+1});
                j++;
            }
            else
            {
                while(ss[j]!=text[i] && j!=0)
                {
                    j = tab[j-1];
                }
                if(j==0)
                {
                    if(text[i]==ss[j])
                    {
                        s.push({text[i],j+1});
                        j++;
                    }
                    else s.push({text[i],0});
                }
                else
                {
                    s.push({text[i],j+1});
                    j++;
                }
            }
            if(j==ss.size())
            {
                for(k=0;k<ss.size();k++)s.pop();
                if(s.empty())j=0;
                else j = s.top().val;
            }
        }
        if(s.empty())
        {
            printf("No COI Secret Code\n");
        }
        else
        {
            i = s.size();
            while(!s.empty())
            {
                t = s.top(); s.pop();
                //printf("%c ",t.x);
                ans[--i] = t.x;
            }
            printf("%s\n",ans);
        }
        //memset(ans,' ',sizeof(ans));
    }
}
/*
1
a
acacabacacabacacac


*/
