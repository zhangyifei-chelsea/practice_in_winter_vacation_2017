#include <iostream>
#include <cstdlib>
void maxmin(int *a,int n,int *max,int *min);
int main()
{
    int n;
    int max,min;
    std::cout<<"Enter the number of integers you want to process:\n";
    std::cin>>n;
    int *a=(int*)calloc(n,sizeof(int));
    std::cout<<"Enter all the numbers:\n";
    for(int i=0;i<n;++i)
    {
        std::cin>>a[i];
    }
    maxmin(a,n,&max,&min);
    std::cout<<"max:"<<max<<"\nmin:"<<min;
    return 0;
}
void maxmin(int *a,int n,int *max,int *min)
{
    int max1,min1,max2,min2;
    switch(n)
    {
        case 1: *max=a[0];
            *min=a[0];
            return;
        case 2: if(a[0]>a[1])
            {
                *max=a[0];
                *min=a[1];
            }
            else
            {
                *max=a[1];
                *min=a[0];
            }
            return;
        default:maxmin(a,n/2,&max1,&min1);
            maxmin(a+n/2,n-n/2,&max2,&min2);
            *max=(max1>max2?max1:max2);
            *min=(min1<min2?min1:min2);
            return;
    }
}