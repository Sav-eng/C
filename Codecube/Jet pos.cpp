#include<bits/stdc++.h>
using namespace std;
int b[100005];
int l[100005];
int r[100005];
int stll,stl,enl,maxsuml,_maxl,suml;
int strr,str,enr,maxsumr,_maxr,sumr;
bool check;
main()
{
    char a;
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf(" %c%d",&a,&b[i]);
        if(a=='L')
        {
            l[i] = b[i];
            r[i] = -b[i];
        }
        else
        {
            l[i] = -b[i];
            r[i] = b[i];
        }
        if(a=='L')check=1;
    }
    //for(i=0;i<n;i++)printf("%d ",r[i]);
    for(i=0;i<n;i++)
    {
        //maxsum
        maxsuml += l[i];
        if(maxsuml<0)
        {
            maxsuml = 0;
            stl = i+1;
        }
        if(_maxl<maxsuml)
        {
            _maxl = maxsuml;
            stll = stl;
            enl = i;
        }
        ////////////////////////////////////////////////////////
        maxsumr += r[i];
        if(maxsumr<0)
        {
            maxsumr = 0;
            str = i+1;
        }
        if(_maxr<maxsumr)
        {
            _maxr = maxsumr;
            strr= str;
            enr = i;
        }
        //printf("%d %d\n",maxsumr,_maxr);
        ///////////////////////////////////////////////////////
        //sum
        if(l[i]>0)suml+=l[i];
        if(r[i]>0)sumr+=r[i];
    }
    //printf("suml =%d sumr = %d\n",suml,sumr);
    if(suml+_maxr>sumr+_maxl)
    {
        printf("L %d %d %d\n",suml+_maxr,strr+1,enr+1);
    }
    else if(sumr+_maxl>suml+_maxr)
    {
        printf("R %d %d %d\n",sumr+_maxl,stll+1,enl+1);
    }
    else
    {
        if(!check)printf("L %d %d %d\n",sumr+_maxl,strr+1,enr+1);
        else printf("R %d %d %d\n",sumr+_maxl,stll+1,enl+1);
    }
    //printf("maxsuml = %d-->%d->%d \nmaxsumr = %d-->%d->%d\nsuml = %d sumr = %d",_maxl,stll+1,enl+1,_maxr,strr+1,enr+1,suml,sumr);
}

/*

4
L 9
R 8
L 9
R 10

5
L 1
R 2
L 1
R 2
L 1

2
R 3
R 3

2
L 3
R 3

*/
