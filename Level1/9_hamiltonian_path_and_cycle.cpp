#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void paths(vector<int> adj[],int V,string psf,int src,unordered_set<int> &visited,int osrc){
    if(visited.size()==V-1){
        bool isCyclic=false;
        for(auto node: adj[src]){
            if(node==osrc){
                isCyclic=true;
                break;
            }
        }
        if(isCyclic){
            cout<<psf+"@"<<endl;
        }else{
            cout<<psf+"."<<endl;
        }
        return;
    }
   visited.insert(src);
   for(auto node: adj[src]){
     if(visited.find(node)==visited.end()){
        paths(adj,V,psf+to_string(node),node,visited,osrc);
     }
   }
   visited.erase(src);
}
void hamiltonian(vector<int> adj[],int V,int src){
   unordered_set<int> visited;
   paths(adj,V,to_string(src)+"",src,visited,src);
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

    for(int i=0;i<V;i++)
    hamiltonian(adj,V,i);
    return 0;
}