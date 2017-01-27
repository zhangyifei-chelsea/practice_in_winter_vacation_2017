#include <iostream>
#include "triangle.h"
#include "palindrome.h"
#include "power.h"
#include "abundant.h"
int main()
{
    int n;
    std::cout<<"Enter an integer:";
    std::cin>>n;
    triangle(n);
    palindrome(n);
    power(n);
    abundant(n);
    return 0;
}