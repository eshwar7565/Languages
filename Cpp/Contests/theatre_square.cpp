#include<bits/stdc++.h>
using namespace std;
int main(){
    int n , m , a ;
    cin>>n>>m>>a;
    cout<<((m+a-1)/a)*((n+a-1)/a)<<endl;
    return 0;
}