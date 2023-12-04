#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

//acyclic - true
//cyclic - even -true
//cyclic -odd - false
bool check_compo(vector<int> adj[],int src,vector<int> &visited){
    queue<int> q;
    q.push(src);
    
}
bool is_bipartite(vector<int> adj[],int V){
    vector<int> visited(V,0);
    for(int i=0;i<V;i++){
        if(visited[i]==false){
            if(check_compo(adj,i,visited)==false){
               return false;
            }
        }
    }
    return true;
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
   
   cout<<is_bipartite(adj,V)<<endl;

}