#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    int n;
    int t1;
    
    int arr[n];
    cin>>t;
    for(int i =0 ;i < t ; i++){
        cin>>n;
        for(int i =0; i< n ; i++ ){
            arr[i] = i + 1 ;
        }
        t1 =  arr[1];
        arr[1]= arr[n];
        arr[n] = t1;
        for(int i =0 ; i <n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;



    }
    return 0;
}