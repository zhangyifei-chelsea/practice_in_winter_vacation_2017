//
// Created by liu on 17-2-1.
//

#include <dirent.h>
#include <iostream>
#include <string.h>
#include "../../lib/md5/md5.h"
#include <fstream>
using namespace std;
void rec(string dir,int depth=0);
int main()
{
    string root_dir;
    cout << "Please input the root dir:";
    getline(cin, root_dir);
    cout<<root_dir<<endl;
    rec(root_dir);
    return 0;
}
void rec(string dir,int depth)
{
    auto dir0 = opendir(dir.c_str());
    dirent *file;
    int j=0;
    while ((file = readdir(dir0)) != NULL)
    {
        switch (file->d_type)
        {
            case DT_REG: // Regular file
            {
                for(int i=0;i<depth;++i)
                    cout<<"    ";
                cout << "|-- "<<file->d_name<<"   ";
                ifstream input(dir+'/'+file->d_name);
                MD5 md5(input);
                cout<<md5.toString() <<endl;
                input.close();
                break;
            }
            case DT_DIR: // Directory
                if((strcmp(file->d_name,".")!=0)&&(strcmp(file->d_name,"..")!=0))
                {
                    for(int i=0;i<depth;++i)
                        cout<<"    ";
                    cout << "|-- "<<file->d_name<< endl;
                    rec(dir+'/'+file->d_name,++depth);
                }
                break;
        }
    }
    closedir(dir0);
    delete(file);
    return;
}