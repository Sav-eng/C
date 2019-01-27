#include<stdio.h>
#include<stack>
#include<string.h>
using namespace std;
struct node
{
    char x;
    int val;
};
char ss[1000001];
char text[1000001];
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
        scanf("%s",text);
        scanf("%s",ss);
        j=1;
        for(i=0;i<strlen(ss);i++)
        {
            while(j!=0 && ss[i]!=ss[j])
            {
                j = tab[j-1];
                //printf("%d ",j);
            }
            if(j==0)tab[i] = 0;
            else
            {
                tab[i] = ++j;
            }
        }
        j=0;
        for(i=0;i<strlen(text);i++)
        {
            while(ss[j]!=text[i] && j!=0)
            {
                j = tab[j-1];
            }
            if(j==0)
            {
                if(text[i]==ss[j])
                {
                    s.push({text[i],++j});
                }
                else s.push({text[i],0});
            }
            else
            {
                s.push({text[i],j+1});
                j++;
            }
            if(j==strlen(ss))
            {
                for(k=0;k<strlen(ss);k++)s.pop();
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
            for(i=strlen(ans);i>=0;i--)ans[i] = ' ';
        }
        memset(tab,0,sizeof(tab));
    }
}
/*
3
codecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecodecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecubecube
codecube
CasecaseSensitive191
case


*/
