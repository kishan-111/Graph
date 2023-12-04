#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void compo(vector<int> adj[],int src,vector<bool> &visited){
    visited[src]=true;
    for(auto node: adj[src]){
        if(visited[node]==false){
            compo(adj,node,visited);
        }
    }
    return;
}
int main(){
    int V,E;
    cin>>V>>E;
    vector<int> adj[V];
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        addEdge(adj,u,v);
    }
    int count=0;
    vector<bool> visited(V,false);
    for(int i=0;i<V;i++){
        if(visited[i]==false){
            count++;
            compo(adj,i,visited);
        }
    }
    if(count==1){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
    return 0;
}