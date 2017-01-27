//
// Created by zyf on 2017/1/27.
#include <iostream>
#include <cmath>
void power(int c)
{
    int m,n;
    bool flag;
    flag=0;
    if((c==0)||(c==1))
    {
        std::cout<<c<< " is a power number.\n";
        flag=1;
    }
    else
    {
        for (m = 2; m <= sqrt(c); ++m)
        {
            for (n = 2; pow(m, n) < c + 1; ++n)
            {
                if (c == pow(m, n))
                {
                    std::cout << c << " is a power number.\n";
                    flag = 1;
                    break;
                }
            }
        }
    }
    if(flag==0)
        std::cout<<c<<" is NOT a power number.\n";
}

