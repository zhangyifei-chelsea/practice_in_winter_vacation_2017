#include <iostream>
#include <time.h>
#include "Cipher.h"

using namespace std;

int main()
{
    // Test your class here
    vector<int64_t> vec;
    srand(0);
    for (int i = 0; i < 10; i++)
    {
        int64_t a = rand(), b = rand();
        vec.push_back((a << 32) | b);
    }
    auto str = Cipher::base64_encode(vec);
    cout << str << endl;
    return 0;
}