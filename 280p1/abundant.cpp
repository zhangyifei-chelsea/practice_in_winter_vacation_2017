//
// Created by zyf on 2017/1/27.
#include <iostream>
void abundant(int d)
{
    int total=0;
    for(int factor=1;factor<d;++factor)
    {
        if(d%factor==0)
            total+=factor;
    }
    if(total>d)
        std::cout<<d<<" is an abundant number.\n";
    else
        std::cout<<d<<" is NOT an abundant number.\n";
}

