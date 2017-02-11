//
// Created by liu on 17-2-1.
//

#include <dirent.h>
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include "../../lib/md5/md5.h"

using namespace std;

void printPreffix(int depth)
{
    for (int i = 0; i < depth; i++)cout << "    ";
    cout << "|-- ";
}

void rec(string dir_name, int depth = 0)
{
    auto dir = opendir(dir_name.c_str());
    dirent *file;
    while ((file = readdir(dir)) != NULL)
    {

        switch (file->d_type)
        {
        case DT_REG: // Regular file
        {
            printPreffix(depth);
            cout << file->d_name << "\t";
            ifstream input(dir_name + "/" + file->d_name);
            MD5 md5(input);
            cout << md5.toString() << endl;
            break;
        }
        case DT_DIR: // Directory
            if (strcmp(file->d_name, ".") != 0 && strcmp(file->d_name, ".."))
            {
                printPreffix(depth);
                cout << file->d_name << endl;
                rec(dir_name + "/" + file->d_name, depth + 1);
            }
            break;
        }
    }
    delete file;
    closedir(dir);
}

int main()
{
    string root_dir;
    cout << "Please input the root dir: ";
    getline(cin, root_dir);
    cout << root_dir << endl;
    rec(root_dir);
}