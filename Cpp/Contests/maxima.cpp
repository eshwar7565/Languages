#include<iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    if(t<1 || t>1000)
    {
        return 0;
    }
    for(int i=0;i<t;i++)
    {
    int n,k;
    cin>>n>>k;
    if(k<2 || k>50 || n<2 || n>50)
    {
        return 0;
    }
    int a[n];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]==0 || a[i]==1){
        continue;
        }
    }
    
    for(int i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            sum++;
        }
    }
    
    if(sum==n)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
    }
    }
    return 0;
}