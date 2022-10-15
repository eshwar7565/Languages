#include <bits/stdc++.h>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    vector<int>adj[n+1]; //vector<pair<int,int>>adj[n+1]; for weighted graph
    for(int i=0 ; i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back(v); // adj[u].push_back({v,wt}); 
        adj[v].push_back(u); //Omit this for undirected graph
        }
        return 0;
}