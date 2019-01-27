int recur(int x,int p)
{
    int l;
    if(x>n)return 0;
    if (table3[x] == 0)
    {
        l = recur(x+1,p);
        if(a[x]>a[p])
        {
            l = max(l, 1 + recur(x+1,x));
        }
    }
    return l;
}