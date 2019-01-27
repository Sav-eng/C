#include<bits/stdc++.h>
using namespace std;
string s,s2[6];
main()
{
    int time,i,j,check,o,t,sum;
    scanf("%d",&time);
    getline(cin,s);
    while(time--)
    {
        s.clear();
        for(i=0;i<5;i++)s2[i].clear();
        getline(cin,s);
        //cout << s;
        j=0;
        check=0;
        for(i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                for(o=j;o<i;o++)s2[check] += s[o];
                check++;
                j=i+1;
            }
        }
        for(o=j;o<i;o++)s2[check] += s[o];
        sum=0;
        check=0;
        for(i=0;i<5;i++)
        {
            if(s2[i] != "J" && s2[i] != "K" && s2[i] != "Q" && s2[i] != "A")
            {
                if(s2[i] =="10")t = 10;
                else t = s2[i][0]-'0';
                //printf("%d ",t);
            }
            else if(s2[i]=="A")t = 1;
            else t = 10;
            sum += t;
            if(sum>=16 && sum<= 21)
            {
                printf("%d\n",sum);
                check = 1;
                break;
            }
            else if(sum>21)
            {
                printf("busted\n");
                check = 1;
                break;
            }
        }
        if(!check)printf("%d\n",sum);
    }
}
/*
7
A 10 8 2 7
4 5 3 J Q
6 2 A 3 4
A A A A A
Q Q Q Q Q
A 9 8 2 7
10 10 1 2 2


*/
