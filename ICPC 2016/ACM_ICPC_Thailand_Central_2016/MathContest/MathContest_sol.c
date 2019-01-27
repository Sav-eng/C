#include<stdio.h>
#include<string.h>

int main() {
    int k;
    char num[100100];
    scanf("%d",&k);
    for(int i=0;i<k;i++) {
        scanf("%s",num);
        int sum=0;
		int len=strlen(num);
        for(int j=0;j<len;j++)
            sum+=num[j]-'0';
        if(sum%9==0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
