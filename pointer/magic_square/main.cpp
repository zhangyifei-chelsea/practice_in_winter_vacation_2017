#include <iostream>
#include <cstdlib>
#include <cmath>
int main()
{
    int num,j;
    std::cout<<"Input an odd number:";
    std::cin>>num;
    int *p=(int*)calloc(num*num,sizeof(int));
    j=num/2;
    p[j]=1;
    for (int i=2;i<=num*num;++i)
    {
        if((j>=num)&&(j%num!=num-1))
        {
            j=j-num+1;
            if(p[j]==0)
                p[j]=i;
            else
            {
                j=j+num-1;
                while(p[j]!=0)
                {
                    j=j+num;
                    if(j>=num*num)
                        j=j%num;
                }
                p[j]=i;
            }
        }
        else
        {
            if(j<num-1)
            {
                j=j+num*(num-1)+1;
                if(p[j]==0)
                    p[j]=i;
                else
                {
                    j=j+num-1;
                    while(p[j]!=0)
                    {
                        j=j+num;
                        if(j>=num*num)
                            j=j%num;
                    }
                    p[j]=i;
                }
            }
            else if((j>=num)||(j%num==num-1))
            {
                j=j-2*num+1;
                if(p[j]==0)
                    p[j]=i;
                else
                {
                    j=j+num-1;
                    while(p[j]!=0)
                    {
                        j=j+num;
                        if(j>=num*num)
                            j=j%num;
                    }
                    p[j]=i;
                }
            }
            else
            {
                j=num*(num-1);
                if(p[j]==0)
                    p[j]=i;
                else
                {
                    j=j+num-1;
                    while(p[j]!=0)
                    {
                        j=j+num;
                        if(j>=num*num)
                            j=j%num;
                    }
                    p[j]=i;
                }
            }

        }
    }
    for(int k=0;k<num;++k)
    {
        for(int l=0;l<num;++l)
        {
            int n,w;
            n=k*num+l;
            w=log10(num*num)+3;
            std::cout.width(w);
            std::cout<<p[n];
        }
        std::cout<<std::endl;
    }
    free(p);
    return 0;
}