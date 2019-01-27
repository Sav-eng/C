#include<stdio.h>
main()
{
    FILE *fp=fopen("Sum_of  Power_input.txt","r");
    FILE *ffp=fopen("Sum_of  Power_output.txt","w");
    int n,i,j,k,a,b;
    int x[100000];
    int check;
    fscanf(fp,"%d",&n);
    for(i=0;i<n;i++)
    {
        check = 0;
        fscanf(fp,"%d %d",&a,&b);
        for(j=0;j<a;j++)
        {
            fscanf(fp,"%d",&x[j]);
        }
        for(j=0;j<a-1;j++)
        {
            for(k=j+1;k<a;k++)
            {
                if(x[j]+x[k]==b)
                {
                    //printf("%d %d",x[j],x[k]);
                    check++;
                }
            }
        }
        fprintf(ffp,"%d\n",check);
    }
}
