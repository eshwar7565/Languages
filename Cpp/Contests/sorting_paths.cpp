#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    int n;
    
    cin>>t;
    for(int i =0 ; i< t ; i++)
    {
        cin>>n;
        int arr[n];
        for(int j =0 ; j < n ; j++){
            cin>>arr[j];
        }
        int sum;
        for(int k =0 ; k < n-1 ; k++){
            for(int  l =1 ; l < n; l++){
                if(arr[k]==arr[l]){
                    sum++;
                }
             }
            }
        
        if(sum>3)
        {
           cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }

    }
    return 0;
}