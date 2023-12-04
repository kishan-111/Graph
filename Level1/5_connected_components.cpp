#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void compo(vector<int> adj[],int src,vector<bool> &visited,vector<int> &edge){
    visited[src]=true;
    edge.push_back(src);
    for(auto node: adj[src]){
                if(visited[node]==false){
                    compo(adj,node,visited,edge);
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
   vector<bool> visited(V,false);
   int count=0;
   vector<vector<int> > ans;
   for(int i=0;i<V;i++){
    if(visited[i]==false){
      count++;
      vector<int> temp;
      compo(adj,i,visited,temp);
      ans.push_back(temp);
    }
   }
   for(int i=0;i<count;i++){
    for(int j=0;j<ans[i].size();j++){
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;
   }
}