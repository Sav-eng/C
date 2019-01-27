#include<stdio.h>
#include<algorithm>
using namespace std;
struct node
{
    int val;
    node *left;
    node *right;
};
node *t;
node *now;
node *root=NULL;
void inorder(node *t)
{
    if(t!=NULL)
    {
        inorder(t->left);
        printf("%d ",t->val);
        inorder(t->right);
    }
}
main()
{
    int n,i;
    int a[100000];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        if(root==NULL)
        {
            root = new node;
            root->val = a[i];
            root->left = NULL;
            root->right = NULL;
            //now = head;
        }
        else
        {
            //now =head;
            now = root;
            while(1)
            {
                //printf("a");
                if(a[i]>=now->val)
                {
                    if(now->right==NULL)
                    {
                        t = new node;
                        t->val = a[i];
                        t->right = NULL;
                        t->left = NULL;
                        now->right = t;
                        break;
                    }
                    else
                    {
                        now = now->right;
                    }
                }
                else if(a[i]<now->val)
                {
                    if(now->left==NULL)
                    {
                        t = new node;
                        t->val = a[i];
                        t->right = NULL;
                        t->left = NULL;
                        now->left = t;
                        break;
                    }
                    else
                    {
                        now = now->left;
                    }
                }
            }
        }
    }
    inorder(root);

}
