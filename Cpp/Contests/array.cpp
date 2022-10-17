#include<iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
    int n;
    cin>>n;
    int query;
    cin>>query;
    long long array[n];
    for(int i=0;i<n;i++)
    {
        cin>>array[i];
    }
    for(int i=0;i<query;i++)
    {
    int typej;
    cin>>typej;
    int xj;
    cin>>xj;
    long long sum=0;
    if(typej<0 || typej>1)
    {
        return 0;
    }
    
    if(typej==0)
    {
        for(int i=0;i<n;i++)
        {
            if(array[i]%2==0)
            {
                array[i]=array[i]+xj;
            }
        }
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            if(array[i]%2!=0)
            {
                array[i]=array[i]+xj;
            }
        }
    }
    
    for(int i=0;i<n;i++)
    {
        sum=sum+array[i];
    }
    
    cout<<sum<<endl;
    }
    }
    return 0;
}