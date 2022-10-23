#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    int n ;
    int arr[n];
    int count =0;
    string str;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n;
      for(int j=0;j<n;j++)
      {
        cin>>str[j];
      }

        for(int k=0;k<n;k++)
        {
            cin>>arr[k];
        }
                for(int l=0;i<n;i++)
                {
                    if( arr[i]> arr[i+1] && str[i] < str[i+1])
                    {
                      count = count + arr[i];
                    }
                }
                cout<<count;
    }
      
      return 0;
    
    
}