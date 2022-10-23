#include<bits/stdc++.h>
using namespace std;
int main(){
 int n;
 cin>>n;
 if(n<1 || n>100){
    return 0 ;
 }
    
    if(n%2==0 && n>2 ){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;

}