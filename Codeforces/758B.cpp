#include<stdio.h>
#include<map>
#include<string.h>
using namespace std;
map<char,int>ans,mem;
char a[1005];
main()
{
    int i;
    scanf("%s",a);
    for(i=0;i<strlen(a);i++)
    {
        if(a[i]!='!')
        {
            mem[i%4]=a[i];
            //printf("mem[%d] = %c\n",i%4,mem[i%4]);
        }
    }
    for(i=0;i<strlen(a);i++)
    {
        if(a[i]=='!')
        {
            ans[mem[i%4]]++;
        }
    }
    printf("%d %d %d %d",ans['R'],ans['B'],ans['Y'],ans['G']);
}
