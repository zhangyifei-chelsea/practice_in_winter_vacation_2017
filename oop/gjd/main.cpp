#include <iostream>
#include "BigNumber.h"

using namespace std;

int main()
{
    // Test your class here
    BigNumber a("123456789");
    BigNumber b("99");
    auto c=a/b;
    cout<<c.toString();
    return 0;
}