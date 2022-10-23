#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,m,n;
    cin>>t;
    
    
    if(t<=1 || t>=2000){
        return 0;
    }
    for(int i=0;i<t;i++)
    {
    cin>>n;
    cin>>m;
    int arrx[m];
    int arry[m];
    for(int i=0;i<m;i++)
      {
        cin>>arrx[i];
        cin>>arry[i];
      }
    if(m>=n){
        cout<<"NO";
    }
    else{
        cout<<"YES";
     }

    }
    return 0;


}