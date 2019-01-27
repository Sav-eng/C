#include<stdio.h>
#include<unordered_map>
#include<string.h>
using namespace std;
unordered_map<char,char>mem;
main()
{
    char a[2000];
    char b[2000];
    char ans1[2000],ans2[2000];
    int check=0;
    int i;
    scanf("%s",&a);
    scanf("%s",&b);
    for(i=0;i<strlen(a);i++)
    {
        if(a[i]!=b[i])
        {
            if(mem.find(a[i])==mem.end() && mem.find(b[i])==mem.end())
            {
                mem[a[i]]=b[i];
                mem[b[i]]=a[i];
                ans1[check] = a[i];
                ans2[check] = b[i];
                check++;
            }
            if(mem[a[i]]!=b[i] || mem[b[i]]!=a[i])
            {
                printf("-1");
                return 0;
            }
        }
    }
    printf("%d\n",check);
    for(i=0;i<check;i++)
    {
        printf("%c %c\n",ans1[i],ans2[i]);
    }
}
