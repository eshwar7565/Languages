#include<iostream>
 
using namespace std;
 
int main()
{
    int test;
    cin>>test;
    if(test<1 || test>48)
    {
        return 0;
    }
    while(test--)
    {
    int n;
    cin>>n;
    int array[n];
    for(int i=1;i<=n;i++)
    {
        array[i]=i;
    }
    
    int t1=array[2];
    array[2]=array[n];
    array[n]=t1;
    
    for(int i=1;i<=n;i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
    }
    return 0;
}