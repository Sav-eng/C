#include<stdio.h>
main()
{
    FILE *fp=fopen("Cut_Paper_input.txt","r");
    FILE *ffp=fopen("Cut_Paper_output.txt","w");
    int n,i,a,b;
    fscanf(fp,"%d",&n);
    for(i=0;i<n;i++)
    {
        fscanf(fp,"%d %d",&a,&b);
        while(a!=b)
        {
            if(a>b)a/=2;
            else b/=2;
        }
        fprintf(ffp,"%d\n",a);
    }
}
