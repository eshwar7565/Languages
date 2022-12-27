#include<bits/stdc++.h>
using namespace std;
int main(){
    int v,e;
    cout<<"Enter the number of vertices:"<<endl;
    cin>>v;
    cout<<"Enter the number of edges:"<<endl;
    cin>>e;
    int arr[e][3];
  cout<<"Enter each edge along with the time required to burn it"<<endl;
    for(int i=0;i<e;i++){
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
        }
    }
    return 0;

}