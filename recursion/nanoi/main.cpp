#include <iostream>
void Hanoi(int n,char start,char finish,char intermediate);
int main()
{
    int a;
    std::cout << "Enter an integer:";
    std::cin>>a;
    Hanoi(a,'A','B','C');
    return 0;
}
void Hanoi(int n,char start,char finish,char intermediate)
{
    if(n==1)
        std::cout<<start<<"-->"<<finish<<"\n";
    else
    {
        Hanoi(n-1,start,intermediate,finish);
        std::cout<<start<<"-->"<<finish<<"\n";
        Hanoi(n-1,intermediate,finish,start);
    }
}

