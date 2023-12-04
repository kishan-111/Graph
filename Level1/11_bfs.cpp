#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void bfs(vector<int> adj[],int src,int V){
   vector<int> visited(V,0);
   queue<int> q;
   q.push(src);
   visited[src]=1;
   while(!q.empty()){
      int temp=q.front();
      q.pop();
      if(visited[temp]){
        continue;
      }
      visited[temp]=1;
      cout<<temp<<" ";
      for(auto node: adj[temp]){
        if(!visited[node]){
            q.push(node);
        }
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
        addEdge(adj,u,v);
    }
    
    bfs(adj,0,V);
}