//
// Created by zyf on 2017/1/27.
#include <iostream>
#include <cmath>
void power(int c)
{
    bool flag;
    flag=false;
    if((c==0)||(c==1))
    {
        std::cout<<c<< " is a power number.\n";
        flag=true;
    }
    else
    {
        for (int m = 2; m <= sqrt(c); ++m)
        {
            for (int n = 2; pow(m, n) < c + 1; ++n)
            {
                if (c == pow(m, n))
                {
                    std::cout << c << " is a power number.\n";
                    return;
                }
            }
        }
    }
    if(!flag)
        std::cout<<c<<" is NOT a power number.\n";
}

