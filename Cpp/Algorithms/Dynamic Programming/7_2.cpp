#include <iostream>
using namespace std;

//Creating a function using dynamic programming approach

//height - h
//left  - l
//right - r

int Rain_Water(int h[],int n){
    if(n<=2){
        return 0;
    }
    int l[n];                                
    int r[n];
    l[0]=h[0];
    for(int i=0;i<n;i++){
        l[i]=max(l[i-1],h[i]);
    }
    r[n-1]=h[n-1];
    for(int i=n-2;i>=0;i--){
        r[i]=max(r[i+1],h[i]);
    }
    int Trapped_Water=0;
    for(int i=0;i<n;i++){
        Trapped_Water=Trapped_Water+min(l[i],r[i])-h[i];
    }
    return Trapped_Water;
}

int main()
{   
    int n;
    cin>>n;
    if(n>=1 && n<=20000){
    int h[n];
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    int Trapped_Water=Rain_Water(h,n);
    cout<<Trapped_Water;
}
}