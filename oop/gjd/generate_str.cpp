//
// Created by liu on 17-2-14.
//

#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    ofstream out("unittest.h");
    out << "#pragma once" << endl;
    out << "#include <string>" << endl;
    out << "const std::string BIGNUMBER_STR[] = {" << endl;

    out << "};" << endl;
    out.close();
}