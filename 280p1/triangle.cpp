//
// Created by zyf on 2017/1/26.
#include <iostream>
void triangle(int a)
{
    int i;
    bool flag;
    flag=1;
    for(i=0;i<=a;++i)
    {
        if(a==i*(i+1)/2)
        {
            std::cout<<a<<" is a triangle number.\n";
            flag=0;
        }
    }
    if (flag==1)
        std::cout<<a<<" is NOT a triangle number.\n";
}
