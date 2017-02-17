#include <iostream>
#include "BigNumber.h"

using namespace std;

int main()
{
    // Test your class here
    BigNumber a("123456789");
    BigNumber b("999");
    auto c=a/b;
    auto d=a%b;
    //cout<<c.toString()<<std::endl;
    //cout<<d.toString()<<std::endl;
    return 0;
}