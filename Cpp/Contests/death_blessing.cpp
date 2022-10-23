#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    int n;
    for(int i =0; i< t ; i++){
        cin>>n;
        long long arr[n];
        long long b[n];
        for(int k =0 ; k < n ; k++){
            cin>>arr[k];
            cin>>b[k];
        }
        long long sum1 =0;
        long long sum2 =0;
        for(int j=0;j<n;j++)
        {
            sum1= sum1 + arr[j];
           
        }
        for(int o=0;o<n;o++)
        {
            sum2 = sum2 + arr[o];
           
        }

    long long max = b[0];

    for (int l = 1; l < n; l++){
        if (b[l] > max){
            max = arr[l];
         }
    }

        long long  sum;
        sum = sum1 + (sum2 -max);
        cout<<sum;
    }
    return 0;
}