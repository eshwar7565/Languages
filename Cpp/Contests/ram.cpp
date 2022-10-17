#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  for(int i =0 ; i<t ;i++){
    int n;
    
    cin>>n;
    int arr[n];
    int count1=0,count2=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    string str;
    cin>>str;
    
    
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]==arr[j] && str[i]==str[j])
            {
                count1++;
            }
            if(arr[i]==arr[j])
            {
                count2++;
            }
        }
    }
    
    if(count1==count2)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    }
    return 0;
}

