#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool if_cyclic(vector<int> adj[],int src,vector<bool> &visited){
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        if(visited[temp]==true){
            return true;
        }else{
            visited[temp]=true;
        }
        for(auto node: adj[temp]){
          if(visited[node]==false){
            q.push(node);
          }
        }
    }
    return false;
}
bool is_cyclic(vector<int> adj[],int V){
    vector<bool> visited(V,false);
    for(int i=0;i<V;i++){
        if(visited[i]==false and if_cyclic(adj,i,visited)){
            return true;
        }
    }
    return false;
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

    cout<<is_cyclic(adj,V)<<endl;
}