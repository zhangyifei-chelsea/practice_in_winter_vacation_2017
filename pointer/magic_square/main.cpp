#include <iostream>
#include <cstdlib>
#include <math.h>
int main()
{
    int num,m,n;
    std::cout<<"Input an odd number:";
    std::cin>>num;
    int **a=(int**)calloc(num,sizeof(int*));
    for(int m=0;m<num;++m)
    {
        a[m]=(int*)calloc(num,sizeof(int));
    }
    m=0;
    n=num/2;
    a[m][n]=1;
    for(int i=2;i<=num*num;++i)
    {
        m=(m+num-1)%num;
        n=(n+1)%num;
        if(a[m][n]==0)
            a[m][n]=i;
        else
        {
            m=(m+2)%num;
            n=(n+num-1)%num;
            a[m][n]=i;
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