//
// Created by liu on 17-2-1.
//

#include <dirent.h>
#include <iostream>
#include <string.h>
using namespace std;
void rec(string dir,int depth);
int main()
{
    int depth=1;
    string root_dir;
    cout << "Please input the root dir:";
    getline(cin, root_dir);
    cout<<root_dir<<endl;
    rec(root_dir,depth);
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
                for(int i=0;i<depth;++i)
                    cout<<"    ";
                cout << "|-- "<<file->d_name <<endl;
                break;
            case DT_DIR: // Directory
                for(int i=0;i<depth;++i)
                    cout<<"    ";
                cout << "|-- "<<file->d_name<< endl;
                while((strcmp(file->d_name,".")!=0)&&(strcmp(file->d_name,"..")!=0))
                {
                    dir=dir+'/'+file->d_name;
                    ++depth;
                    rec(dir,depth);
                }
                break;
        }
    }
    closedir(dir0);
    delete(file);
    return;
}