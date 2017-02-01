//
// Created by liu on 17-2-1.
//

#include <dirent.h>
#include <iostream>

using namespace std;

int main()
{
    string root_dir;
    cout << "Please input the root dir: ";
    getline(cin, root_dir);

    auto dir = opendir(root_dir.c_str());
    dirent *file;
    while ((file = readdir(dir)) != NULL)
    {
        switch (file->d_type)
        {
        case DT_REG: // Regular file
            cout << file->d_name <<endl;
            break;
        case DT_DIR: // Directory
            cout << file->d_name <<endl;
            break;
        }
    }
    closedir(dir);
}