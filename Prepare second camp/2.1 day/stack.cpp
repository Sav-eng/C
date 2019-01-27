#include<stdio.h>
#include<stack>
#include<string.h>

using namespace std;
stack<char>x;
main()
{
    char a[100];
    int i;
    gets(a);
    for(i=0;i<strlen(a);i++)
    {
        if(a[i] == '}')
        {
            if(x.top()== '{')
            {
                x.pop();
            }
            else
            {
                printf("No");
                return 0;
            }
        }
        else if(a[i] == ']')
        {
            if(x.top()== '[')
            {
                x.pop();
            }
            else
            {
                printf("No");
                return 0;
            }
        }
        else if(a[i] == ')')
        {
            if(x.top()== '(')
            {
                x.pop();
            }
            else
            {
                printf("No");
                return 0;
            }
        }
        else x.push(a[i]);
    }
    if(x.empty())
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
}
