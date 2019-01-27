#include<stdio.h>
main()
{
    FILE *fp=fopen("Power_Convering_input.txt","r");
    FILE *ffp=fopen("Power_Convering_output.txt","w");
    int n,i,j,a,check;
    fscanf(fp,"%d",&n);
    for(i=0;i<n;i++)
    {
        check =0;
        fscanf(fp,"%d",&a);
        for(j=1;j<=a;j++)
        {
            if(a%j==0)check+=j;
        }
        fprintf(ffp,"%d\n",check);
    }
}
