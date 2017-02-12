#include <iostream>
#include "BigNumber.h"

using namespace std;

int main()
{
    // Test your class here
    BigNumber a("-9999");
    BigNumber b("9857");
    auto c=a + b;
    cout<<a.toString()<<"+"<<b.toString()<<"="<<c.toString()<<endl;
    return 0;
}