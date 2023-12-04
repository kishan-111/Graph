/*
1.) prepare a degree vector
2.) push vector with degree 0 in queue
3.) whenever a vertice is found as neighbour decrease its degree by 1
4.) return vector of ans
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> findOrder(vector<int> adj[],int n){
    vector<int> degree(n);
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        for(int x: adj[i]){
            degree[x]++;
        }
    }
    
    for(int i=0;i<n;i++){
        cout<<degree[i]<<" ";
    }
    cout<<endl;
    queue<int> q;
    for(int i=0;i<n;i++){
        if(degree[i]==0){
            q.push(i);
        }
    }
    int idx=0;
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        ans[idx++]=temp;
        for(int x: adj[temp]){
           degree[x]--;
           if(degree[x]==0){
            q.push(x);
           }
        }
    }
    if(idx==n){
        return ans;
    }
    return {-1};
}
int main(){
    int V,E;
    cin>>V>>E;

    vector<int> adj[V];
    for(int i=0;i<E;i++){
       int u,v;
       cin>>u>>v;
       adj[v].push_back(u);
    }
    vector<int> ans=findOrder(adj,V);
   
   for(int i=0;i<V;i++){
    cout<<ans[i]<<" ";
   }
   cout<<endl;
    return 0;
}