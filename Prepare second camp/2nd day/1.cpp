#include<stdio.h>
#include<conio.h>
typedef struct node
{
        int val;
        node *next;
};
node *t;
node *head=NULL;
node *last;
main()
{
      int n,k,i;
      scanf("%d %d",&n,&k);
      node *now;
      for(i=0;i<n;i++)
      {
           if(head==NULL)
           {
                head = new node;
                head->val = i;
                head->next = head;             
           }
           else
           {
                //t = last;
                last = new node;
                last->val = i;
                last->next = head;
           }
      }
      while(now->next!=head)
      {
           for(i=0;i<k;i++)
           {
                now = now->next;     
           }
           last ->next = now ->next;
           now = now ->next;
      }
      printf("%d",now->val);
      getch();
}
