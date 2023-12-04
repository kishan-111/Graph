//count the number of strongly connected components
//step 1: make a stack by dfs traversal on each vertex
//step 2: reverse each edges
//step 3: dfs on from element present on top to bottom in stack

#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<int> &vis,vector<int> adj[],stack<int> &st){
    vis[node]=1;
    for(auto x: adj[node]){
        if(!vis[x]){
            dfs(x,vis,adj,st);
        }
    }
    st.push(node);
}
void dfss(int node,vector<int> &vis,vector<int> adj[]){
    vis[node]=1;
    for(auto x: adj[node]){
        if(!vis[x]){
            dfss(x,vis,adj);
        }
    }
}
int main(){
    int V,E;
    cin>>V>>E;
    vector<int> adj[V];
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    //kosarju algo
    vector<int> vis(V,0);
    stack<int> st;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            dfs(i,vis,adj,st);
        }
    }
    vector<int> adjT[V];
    for(int i=0;i<V;i++){
        vis[i]=0;
        for(auto x: adj[i]){
            adjT[x].push_back(i);
        }
    }

    int ans=0;
    while(!st.empty()){
        int node=st.top();
        st.pop();
        if(!vis[node]){
            ans++;
            dfss(node,vis,adjT);
        }
    }
    
    cout<<ans<<endl;
}