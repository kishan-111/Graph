#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void count_friend(vector<int> adj[],int src,vector<int> &visited,int &size){
    visited[src]=1;
    size++;
    for(auto node: adj[src]){
        if(visited[node]==false){
            count_friend(adj,node,visited,size);
        }
    }
    return;
}
int perfect_friend(vector<int> adj[],int V){
    vector<int> visited(V,0);
    vector<int> v;
    for(int i=0;i<V;i++){
        if(visited[i]==0){
            int size=0;
            count_friend(adj,i,visited,size);
            v.push_back(size);
        }
    }
    int count=0;
    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
            count+=v[i]*v[j];
        }
    }
    return count;
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

    cout<<perfect_friend(adj,V)<<endl;
}