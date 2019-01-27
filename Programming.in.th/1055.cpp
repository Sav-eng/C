#include<stdio.h>
struct node
{
    int val;
    node* next;
};
node *head = NULL;
node *t;
node *last;
node *now;
main()
{
    int i,j,n,k,a[1000],x[1000],h[1000]={};
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&x[i]);
    }
    for(i=0;i<n;i++)
    {
        if(head==NULL)
        {
            head = new node;
            head->val = i;
            head->next = head;
            last = head;
        }
        else
        {
            t = new node;
            t->val = i;
            t->next = head;
            last->next = t;
            last = t;
        }
    }
    now = head;
    for(i=0;i<n;i++)
    {
        for(j=0;j<x[i];j++)
        {
            last = now;
            now = now->next;
        }
        //printf("%d ",now->val);
        h[i%k]+=a[(now->val)];
        last->next = now->next;
        now = now->next;
    }
   // printf("\n");
    for(i=0;i<k;i++)
    {
        printf("%d\n",h[i]);
    }
}

/*
5 3
3
5
2
4
1
3
5
1
2
1
*/
