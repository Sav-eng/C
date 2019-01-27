#include<stdio.h>
#include<string.h>
main()
{
    int n,i,ans[120]={},j,k,bns[120]={},check=0;
    char a[30],b[30];
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
        int ans[120]={};
        int bns[120]={};
        scanf("%s",a);
        scanf("%s",b);
        if(strlen(a)==strlen(b))
        {
            for(j=0;j<strlen(a);j++)
            {
                ans[a[j]]++;
                bns[b[j]]++;
            }
            for(k=0;k<120;k++)
            {
                if(ans[k]==bns[k])check++;
                printf("check = %d k = %d ans[k] = %d bns[k] = %d\n",check,k,ans[k],bns[k]);
            }
            if(check==120)printf("Yes\n");
            else printf("No\n");
        }
        else printf("No\n");
        check = 0;
   }
   for(i=0;i<n;i++)
   {

   }
}
