#include"bits/stdc++.h"
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    int maxSum =INT_MIN;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }for(int i=0;i<n;i++){
        for(int j=1;j<n;j++){
            int sum=0;
           for(int k=i;k<=j;k++){
           sum+=a[k];
           } cout<<endl;
        maxSum=max(maxSum,sum);
        }
    }
    cout<<maxSum<<endl;
    return 0;
}