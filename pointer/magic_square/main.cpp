#include <iostream>
#include <cstdlib>
#include <math.h>
void square(int **a,int s,int start,int l,int c);
int main()
{
    int num,m,n;
    std::cout<<"Input an integer:";
    std::cin>>num;
    int **a=(int**)calloc(num,sizeof(int*));
    for(int m=0;m<num;++m)
    {
        a[m]=(int*)calloc(num,sizeof(int));
    }
    if(num%2==1)
    {
        m = 0;
        n = num / 2;
        a[m][n] = 1;
        for (int i = 2; i <= num * num; ++i)
        {
            m = (m + num - 1) % num;
            n = (n + 1) % num;
            if (a[m][n] == 0)
                a[m][n] = i;
            else
            {
                m = (m + 2) % num;
                n = (n + num - 1) % num;
                a[m][n] = i;
            }
        }
    }
    else if(num%4==0)
    {
        for(m=0;m<num;++m)
        {
            for(n=0;n<num;++n)
            {
                int i=m*num+n+1;
                if((m%4==n%4)||(m%4+n%4==3))
                    a[m][n]=num*num+1-i;
                else
                    a[m][n]=i;
            }
        }

    }
    else
    {
        int s,k;
        s=num/2;
        square(a,s,1,0,0);
        square(a,s,s*s+1,s,s);
        square(a,s,2*s*s+1,0,s);
        square(a,s,3*s*s+1,s,0);
        k=(num-2)/4;
        for(m=0;m<s;++m)
        {
            if(m%s!=s/2)
            {
                for(n=0;n<k;++n)
                {
                    int c;
                    c=a[m][n];
                    a[m][n]=a[m+s][n];
                    a[m+s][n]=c;
                }
            }
            else
            {
                for(n=k;n<2*k;++n)
                {
                    int c;
                    c=a[m][n];
                    a[m][n]=a[m+s][n];
                    a[m+s][n]=c;
                }
            }
        }
        for(m=0;m<s;++m)
        {
            if(k-1>0)
            {
                for(n=2*k+3;n<=3*k+1;++n)
                {
                    int c;
                    c=a[m][n];
                    a[m][n]=a[m+s][n];
                    a[m+s][n]=c;
                }
            }
        }
    }
    for(m=0;m<num;++m)
    {
        for(n=0;n<num;++n)
        {
            int w;
            w=log10(num*num)+3;
            std::cout.width(w);
            std::cout<<a[m][n];
        }
        std::cout<<std::endl;
    }
    for(m=0;m<num;++m)
    {
        free(a[m]);
    }
    free(a);
    return 0;
}
void square(int **a,int s,int start,int l,int c)
{
    int m,n;
    m = 0+l;
    n = s / 2+c;
    a[m][n] = start;
    for (int i = 1+start; i <= s*s+start-1; ++i)
    {
        m = (m + s - 1) % s+l;
        n = (n + 1) % s+c;
        if (a[m][n] == 0)
            a[m][n] = i;
        else
        {
            m = (m + 2) % s+l;
            n = (n + s - 1) % s+c;
            a[m][n] = i;
        }
    }
}