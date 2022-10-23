#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    string array[t];
    for(int i =0 ; i < t ; i++){
          cin>>array[i];
    }
    for(int i= 0 ; i < t ; i++){
    if(array[i].length() >10 ){
     cout<<array[i][0]<<array[i].length()-2<<array[i][array[i].length()-1]<<endl;
    }
    else{
        cout<<array[i];
    }
    return 0;
}