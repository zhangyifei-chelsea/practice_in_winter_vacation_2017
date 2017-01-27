//
// Created by zyf on 2017/1/26.
#include <iostream>
void palindrome(int b)
{
    int i,k;
    int a[10];
    bool flag;
    i=0;
    flag=false;
    k=b;
    if(b==0)
        std::cout<<b<<" is palindrome.\n";
    else
    {
        for (int digit = 1; b / digit > 0; digit *= 10)
        {
            a[i] = k % 10;
            k = k / 10;
            ++i;
        }
        for (int j = 0; j <= (i - 1) / 2; ++j)
        {
            if (a[j] != a[i - 1 - j])
                flag = true;
        }
        if (!flag)
            std::cout << b << " is palindrome.\n";
        else
            std::cout << b << " is NOT palindrome.\n";
    }
}

