#include "binary_search.h"
main()
{
    int r=  get_n();
    int l =0;
    int check = 0;
    while(l<=r && check<=50)
    {
        int mid = (l+r)/2;
        if(is_less(mid))l = mid+1;
        else r = mid-1;
        check++;
    }
    int i;
    for(i=l;i<=r;i++)
    {
        if(is_equal(i))answer(i);
    }
    /*get_n();
    is_less(2);
    is_equal(2);
    answer(7);*/
}
