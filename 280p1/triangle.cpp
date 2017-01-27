//
// Created by zyf on 2017/1/26.
#include <iostream>
void triangle(int a)
{
    bool flag;
    flag=false;
    for(int i=0;i<=a;++i)
    {
        if(a==i*(i+1)/2)
        {
            std::cout<<a<<" is a triangle number.\n";
            flag=true;
        }
    }
    if (!flag)
        std::cout<<a<<" is NOT a triangle number.\n";
}
