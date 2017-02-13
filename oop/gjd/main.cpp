#include <iostream>
#include "BigNumber.h"

using namespace std;

int main()
{
    // Test your class here
    BigNumber a("10");
    BigNumber b("11");
    auto c=a * b;
    cout<<c.toString();
    return 0;
}